#pragma once

#include "CASphere.h"
#include "CACylinder.h"
#include "CASkeleton.h"
#include <glm\glm.hpp>
#include <vector>

class CASkeleton;

//
// CLASE: Balljoint
//
// DESCRIPCIÓN: Representa una articulación con 3 grados de libertad
// 
class CABalljoint {
private:
	GLfloat length;
	glm::vec3 location;
	glm::vec3 dir;
	glm::vec3 up;
	glm::vec3 right;
	GLfloat angles[3];
	CASphere* joint;
	CACylinder* bone;
	void ComputeMatrix();

	//Codigo Modificado
	GLfloat minAngles[3];
	GLfloat maxAngles[3];
	CASkeleton* skeleto;
	CABalljoint* padre;
	std::vector<CABalljoint*> children; //Hijos de la articulacion
	glm::mat4 matrixArticulacion;

public:
	CABalljoint(float length);
	~CABalljoint();

	void initialize(CAVulkanState* vulkan);
	void finalize(CAVulkanState* vulkan);
	void addCommands(CAVulkanState* vulkan, VkCommandBuffer commandBuffer, int index);
	void updateUniformBuffers(CAVulkanState* vulkan, glm::mat4 view, glm::mat4 projection);

	void setLight(CALight l);
	void setLocation(glm::vec3 loc);
	void setOrientation(glm::vec3 nDir, glm::vec3 nUp);
	void setPose(float xrot, float yrot, float zrot);

	//Codigo Modificado 
	void setPose(glm::vec3 poseNueva);
	glm::vec3 getPose() const;

	// Límites de rotación
	void setLimits(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	void getLimits(float& minX, float& maxX, float& minY, float& maxY, float& minZ, float& maxZ) const;

	// Gestión de articulaciones hijas
	void addChild(CABalljoint* child);
	const std::vector<CABalljoint*>& getChildren() const;

	//Padre
	void addPadre(CABalljoint* child);


};


