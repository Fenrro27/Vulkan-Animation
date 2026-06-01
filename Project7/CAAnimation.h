#pragma once
#include <glm/glm.hpp> 
#include "CASkeleton.h"

const int nKeyFrames = 10;
const int nFramesIntermedios = 14;

class CAAnimation
{
private:
	glm::vec3 keyFrames[10][nKeyFrames]; // Articulaciones-Framens
	glm::vec3 animationFrames[10][(nKeyFrames-1) * nFramesIntermedios]; //Lugar donde almacenamos los grames
	CASkeleton* skel;
	int nFramesTotales = (nKeyFrames-1) * nFramesIntermedios;
public:
	CAAnimation(CASkeleton* skel);
	~CAAnimation();

	void inicializarAnimacion(); //Pone la pose base
	void animar(long& nFrame); //Metodo que inicia la animacion
	void GenerarFrames();
};

