#pragma once

#include "ofMain.h"
#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "cg_cam_extras.h"
#include "Tank.h"
#include "Enemy.h"
#include "Lights.h"

class ofApp : public ofBaseApp{

	public:

		Tank player1;
		Tank* winner;
		Enemy player2;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();
		void Debug();

		//camera variables
		int view;
		GLfloat lensAngle;
		GLfloat alpha, beta;
		
		ofVec3f camPos;
		ofVec3f lookatPos;
		ofVec3f camUp;
		GLfloat orbitAngle;

		//game variables
		void setupFloor();
		void drawFloor();
		void checkBulletCollisions(Tank& playerTank, Tank& enemyTank);
		void printLives(Tank& player);
		void checkGameOver();

		//floor
		GLint resX, resY;
		GLfloat floorWidth, floorHeight, floorHeightPos;

		GLfloat perfectDist;

		string game_state, game_difficulty;
		string last_game_state;

		bool gameOver;

		float flashing_time, last_flashing_time;

		// Lights
		Lights light;
		bool isDirOn, isP1PontOn, isP2PontOn,
			isP1BulletPontOn, isP2BulletPontOn,
			isSpot1On, isSpot2On;
		int lightFlags[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

		
		// Texture
		ofImage floorTexture;
		ofImage floorTextureHard;
		ofImage tankTexture;
};
