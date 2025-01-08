#include "Tank.h"

Tank::Tank() {
	speed = 1.0;
	rotateSpeed = 1.0; 

	playerType = 1;
	health = 3;

	gameOverMaxRotation = 880;

	is_left_pressed = false;
	is_right_pressed = false;
	is_down_pressed = false;
	is_up_pressed = false;
	is_rotate_left = false;
	is_rotate_right = false;

}

void Tank::update(bool isFirstPersonMode) {

	if (isFirstPersonMode) {

		ofVec3f direction = tip - bottom;
		direction.normalize();

		ofVec3f right = direction.getCrossed(ofVec3f(0, 0, 1)); // Cross Product

		ofVec3f movement(0, 0, 0);
		if (is_up_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) movement += direction ;
		}
		if (is_down_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) movement -= direction;
		}
		if (is_right_pressed) { 
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) movement += right;
		}
		if (is_left_pressed) { 
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) movement -= right;
		}

		basePos.x += movement.x;
		basePos.y += movement.y;
	}
	else {
		if (is_left_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) basePos.x += -speed;
		}
		if (is_right_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) basePos.x += speed;
		}
		if (is_up_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) basePos.y += speed;
		}
		if (is_down_pressed) {
			if (!tankBoundaryCollisions(floorWidth, floorHeight)) basePos.y += -speed;
		}
	}

	if (is_rotate_left) rotatorAngle += rotateSpeed;
	if (is_rotate_right) rotatorAngle -= rotateSpeed;
	
	// Ball Shooted
	if (isShooted) {

		copy(&auxMatrix[0][0], &auxMatrix[0][0] + 16, &cBallMatrix[0][0]);

		cBallPos += cBallSpeedMod * cBallSpeed;

		if (bulletBounderyCollision(floorWidth, floorHeight)) {
			if (cBallLife == cBallLifeMax) {
				cBallLife = 0;
				isShooted = false;
			}
		}
	}
}

void Tank::shoot(){
	if (!isShooted) {
		cBallPos = tip;
		cBallSpeed = (tip - bottom).normalize(); 
		isShooted = true;
	}
}

void Tank::setup(GLint mainResX, 
				GLint mainResY, 
				GLfloat mainFloorWidht, 
				GLfloat mainFloorHeight, 
				GLfloat mainFloorHeighPos) 
{

	// floor
	resX = mainResX;
	resY = mainResY;
	floorWidth = mainFloorWidht;
	floorHeight = mainFloorHeight;
	floorHeightPos = mainFloorHeighPos;
	
	//tank parameters
	//base
	baseWidth = gh() * 0.3 / GLfloat(resX * 0.5 );
	baseHeight = gh() * 0.3  / GLfloat(resY * 0.5);
	baseDepth = baseWidth * 0.2;

	if (playerType) {
		basePos.x = floorWidth * 0.5 - baseWidth * 0.5 - 50;
	}
	else {
		basePos.x = - (floorWidth * 0.5) + baseWidth * 0.5 + 50;
	}
	basePos.y = 0;
	basePos.z = baseDepth * 0.5;

	//rotator
	rotatorWidth = min(baseWidth, baseHeight);
	rotatorHeight = rotatorWidth;
	rotatorDepth = 0.2 * rotatorWidth;
	rotatorAngle = 0;

	//cannon
	cannonWidth = rotatorWidth * 0.2;
	cannonHeight = cannonWidth;
	cannonDepth = cannonWidth * 5.;

	//cannonBall
	cBallWidth = cannonWidth * 0.9;
	cBallHeight = cBallWidth;
	cBallDepth = cannonDepth * 0.2;
	cBallSpeedMod = 12;
	cBallLife = 0;
	cBallLifeMax = 3;

	isShooted = false;

	gameOverRotation = 0;

}

void Tank::draw() {

	glPushMatrix();//master push

		//tank
		glPushMatrix();//tank master push
			glTranslatef(basePos.x, basePos.y, basePos.z);

			if (playerType) {
				glRotatef(180, 0, 0, 1);
			}

			//base
			glColor3f(153. / 255., 34./255., 31./255.);
			loadMaterial(4);
			if (playerType) { 
				loadMaterial(5);
				glColor3f(50. / 255., 93. / 255., 37. / 255.); 
			}

			glPushMatrix();//base push
				glScalef(baseWidth, baseHeight, baseDepth);
				cube_unit();
			glPopMatrix();//base pop


			//rotator
			glColor3f(177. / 255., 53. / 255., 50./255.);
			if (playerType) glColor3f(68./255., 112./255. , 53./255.);


			glPushMatrix();//rotator push
				
				glTranslatef(0, 0, rotatorDepth * 0.5 + baseDepth * 0.51);
				glRotatef(rotatorAngle, 0, 0, 1);

				glPushMatrix();//rotator scale push
					glScalef(rotatorWidth, rotatorHeight, rotatorDepth);
					cube_unit();
				glPopMatrix();//rotator scale pop

				//cannon
				glPushMatrix();//cannon master push

					glRotatef(90, 0, 1, 0);
					glTranslatef(0, 0, cannonDepth * 0.5);

					glColor3f(153. / 255., 34. / 255., 31. / 255.);
					if (playerType) glColor3f(50. / 255., 93. / 255., 37. / 255.);

					glPushMatrix();//cannon scale push
						glScalef(cannonWidth, cannonHeight, cannonDepth);
						cube_unit();
					glPopMatrix();//cannon scale pop

					//cannon bottom
					glPushMatrix();//cannon bottom push
						glTranslatef(0, 0, -0.5 * cannonDepth);
						bottom = getModelViewMatrixPos();

						glColor3f(214. / 255., 184. / 255., 0.);
						if (playerType) glColor3f(1.0f, 0.8588f, 0.3451f);
						//modelview da cannon ball
						glGetFloatv(GL_MODELVIEW_MATRIX, &auxMatrix[0][0]);

						glScalef(cannonWidth, cannonHeight, cannonDepth * 0.1);
						cube_unit();
					glPopMatrix();//cannon bottom pop

					//cannon tip
					glPushMatrix();//cannon tip push
						glTranslatef(0, 0, 0.5 * cannonDepth);

						glColor3f(225. / 255., 98. / 255., 93./255.);
						if (playerType) glColor3f(111./255., 158./255., 91./255.);

						//modelview da cannon ball
						tip = getModelViewMatrixPos();
						glScalef(cannonWidth, cannonHeight, cannonDepth * 0.1);
						cube_unit();
					glPopMatrix();//cannon tip pop

				glPopMatrix();//cannon master pop
			glPopMatrix();//rotator pop
		glPopMatrix();//tank master poop
	glPopMatrix();//master pop


	if (isShooted) {

		glColor3f(226. / 255., 142. / 255., 120./255.);
		loadMaterial(15);
		if (playerType) {
			loadMaterial(14);
			glColor3f(147. / 255, 178. / 255., 165. / 255.); 
		}
		glPushMatrix();
			glTranslatef(cBallPos.x, cBallPos.y, cBallPos.z);
			glScalef(cBallWidth, cBallHeight, cBallDepth);
			cube_unit();
		glPopMatrix();

	}
}

void Tank::gameOverAnimationUpdate() {
	isShooted = false;

	if (gameOverRotation < gameOverMaxRotation) {
		gameOverRotation += 3;
		rotatorAngle += 3;
	}
}

bool Tank::tankBoundaryCollisions(float floorWidth, float floorHeight) {
	float leftBoundary = - (floorWidth * 0.5) + baseWidth * 0.5;
	float rightBoundary = floorWidth * 0.5 - baseWidth * 0.5;
	float topBoundary = floorHeight * 0.5 - baseHeight * 0.5;
	float bottomBoundary = - (floorHeight * 0.5) + baseHeight * 0.5;

	if (basePos.x < leftBoundary) {
		basePos.x = leftBoundary;
		return true;
	}
	if (basePos.x > rightBoundary) {
		basePos.x = rightBoundary;
		return true;
	}
	if (basePos.y > topBoundary) {
		basePos.y = topBoundary;
		return true;
	}
	if (basePos.y < bottomBoundary) {
		basePos.y = bottomBoundary;
		return true;
	}

	return false; 
}

bool Tank::bulletBounderyCollision(float floorWidth, float floorHeight) {
	float leftBoundary = -(floorWidth * 0.5);
	float rightBoundary = floorWidth * 0.5;
	float topBoundary = floorHeight * 0.5;
	float bottomBoundary = - (floorHeight * 0.5) ;

	if (cBallPos.x <= leftBoundary || cBallPos.x >= rightBoundary) {
		cBallSpeed.x *= -1;
		cBallLife++;
		return true;
	}

	if (cBallPos.y >= topBoundary || cBallPos.y <= bottomBoundary) {
		cBallSpeed.y *= -1;
		cBallLife++;
		return true;
	}
	return false;
}

void Tank::beginMaterials(int material) { loadMaterial(material); }