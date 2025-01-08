#pragma once

#ifndef LIGHTS
#define LIGHTS 

#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "cg_cam_extras.h"
#include "ofMain.h"
#include "materials.h"
#include "Tank.h"


class Lights {
public:

	// Directional light
	GLfloat Position[4];
	GLfloat Ambient[4];
	GLfloat Difuse[4];
	GLfloat Specular[4];

	// Player 1 light
	GLfloat ponPostition[4];
	GLfloat ponAmbient[4];
	GLfloat ponDifuse[4];
	GLfloat ponSpecular[4];

	// Player 2 light
	GLfloat pon2Postition[4];
	GLfloat pon2Ambient[4];
	GLfloat pon2Difuse[4];
	GLfloat pon2Specular[4];

	// Player 1 bullet light
	GLfloat pon3Postition[4];
	GLfloat pon3Ambient[4];
	GLfloat pon3Difuse[4];
	GLfloat pon3Specular[4];

	// PLayer 2 bullet light
	GLfloat pon4Postition[4];
	GLfloat pon4Ambient[4];
	GLfloat pon4Difuse[4];
	GLfloat pon4Specular[4];

	// Player 1 spot light
	GLfloat spotPosition[4];
	GLfloat spotDirection[3];
	GLfloat spotAmbient[4];
	GLfloat spotDifuse[4];
	GLfloat spotSpecular[4];
	GLfloat spotCutoff, spotExponent;
	GLfloat spotAtC, spotAtL, spotAtQ;
	GLfloat spotTheta;

	// Player 2 spot light
	GLfloat spot2Position[4];
	GLfloat spot2Direction[3];
	GLfloat spot2Ambient[4];
	GLfloat spot2Difuse[4];
	GLfloat spot2Specular[4];
	GLfloat spot2Cutoff, spot2Exponent;
	GLfloat spot2AtC, spot2AtL, spot2AtQ;
	GLfloat spot2Theta;
				
	Lights();
	void setLight(ofVec3f player1Pos,
		ofVec3f player2Pos,
		ofVec3f player1Bullet,
		ofVec3f player2Bullet,
		bool isShooted1,
		bool isShooted2,
		bool isDirOn,
		bool isP1PontOn,
		bool isP2PontOn,
		bool isP1BulletPontOn,
		bool isP2BulletPontOn,
		bool isSpot1On,
		bool isSpot2On,
		int lightFlags[9]);
	void disableLight();

	void setUpDirectionalLight();
	void setUpPontualLights();
	void setUpSpotLights();
	void updateSpotLight();
	void lightComponents(int lightFlags[9]);
};

#endif