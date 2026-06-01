#include "CAScene.h"
#include "CATransform.h"
#include "CACylinder.h"
#include "CASphere.h"
#include "CAGround.h"
#include "CABalljoint.h"
#include <iostream>

//
// FUNCIÓN: CAScene::CAScene(CAVulkanState* vulkan)
//
// PROPÓSITO: Construye el objeto que representa la escena
//
CAScene::CAScene(CAVulkanState* vulkan)
{
	CALight light = {};
	light.Ldir = glm::normalize(glm::vec3(1.0f, -0.8f, -0.7f));
	light.La = glm::vec3(0.2f, 0.2f, 0.2f);
	light.Ld = glm::vec3(0.8f, 0.8f, 0.8f);
	light.Ls = glm::vec3(1.0f, 1.0f, 1.0f);

	CAMaterial groundMat = {};
	groundMat.Ka = glm::vec3(0.0f, 0.3f, 0.0f);
	groundMat.Kd = glm::vec3(0.0f, 0.3f, 0.0f);
	groundMat.Ks = glm::vec3(0.8f, 0.8f, 0.8f);
	groundMat.Shininess = 16.0f;

	//Codigo modificado
	ground = new CAGround(5.0f, 50.0f);
	ground->initialize(vulkan);
	ground->setLight(light);
	ground->setMaterial(groundMat);

	CAMaterial cubeMat = {};
	cubeMat.Ka = glm::vec3(0.0f, 0.0f, 0.8f);
	cubeMat.Kd = glm::vec3(0.0f, 0.0f, 0.8f);
	cubeMat.Ks = glm::vec3(0.8f, 0.8f, 0.8f);
	cubeMat.Shininess = 16.0f;

	cubeFort = new CACube(2.0f, 0.5f, 0.1f);
	cubeFort->initialize(vulkan);
	cubeFort->setLight(light);
	cubeFort->setMaterial(cubeMat);
	cubeFort->translate(glm::vec3(0.0f,0.5f,6.0f));

	skel = new CASkeleton(vulkan);
	skel->initialize(vulkan);
	skel->setLight(light);

	anima = new CAAnimation(skel);
	anima->inicializarAnimacion();

	angle = 0.0;
}

//
// FUNCIÓN: CAScene::~CAScene()
//
// PROPÓSITO: Destruye el objeto que representa la escena
//
CAScene::~CAScene()
{
	delete ground;
	delete skel;
	delete anima;
	delete cubeFort;
}

//
// FUNCIÓN: CAScene::finalize(CAVulkanState* vulkan)
//
// PROPÓSITO: Destruyelos buffers de las figuras que forman la escena
//
void CAScene::finalize(CAVulkanState* vulkan)
{
	ground->finalize(vulkan);
	skel->finalize(vulkan);
	cubeFort->finalize(vulkan);
}

//
// FUNCIÓN: CAScene::addCommands(VkCommandBuffer commandBuffer, int index)
//
// PROPÓSITO: Añade los comandos de renderizado al command buffer
//
void CAScene::addCommands(CAVulkanState* vulkan, VkCommandBuffer commandBuffer, int index)
{
	ground->addCommands(vulkan, commandBuffer, index);
	skel->addCommands(vulkan, commandBuffer, index);
	cubeFort->addCommands(vulkan, commandBuffer, index);
}

//
// FUNCIÓN: CAScene::	void update(CAVulkanState* vulkan, uint32_t imageIndex, glm::mat4 view, glm::mat4 projection)
// 
// PROPÓSITO: Actualiza los datos para dibujar la escena
//
void CAScene::update(CAVulkanState* vulkan, glm::mat4 view, glm::mat4 projection)
{
	//Codigo modificado
	anima->animar(contador);
	ground->updateUniformBuffers(vulkan, view, projection);
	skel->updateUniformBuffers(vulkan, view, projection);
	cubeFort->updateUniformBuffers(vulkan, view, projection);

	std::this_thread::sleep_for(std::chrono::milliseconds(41));
	std::cout << "Contador: "<<contador << std::endl;
}
