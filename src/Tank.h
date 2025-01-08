#pragma once

#ifndef TANK
#define TANK

#include "ofMain.h"
#include "cg_cam_extras.h" 
#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "materials.h"

class Tank {
public:

	float speed, rotateSpeed, health;
	float gameOverRotation, gameOverMaxRotation;; // How much rotations can be used in "gameOver" animation

	//floor
	GLint resX, resY;
	GLfloat floorWidth, floorHeight, floorHeightPos;

	// Base
	GLfloat baseWidth, baseDepth, baseHeight;
	GLint basePosX, basePosY;
	ofVec3f basePos;

	// Rotator
	GLfloat rotatorWidth, rotatorHeight, rotatorDepth;
	GLfloat rotatorAngle;

	// Cannon
	GLfloat cannonWidth, cannonHeight, cannonDepth;

	// Cannon Ball
	GLfloat cBallWidth, cBallHeight, cBallDepth;
	ofVec3f cBallPos, cBallSpeed, cBallacc, cBallDir;
	GLfloat cBallSpeedMod;
	ofVec3f tip, bottom;
	GLfloat cBallMatrix[4][4];
	GLfloat auxMatrix[4][4];
	bool isShooted;
	int cBallLife, cBallLifeMax;

	int playerType;

	// Tank movement
	bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
	bool is_rotate_left, is_rotate_right;

	void setup(GLint mainResX,
				GLint mainResY,
				GLfloat mainFloorWidht,
				GLfloat mainFloorHeight,
				GLfloat mainFloorHeighPos);
	void update(bool isFirstPersonMode);
	void draw();
	void shoot();
	bool tankBoundaryCollisions(float floorWidth, float floorHeight);
	bool bulletBounderyCollision(float floorWidth, float floorHeight);
	void beginMaterials(int material);

	void gameOverAnimationUpdate();

	ofRectangle getTankPos() const {
		return ofRectangle(basePos.x - baseWidth / 2, basePos.y - baseDepth / 2, baseWidth, baseDepth);
	}

	ofRectangle getBulletPos() const {
		return ofRectangle(cBallPos.x - cBallWidth / 2, cBallPos.y - cBallHeight / 2, cBallWidth, cBallHeight);
	}

	Tank();

};


#endif 