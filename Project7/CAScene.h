#pragma once

#include "CAVulkanState.h"
#include "CAFigure.h"
#include "CABalljoint.h"
#include "CASkeleton.h"
#include "CAAnimation.h"
#include "CACube.h"

#include <thread> // Para std::this_thread::sleep_for
#include <chrono> // Para std::chrono::seconds



class CAScene {
public:
	CAScene(CAVulkanState* vulkan);
	~CAScene();
	void finalize(CAVulkanState* vulkan);
	void addCommands(CAVulkanState* vulkan, VkCommandBuffer commandBuffer, int index);
	void update(CAVulkanState* vulkan, glm::mat4 view, glm::mat4 projection);

private:
	CAAnimation* anima;
	CAFigure* ground;
	CASkeleton* skel;
	CACube* cubeFort;
	float angle;
	long contador = 0;
};

