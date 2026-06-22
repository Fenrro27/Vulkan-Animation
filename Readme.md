# Vulkan Animation

Este proyecto es una aplicación gráfica en Vulkan que implementa animaciones de figuras articuladas.

## Configuración y Dependencias

El proyecto utiliza **vcpkg en Manifest Mode** para la gestión de dependencias (como `glfw3` y `glm`), y se basa en **CMake Presets** para simplificar la configuración y compilación multiplataforma.

### Requisitos Previos

Para poder compilar y ejecutar este proyecto, asegúrate de tener instalado lo siguiente:

1. **Vulkan SDK**: Es un requisito estricto tener instalado el [Vulkan SDK](https://vulkan.lunarg.com/). CMake se encargará de detectar automáticamente la versión instalada y utilizará sus herramientas (como `glslc` para compilar los shaders de manera automática).
2. **vcpkg (Moderno)**: Es necesario tener una versión de `vcpkg` posterior a **octubre de 2023** (ya que se utiliza la característica `builtin-baseline` requerida en el archivo de manifiesto).
3. **Variable de Entorno `VCPKG_ROOT`**: Debes tener configurada la variable de entorno `VCPKG_ROOT` apuntando a la ruta donde tienes instalado vcpkg. Si te da un error de que no se encuentra el toolchain, puedes configurarlo en PowerShell para la sesión actual ejecutando:
   ```powershell
   $env:VCPKG_ROOT = "C:\vcpkg"
   ```
   Alternativamente, puedes usar la integración directa de **Visual Studio 2022**.
4. **CMake 3.20 o superior**.

### Comandos de Compilación

Dado que usamos CMake Presets, compilar el proyecto es muy sencillo. Abre una terminal en la raíz del proyecto y ejecuta:

#### 1. Configurar el proyecto
```bash
cmake --preset win-debug
```
*(Nota: Si quieres compilar en modo release, puedes usar el preset `win-release`. También hay opciones para `ninja-debug` o `ninja-release`).*

#### 2. Compilar el proyecto
```bash
cmake --build --preset win-debug
```
Para compilar y ejecutar directamente desde la terminal, puedes usar el target especial `run` que hemos añadido:
```bash
cmake --build --preset win-debug --target run
```
*(Nota sobre los Shaders)*: Los shaders `.vert` y `.frag` ubicados en `VulkanAnimation/shaders/` se compilan automáticamente a `.spv` en la carpeta de salida `bin/shaders/` gracias al Vulkan SDK detectado. Esto permite que el ejecutable los encuentre de forma portable sin requerir archivos de recursos de Windows.

## Solución de Problemas Frecuentes

**Error:** `unexpected field 'license', did you mean 'supports'?`
- **Causa:** Este error ocurre si la versión de vcpkg que estás usando o la que viene empaquetada con tu entorno de desarrollo es demasiado antigua y no entiende las últimas características del formato `vcpkg.json`.
- **Solución:** Debes actualizar tu versión local de vcpkg. Abre una terminal en la ruta de tu `vcpkg`, ejecuta `git pull` y posteriormente `./bootstrap-vcpkg.bat` (o `./bootstrap-vcpkg.sh` en Linux/macOS). Si estás usando la versión integrada de Visual Studio, asegúrate de actualizar **Visual Studio a su última versión**.
