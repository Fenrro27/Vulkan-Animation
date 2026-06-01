#pragma once
#include "CAFigure.h"
#include "CABalljoint.h"

class CABalljoint;

class CASkeleton 
{
private:
    // Método auxiliar para crear la jerarquía
    void createHierarchy();
    CAVulkanState* vulkan;

public:
    CASkeleton(CAVulkanState* vulkan);
    ~CASkeleton();
    void setLight(CALight l);
    void initialize(CAVulkanState* vulkan) ;
    void finalize(CAVulkanState* vulkan) ;
    void addCommands(CAVulkanState* vulkan, VkCommandBuffer commandBuffer, int index) ;
    void updateUniformBuffers(CAVulkanState* vulkan, glm::mat4 view, glm::mat4 projection) ;
    

    CABalljoint* root; // Articulación raíz del esqueleto
    CABalljoint* pelvis;
    CABalljoint* spine;
    CABalljoint* neck;

    CABalljoint* clavicle_l;
    CABalljoint* shoulder_l;
    CABalljoint* elbow_l;
    CABalljoint* wrist_l;

    CABalljoint* clavicle_r;
    CABalljoint* shoulder_r;
    CABalljoint* elbow_r;
    CABalljoint* wrist_r;

    CABalljoint* hip_l;
    CABalljoint* leg_l;
    CABalljoint* knee_l;
    CABalljoint* ankle_l;

    CABalljoint* hip_r;
    CABalljoint* leg_r;
    CABalljoint* knee_r;
    CABalljoint* ankle_r;
};

