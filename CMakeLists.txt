cmake_minimum_required(VERSION 3.20)
project(VulkanAnimation CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################################################################
# Rutas de Salida (Output Directories)
################################################################################
# Forzamos a que todos los ejecutables vayan a una carpeta "bin" predecible
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")

# Buscar dependencias vía vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Detectar automáticamente Vulkan SDK (incluyendo cabeceras, librerías y utilidades)
find_package(Vulkan REQUIRED)

# Encontrar fuentes y cabeceras
file(GLOB SOURCES "VulkanAnimation/*.cpp")
file(GLOB HEADERS "VulkanAnimation/*.h")

# Configuración de Shaders
set(SHADER_VERT "VulkanAnimation/shaders/shader.vert")
set(SHADER_FRAG "VulkanAnimation/shaders/shader.frag")

# Como el ejecutable estará en bin/, compilamos los shaders en bin/shaders/
set(SPV_VERT "${CMAKE_BINARY_DIR}/bin/shaders/vert.spv")
set(SPV_FRAG "${CMAKE_BINARY_DIR}/bin/shaders/frag.spv")

# Crear el directorio de salida de shaders en el directorio de compilación
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/shaders")

# Localizar el compilador de shaders (glslc) provisto por el Vulkan SDK
if(TARGET Vulkan::glslc)
    set(GLSLC_EXE Vulkan::glslc)
elseif(Vulkan_GLSLC_EXECUTABLE)
    set(GLSLC_EXE ${Vulkan_GLSLC_EXECUTABLE})
else()
    # Si glslc no está, intentamos con glslangValidator
    if(Vulkan_GLSLANG_VALIDATOR_EXECUTABLE)
        set(GLSLC_EXE ${Vulkan_GLSLANG_VALIDATOR_EXECUTABLE})
    else()
        message(FATAL_ERROR "No se ha encontrado el compilador de shaders (glslc o glslangValidator). Asegúrate de tener el Vulkan SDK instalado correctamente.")
    endif()
endif()

# Comandos personalizados para compilar los shaders
add_custom_command(
    OUTPUT ${SPV_VERT}
    COMMAND ${GLSLC_EXE} ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER_VERT} -o ${SPV_VERT}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER_VERT}
    COMMENT "Compilando Vertex Shader..."
)

add_custom_command(
    OUTPUT ${SPV_FRAG}
    COMMAND ${GLSLC_EXE} ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER_FRAG} -o ${SPV_FRAG}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER_FRAG}
    COMMENT "Compilando Fragment Shader..."
)

# Target para forzar la compilación de shaders
add_custom_target(CompileShaders DEPENDS ${SPV_VERT} ${SPV_FRAG})

# Crear el ejecutable
add_executable(VulkanAnimation ${SOURCES} ${HEADERS})

# Requerir que los shaders se compilen antes
add_dependencies(VulkanAnimation CompileShaders)

# Añadir el directorio binario de CMake a los include directories
target_include_directories(VulkanAnimation PRIVATE "${CMAKE_BINARY_DIR}/bin")

# Vincular las librerías
target_link_libraries(VulkanAnimation PRIVATE 
    glfw 
    glm::glm 
    Vulkan::Vulkan
)

# --- FUNCIÓN PARA EJECUTAR DESDE TERMINAL ---
# Esto permite hacer: cmake --build --preset win-debug --target run
add_custom_target(run
    COMMAND $<TARGET_FILE:VulkanAnimation>
    DEPENDS VulkanAnimation
    WORKING_DIRECTORY $<TARGET_FILE_DIR:VulkanAnimation>
    COMMENT "Lanzando el proyecto VulkanAnimation..."
)
