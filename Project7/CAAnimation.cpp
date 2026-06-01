#include "CAAnimation.h"






CAAnimation::CAAnimation(CASkeleton* skel)
{
	this->skel = skel;
	/*
	CABalljoint* root; // Articulación raíz del esqueleto
    CABalljoint* shoulder_l;
    CABalljoint* elbow_l;
    CABalljoint* shoulder_r;

    CABalljoint* elbow_r;
    CABalljoint* leg_l;
    CABalljoint* knee_l;
    CABalljoint* leg_r;
    
	CABalljoint* knee_r;
	*/

	// Pose 1
	keyFrames[0][0] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][0] = glm::vec3(90.0f, 0.0f, 0.0f);//shoulder_l
	keyFrames[2][0] = glm::vec3(0.0f, 0.0f, 0.0f);//elbow_l
	keyFrames[3][0] = glm::vec3(90.0f, 0.0f, 0.0f);//shoulder_r
	keyFrames[4][0] = glm::vec3(0.0f, 0.0f, 0.0f);//elbow_r
	keyFrames[5][0] = glm::vec3(0.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][0] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][0] = glm::vec3(0.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][0] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][0] = glm::vec3(0.0f, 1.0f, -4.5f);//Posicion en el escenario

	// Pose 2
	keyFrames[0][1] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][1] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_l
	keyFrames[2][1] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][1] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_r
	keyFrames[4][1] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][1] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][1] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][1] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][1] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][1] = glm::vec3(0.0f, 1.0f, -3.0f);//Posicion en el escenario

	// Pose 3
	keyFrames[0][2] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][2] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_l
	keyFrames[2][2] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][2] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_r
	keyFrames[4][2] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][2] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][2] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][2] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][2] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][2] = glm::vec3(0.0f, 1.0f, -1.5f);//Posicion en el escenario

	// Pose 4
	keyFrames[0][3] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][3] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_l
	keyFrames[2][3] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][3] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_r
	keyFrames[4][3] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][3] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][3] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][3] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][3] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][3] = glm::vec3(0.0f, 1.0f, 0.0f);//Posicion en el escenario

	// Pose 5
	keyFrames[0][4] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][4] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_l
	keyFrames[2][4] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][4] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_r
	keyFrames[4][4] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][4] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][4] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][4] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][4] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][4] = glm::vec3(0.0f, 1.0f, 1.5f);//Posicion en el escenario
	
	// Pose 6
	keyFrames[0][5] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][5] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_l
	keyFrames[2][5] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][5] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_r
	keyFrames[4][5] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][5] = glm::vec3(40.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][5] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][5] = glm::vec3(0.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][5] = glm::vec3(45.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][5] = glm::vec3(0.0f, 1.0f, 3.0f);//Posicion en el escenario

	// Pose 7 //Saltamos
	keyFrames[0][6] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][6] = glm::vec3(0.0f, 0.0f, 0.0f);//shoulder_l
	keyFrames[2][6] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][6] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_r
	keyFrames[4][6] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][6] = glm::vec3(0.0f, 90.0f, 0.0f);//leg_l
	keyFrames[6][6] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][6] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][6] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][6] = glm::vec3(0.0f, 2.5f, 4.5f);//Posicion en el escenario

	// Pose 8
	keyFrames[0][7] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][7] = glm::vec3(45.0f, 0.0f, 0.0f);//shoulder_l
	keyFrames[2][7] = glm::vec3(0.0f, -90.0f, 0.0f);//elbow_l
	keyFrames[3][7] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_r
	keyFrames[4][7] = glm::vec3(0.0f, 90.0f, 0.0f);//elbow_r
	keyFrames[5][7] = glm::vec3(0.0f, 45.0f, 0.0f);//leg_l
	keyFrames[6][7] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][7] = glm::vec3(0.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][7] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][7] = glm::vec3(0.0f, 2.0f, 6.0f);//Posicion en el escenario

	// Pose 9
	keyFrames[0][8] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][8] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_l
	keyFrames[2][8] = glm::vec3(0.0f, -45.0f, 0.0f);//elbow_l
	keyFrames[3][8] = glm::vec3(90.0f, 0.0f, -90.0f);//shoulder_r
	keyFrames[4][8] = glm::vec3(0.0f, 45.0f, 0.0f);//elbow_r
	keyFrames[5][8] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][8] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][8] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][8] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][8] = glm::vec3(0.0f, 1.0f, 7.5f);//Posicion en el escenario

	// Pose 10
	keyFrames[0][9] = glm::vec3(0.0f, 0.0f, 0.0f);//root
	keyFrames[1][9] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_l
	keyFrames[2][9] = glm::vec3(0.0f, 0.0f, 0.0f);//elbow_l
	keyFrames[3][9] = glm::vec3(90.0f, 0.0f, 90.0f);//shoulder_r
	keyFrames[4][9] = glm::vec3(0.0f, 0.0f, 0.0f);//elbow_r
	keyFrames[5][9] = glm::vec3(-90.0f, 0.0f, 0.0f);//leg_l
	keyFrames[6][9] = glm::vec3(0.0f, 0.0f, 0.0f);//knee_l
	keyFrames[7][9] = glm::vec3(90.0f, 0.0f, 0.0f);//leg_r
	keyFrames[8][9] = glm::vec3(90.0f, 0.0f, 0.0f);//knee_r
	keyFrames[9][9] = glm::vec3(0.0f, 1.0f, 9.0f);//Posicion en el escenario

	// Generamos todos los frames de la animacion
	GenerarFrames();

}

CAAnimation::~CAAnimation()
{
	
}

void CAAnimation::inicializarAnimacion() //Pone la pose base
{
	skel->root->setPose(keyFrames[0][0]);
	skel->shoulder_l->setPose(keyFrames[1][0]);
	skel->elbow_l->setPose(keyFrames[2][0]);
	skel->shoulder_r->setPose(keyFrames[3][0]);

	skel->elbow_r->setPose(keyFrames[4][0]);
	skel->leg_l->setPose(keyFrames[5][0]);
	skel->knee_l->setPose(keyFrames[6][0]);
	skel->leg_r->setPose(keyFrames[7][0]);

	skel->knee_r->setPose(keyFrames[8][0]);
	skel->root->setLocation(keyFrames[9][0]);

}

void CAAnimation::animar(long& nFrame) //Metodo que inicia la animacion
{

	if (nFrame > nFramesTotales) {
		nFrame = 0; //Reseteamos si termina la animacion
		inicializarAnimacion();
	}
	else {

		skel->root->setPose(animationFrames[0][nFrame]);
		skel->shoulder_l->setPose(animationFrames[1][nFrame]);
		skel->elbow_l->setPose(animationFrames[2][nFrame]);
		skel->shoulder_r->setPose(animationFrames[3][nFrame]);

		skel->elbow_r->setPose(animationFrames[4][nFrame]);
		skel->leg_l->setPose(animationFrames[5][nFrame]);
		skel->knee_l->setPose(animationFrames[6][nFrame]);
		skel->leg_r->setPose(animationFrames[7][nFrame]);

		skel->knee_r->setPose(animationFrames[8][nFrame]);
		skel->root->setLocation(animationFrames[9][nFrame]);

		nFrame++;//Incrementamos el frame
	}
}

void CAAnimation::GenerarFrames()
{
	int nFrame = 0; 

	for (int i = 1; i < nKeyFrames; i++) // el primer frame 
	{

		glm::vec3 nuevoFrame[10];//Array con los frames nuevos
		glm::vec3 incrementoFrame[10]; //Array con lo que debe incrementarse cada frame
		
		//Asignamos el keyFrame al nuevoFrame

		for (int k = 0; k < 10; k++) {
			nuevoFrame[k] = keyFrames[k][i-1]; //Asignamos el keyFrame anterior al nuevoFrame antes de empezar el bucle
			//Calculamos los incrementos del frame teniendo en cuenta el anterior y el nuevo
			incrementoFrame[k] = (keyFrames[k][i] - keyFrames[k][i-1])/(float)nFramesIntermedios; //Asignamos el keyFrame al nuevoFrame antes de empezar el bucle
		}


		for (int j = 0; j < nFramesIntermedios; j++)
		{
			//Asignamos los frames al animationFrame
			for (int k = 0; k < 10; k++) {
				animationFrames[k][nFrame] = nuevoFrame[k];
			}

			//Actualizamos el valor del frame incrementando
			for (int k = 0; k < 10; k++) 
			{
				nuevoFrame[k] += incrementoFrame[k];
			}

			nFrame++; // Incrementamos el frame una vez hecho el actual
		}

	}
}