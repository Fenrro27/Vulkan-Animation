#include "CASkeleton.h"


CASkeleton::CASkeleton(CAVulkanState* vulkan) {
    this->vulkan = vulkan;
    createHierarchy();
}


CASkeleton::~CASkeleton() {
    // Destructor
}

void CASkeleton::setLight(CALight light)
{
    root->setLight(light);

}

void CASkeleton::initialize(CAVulkanState* vulkan) {
    // Inicializar la jerarquía de articulaciones
    if (root) root->initialize(vulkan);
}

void CASkeleton::finalize(CAVulkanState* vulkan) {
    // Finalizar la jerarquía de articulaciones
    if (root) root->finalize(vulkan);

}

void CASkeleton::addCommands(CAVulkanState* vulkan, VkCommandBuffer commandBuffer, int index) {
    // Agregar comandos de la jerarquía
    if (root) root->addCommands(vulkan, commandBuffer, index);
}

void CASkeleton::updateUniformBuffers(CAVulkanState* vulkan, glm::mat4 view, glm::mat4 projection) {
    // Actualizar los buffers de la jerarquía
    if (root) root->updateUniformBuffers(vulkan, view, projection);
}



void CASkeleton::createHierarchy() {
    // Crear la raíza
    root = new CABalljoint(0); //Para evitar mostrar esta articulacion ponemos en 0
    root->initialize(vulkan);
    root->setLocation(glm::vec3(0.0f, 1.0f, 0.0f));
    root->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    // Crear pelvis
    pelvis = new CABalljoint(0.3f);
    pelvis->initialize(vulkan);
    pelvis->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    pelvis->setOrientation(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    root->addChild(pelvis);

    // Crear columna vertebral
    spine = new CABalljoint(0.4f);
    spine->initialize(vulkan);
    spine->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    spine->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    pelvis->addChild(spine);

    // Crear cuello
    neck = new CABalljoint(0.35f);
    neck->initialize(vulkan);
    neck->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    neck->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    spine->addChild(neck);

    // Crear clavícula izquierda
    clavicle_l = new CABalljoint(0.25f);
    clavicle_l->initialize(vulkan);
    clavicle_l->setLocation(glm::vec3(-0.05f, 0.0f, -0.05f));
    clavicle_l->setOrientation(glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    spine->addChild(clavicle_l);

    // Crear brazo izquierdo
    shoulder_l = new CABalljoint(0.35f);
    shoulder_l->initialize(vulkan);
    shoulder_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    shoulder_l->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    clavicle_l->addChild(shoulder_l);

    elbow_l = new CABalljoint(0.30f);
    elbow_l->initialize(vulkan);
    elbow_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    elbow_l->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shoulder_l->addChild(elbow_l);

    wrist_l = new CABalljoint(0.20f);
    wrist_l->initialize(vulkan);
    wrist_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    wrist_l->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    elbow_l->addChild(wrist_l);

    // Crear clavícula derecha
    clavicle_r = new CABalljoint(0.25f);
    clavicle_r->initialize(vulkan);
    clavicle_r->setLocation(glm::vec3(0.05f, 0.0f, -0.05f));
    clavicle_r->setOrientation(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    spine->addChild(clavicle_r);

    // Crear brazo derecho
    shoulder_r = new CABalljoint(0.35f);
    shoulder_r->initialize(vulkan);
    shoulder_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    shoulder_r->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    clavicle_r->addChild(shoulder_r);

    elbow_r = new CABalljoint(0.30f);
    elbow_r->initialize(vulkan);
    elbow_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    elbow_r->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    shoulder_r->addChild(elbow_r);

    wrist_r = new CABalljoint(0.20f);
    wrist_r->initialize(vulkan);
    wrist_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    wrist_r->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    elbow_r->addChild(wrist_r);

    // Crear cadera izquierda
    hip_l = new CABalljoint(0.2f);
    hip_l->initialize(vulkan);
    hip_l->setLocation(glm::vec3(0.05f, -0.05f, 0.0f));
    hip_l->setOrientation(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    root->addChild(hip_l);

    leg_l = new CABalljoint(0.5f);
    leg_l->initialize(vulkan);
    leg_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    leg_l->setOrientation(glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
    hip_l->addChild(leg_l);

    knee_l = new CABalljoint(0.4f);
    knee_l->initialize(vulkan);
    knee_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    knee_l->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    leg_l->addChild(knee_l);

    ankle_l = new CABalljoint(0.25f);
    ankle_l->initialize(vulkan);
    ankle_l->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    ankle_l->setOrientation(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    knee_l->addChild(ankle_l);

    // Crear cadera derecha
    hip_r = new CABalljoint(0.2f);
    hip_r->initialize(vulkan);
    hip_r->setLocation(glm::vec3(-0.05f, -0.05f, 0.0f));
    hip_r->setOrientation(glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    root->addChild(hip_r);

    leg_r = new CABalljoint(0.5f);
    leg_r->initialize(vulkan);
    leg_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    leg_r->setOrientation(glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    hip_r->addChild(leg_r);

    knee_r = new CABalljoint(0.4f);
    knee_r->initialize(vulkan);
    knee_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    knee_r->setOrientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    leg_r->addChild(knee_r);

    ankle_r = new CABalljoint(0.25f);
    ankle_r->initialize(vulkan);
    ankle_r->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));
    ankle_r->setOrientation(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    knee_r->addChild(ankle_r);
}