#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFullscreen(true);
	//ofSetVerticalSync(false);
	glEnable(GL_DEPTH_TEST);
	ofDisableArbTex();
	
	glPointSize(200);
	glLineWidth(3);

	// Camera parameters
	lensAngle = 60;
	alpha = 10;
	beta = 1000;

	perfectDist = gh() * 0.5 / tan(lensAngle * 0.5 * PI / 180);

	// Game over variables
	flashing_time = 0.1;
	last_flashing_time = 0;

	// Forms of visualization
	setupFloor();
	ofBackground(0, 0, 0);

	// Game States
	game_state = "start";
	game_difficulty = "easy";

	//Lights
	isDirOn = true;
	isP1PontOn = true;
	isP2PontOn = true;
	isP1BulletPontOn = true;
	isP2BulletPontOn = true;
	isSpot1On = true;
	isSpot2On = true;

	// Texture
	floorTexture.load("floor.png");
	floorTextureHard.load("metal2.png");
	tankTexture.load("TankUPPP.png");

}

//--------------------------------------------------------------
void ofApp::update() {

	if (game_state != "start" && game_state != "end") {

		light.updateSpotLight();

		if (game_state == "fp") {
			player1.update(true);
			player2.update(player1);
			checkBulletCollisions(player1, player2);
		}
		else {
			player1.update(false);
			player2.update(player1);
			checkBulletCollisions(player1, player2);
		}
				
		checkGameOver();
	}
	else if (game_state == "end" && winner) {

		if (winner == &player1) {
			player2.gameOverAnimationUpdate();
		}
		else if (winner == &player2) {
			player1.gameOverAnimationUpdate();
		}
	}
	else if (game_state == "start") {
		player1.setup(10, 10, floorWidth, floorHeight, floorHeightPos);
		player2.setup(10, 10, floorWidth, floorHeight, floorHeightPos);

		// Choose Difficulty
		if (game_difficulty == "easy") { 
			player2.difficulty(0); 
		}
		else if (game_difficulty == "hard") {
			isDirOn = false;
			isP1PontOn = false;
			isP2PontOn = false;
			isP1BulletPontOn = true;
			isP2BulletPontOn = true;
			player2.difficulty(1); 
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (game_state == "start") {

		ofBackground(0, 0, 0);

		light.disableLight();

		std::string title = "COMBAT";
		std::string subtitle = "ATARI GAME";
		std::string prompt1 = "PRESS M TO START";
		std::string prompt2 = "PRESS N FOR INFO";

		int centerX = gw() / 2;
		int centerY = gh() / 2;

		ofSetColor(255, 255, 0);
		ofDrawBitmapString(title, centerX - (title.length() * 4), centerY - 40);

		ofSetColor(255, 165, 0);
		ofDrawBitmapString(subtitle, centerX - (subtitle.length() * 4), centerY - 10);

		ofSetColor(255, 165, 100);
		ofDrawBitmapString(prompt1, centerX - (prompt1.length() * 4), centerY + 30);
		ofDrawBitmapString(prompt2, centerX - (prompt2.length() * 4), centerY + 50);

		ofDrawBitmapString("DIFFICULTY: " + game_difficulty, gw() - 150, 20);
	}
	else if (game_state == "info") {
		light.disableLight();

		std::string title = "COMBAT";
		std::string subtitle = "ATARI GAME";
		std::string instructions1 = "ARROWS to move, Q and W to rotate, SPACE to shoot";
		std::string instructions2 = "M to switch the view";
		std::string instructions3 = "Player 1 has 3 lives (Green Tank), Player 2 has 1 life (Red Tank)";
		std::string instructions4 = "To kill Player 2, the shot must ricochet";
		std::string instructions5 = "PRESS M TO START";

		int centerX = gw() / 2;
		int centerY = gh() / 2;

		ofSetColor(255, 255, 0);
		ofDrawBitmapString(title, centerX - (title.length() * 4), centerY - 60);

		ofSetColor(255, 165, 0);
		ofDrawBitmapString(subtitle, centerX - (subtitle.length() * 4), centerY - 30);

		ofSetColor(255, 165, 100);
		ofDrawBitmapString(instructions1, centerX - (instructions1.length() * 4), centerY + 10);
		ofDrawBitmapString(instructions2, centerX - (instructions2.length() * 4), centerY + 30);
		ofDrawBitmapString(instructions3, centerX - (instructions3.length() * 4), centerY + 50);
		ofDrawBitmapString(instructions4, centerX - (instructions4.length() * 4), centerY + 70);
		ofDrawBitmapString(instructions5, centerX - (instructions5.length() * 4), centerY + 90);

		ofDrawBitmapString("DIFFICULTY: " + game_difficulty, gw() - 150, 20);
	}
	else if (game_state == "fp") {

		ofBackground(0, 0, 0);

		ofVec3f cameraPosition = player1.basePos + ofVec3f(0, 0, player1.baseDepth + player1.rotatorDepth + 40);

		printLives(player1);
		ofDrawBitmapString("DIFFICULTY: " + game_difficulty, gw() - 150, 20);

		glViewport(0, 0, gw(), gh());
		perspective(lensAngle, alpha, beta);
		lookat(	cameraPosition.x, cameraPosition.y, cameraPosition.z, 
				player1.tip.x, player1.tip.y, player1.tip.z + 40,
				0, 0, 1);
		
		light.setLight(player1.basePos, player2.basePos, 
						player1.cBallPos, player2.cBallPos, 
						player1.isShooted, player2.isShooted,
						isDirOn, 
						isP1PontOn, isP2PontOn,
						isP1BulletPontOn, isP2BulletPontOn,
						isSpot1On, isSpot2On, lightFlags);

		drawFloor();

		glEnable(GL_TEXTURE);
		tankTexture.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

		player1.beginMaterials(7);
		player1.draw();
		player2.beginMaterials(8);
		player2.draw();

		tankTexture.bind();
		glDisable(GL_TEXTURE);

		glViewport(0, gh() * 0.8, gw() * 0.20, gh() * 0.20);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-gw() * 0.5, gw() * 0.5, -gh() * 0.5, gh() * 0.5, -gw(), gw());
		lookat(0, 0, 1, 0, 0, 0, 0, 1, 0);

		light.setLight(player1.basePos, player2.basePos,
			player1.cBallPos, player2.cBallPos,
			player1.isShooted, player2.isShooted,
			isDirOn,
			isP1PontOn, isP2PontOn,
			isP1BulletPontOn, isP2BulletPontOn,
			isSpot1On, isSpot2On, lightFlags);

		glEnable(GL_TEXTURE);
		tankTexture.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

		drawFloor();
		player1.beginMaterials(7);
		player1.draw();
		player2.beginMaterials(8);
		player2.draw();
				
		tankTexture.unbind();
		glDisable(GL_TEXTURE);
	}
	else if (game_state == "3d") {

		ofBackground(0, 0, 0);

		printLives(player1);
		ofDrawBitmapString("DIFFICULTY: " + game_difficulty, gw() - 150, 20);

		glViewport(0, 0, gw(), gh());
		perspective(lensAngle, alpha, beta);
		lookat(0, -gh() * 0.8, perfectDist * 1.3, 0, 0, 0, 0, 1, 0);

		light.setLight(player1.basePos, player2.basePos,
			player1.cBallPos, player2.cBallPos,
			player1.isShooted, player2.isShooted,
			isDirOn,
			isP1PontOn, isP2PontOn,
			isP1BulletPontOn, isP2BulletPontOn,
			isSpot1On, isSpot2On, lightFlags);

		drawFloor();

		glEnable(GL_TEXTURE);
		tankTexture.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

		player1.beginMaterials(7);
		player1.draw();
		player2.beginMaterials(8);
		player2.draw();

		tankTexture.unbind();
		glDisable(GL_TEXTURE);

		glViewport(0, gh() * 0.8, gw() * 0.20, gh() * 0.20);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-gw() * 0.5, gw() * 0.5, -gh() * 0.5, gh() * 0.5, -gw(), gw());
		lookat(0, 0, 1, 0, 0, 0, 0, 1, 0);

		light.setLight(player1.basePos, player2.basePos,
			player1.cBallPos, player2.cBallPos,
			player1.isShooted, player2.isShooted,
			isDirOn,
			isP1PontOn, isP2PontOn,
			isP1BulletPontOn, isP2BulletPontOn,
			isSpot1On, isSpot2On, lightFlags);

		drawFloor();

		glEnable(GL_TEXTURE);
		tankTexture.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

		player1.beginMaterials(7);
		player1.draw();
		player2.beginMaterials(8);
		player2.draw();

		tankTexture.unbind();
		glDisable(GL_TEXTURE);

	}
	else if (game_state == "2d") {

		ofBackground(0, 0, 0);

		printLives(player1);
		ofDrawBitmapString("DIFFICULTY: " + game_difficulty, gw() - 150, 20);

		glViewport(0, 0, gw(), gh());
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-gw() * 0.5, gw() * 0.5, -gh() * 0.5, gh() * 0.5, -gw(), gw());
		lookat(0, 0, 1, 0, 0, 0, 0, 1, 0);
		
		light.setLight(player1.basePos, player2.basePos,
			player1.cBallPos, player2.cBallPos,
			player1.isShooted, player2.isShooted,
			isDirOn,
			isP1PontOn, isP2PontOn,
			isP1BulletPontOn, isP2BulletPontOn,
			isSpot1On, isSpot2On, lightFlags);

		drawFloor();

		glEnable(GL_TEXTURE);
		tankTexture.bind();
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

		player1.beginMaterials(7);
		player1.draw();
		player2.beginMaterials(8);
		player2.draw();

		tankTexture.unbind();
		glDisable(GL_TEXTURE);
		
	}
	else if (game_state == "end") {

		if (!(player1.gameOverRotation >= player1.gameOverMaxRotation || // While the tank dont stop rotating
			player2.gameOverRotation >= player2.gameOverMaxRotation)) {

			if (last_game_state == "fp" || last_game_state == "start" ) {

				ofBackground(0, 0, 0);

				glViewport(0, 0, gw(), gh());
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-gw() * 0.5, gw() * 0.5, -gh() * 0.5, gh() * 0.5, -gw(), gw());
				lookat(0, 0, 1, 0, 0, 0, 0, 1, 0);

				light.setLight(player1.basePos, player2.basePos,
					player1.cBallPos, player2.cBallPos,
					player1.isShooted, player2.isShooted,
					isDirOn,
					true, true,
					isP1BulletPontOn, isP2BulletPontOn,
					isSpot1On, isSpot2On, lightFlags);

				drawFloor();

				glEnable(GL_TEXTURE);
				tankTexture.bind();
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

				player1.beginMaterials(7);
				player1.draw();
				player2.beginMaterials(8);
				player2.draw();

				tankTexture.unbind();
				glDisable(GL_TEXTURE);
			}
			else if (last_game_state == "2d") {

				ofBackground(0, 0, 0);

				glViewport(0, 0, gw(), gh());
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				perspective(lensAngle, alpha, beta);
				lookat(0, -gh() * 0.8, perfectDist * 1.3, 0, 0, 0, 0, 1, 0);

				light.setLight(player1.basePos, player2.basePos,
					player1.cBallPos, player2.cBallPos,
					player1.isShooted, player2.isShooted,
					isDirOn,
					true, true,
					isP1BulletPontOn, isP2BulletPontOn,
					isSpot1On, isSpot2On, lightFlags);

				drawFloor();

				glEnable(GL_TEXTURE);
				tankTexture.bind();
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPEAT);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

				player1.beginMaterials(7);
				player1.draw();
				player2.beginMaterials(8);
				player2.draw();

				tankTexture.unbind();
				glDisable(GL_TEXTURE);
				
			}
			else if (last_game_state == "3d") {

				last_flashing_time += ofGetLastFrameTime();
				if (last_flashing_time >= flashing_time) {
					
					ofBackground(255, 255, 255);
					last_flashing_time = 0;
				}
				else { 
					
					ofBackground(10, 10, 50);
				}
			}				
		}
		else { // GAME OVER FRAME
			ofBackground(0, 0, 0);

			light.disableLight();

			ofSetColor(255, 0, 0);
			string endText = (winner == &player1) ? "PLAYER 1 WINS!" : "GAME OVER!";
			ofDrawBitmapString(endText, gw() / 2 - 60, gh() / 2 - 20);
			ofSetColor(255, 165, 0);
			ofDrawBitmapString("PRESS M TO RESTART", gw() / 2 - 80, gh() / 2 + 20);
		}
	}
}

void ofApp::setupFloor() {
	//floor parameters
	resX = 32;
	resY = 32;
	floorWidth = gw();
	floorHeight = gh();
	floorHeightPos = 0.;
}

void ofApp::drawFloor() {
	glColor3f(67./255., 41./255., 38./255.);
	loadMaterial(2);

	glEnable(GL_TEXTURE);
	if (game_difficulty == "easy") floorTexture.bind();
	else (floorTextureHard.bind());
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glPushMatrix();
		glScalef(floorWidth, floorHeight, 1.);
		malha_unit(resX, resY);
	glPopMatrix();

	if (game_difficulty == "easy") floorTexture.unbind();
	else (floorTextureHard.unbind());
	glDisable(GL_TEXTURE);

}

void ofApp::printLives(Tank& player) {
	glDisable(GL_LIGHTING);
	string lives = "LIVES: " + ofToString(player.health); // 1 casa decimalc
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(lives, gw() / 2 - 40, gh() / 2 - 20);
	glEnable(GL_LIGHTING);
	
}

void ofApp::checkBulletCollisions(Tank& playerTank, Tank& enemyTank) {

	if (playerTank.isShooted && playerTank.getBulletPos().intersects(enemyTank.getTankPos())) {
		if (playerTank.cBallLife > 0) {
			enemyTank.health--;
			playerTank.isShooted = false;
			playerTank.cBallLife = 0;
		}
	}
	if (enemyTank.isShooted && enemyTank.getBulletPos().intersects(playerTank.getTankPos())) {
		playerTank.health--;
		enemyTank.isShooted = false;
		enemyTank.cBallLife = 0;
	}
}

void ofApp::checkGameOver() {
	if (player1.health <= 0) {
		player1.health = 3;
		player2.health = 1;
		winner = &player2;
		game_state = "end";
	}
	else if (player2.health <= 0) {
		player1.health = 3;
		player2.health = 1;
		winner = &player1;
		game_state = "end";
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case '1':
		isDirOn = !isDirOn;
		break;
	case '2':
		isP1PontOn = !isP1PontOn;
		break;
	case '3':
		isP2PontOn = !isP2PontOn;
		break;
	case '4':
		isP1BulletPontOn = !isP1BulletPontOn;
		break;
	case '5':
		isP2BulletPontOn = !isP2BulletPontOn;
		break;
	case '6':
		isSpot1On = !isSpot1On;
		break;
	case '7':
		isSpot2On = !isSpot2On;
		break;
	case 'I':
	case 'i':
		if (lightFlags[0] == 1) lightFlags[0] = 0;
		else lightFlags[0] = 1;
		break;
	case 'o':
		if (lightFlags[1] == 1) lightFlags[1] = 0;
		else lightFlags[1] = 1;
		break;
	case 'P':
	case 'p':
		if (lightFlags[2] == 1) lightFlags[2] = 0;
		else lightFlags[2] = 1;
		break;
	case 'K':
	case 'k':
		if (lightFlags[3] == 1) lightFlags[3] = 0;
		else lightFlags[3] = 1;
		break;
	case 'l':
	case 'L':
		if (lightFlags[4] == 1) lightFlags[4] = 0;
		else lightFlags[4] = 1;
		break;
	case 'ç':
	case 'Ç':
		if (lightFlags[5] == 1) lightFlags[5] = 0;
		else lightFlags[5] = 1;
		break;
	case ',':
		if (lightFlags[6] == 1) lightFlags[6] = 0;
		else lightFlags[6] = 1;
		break;
	case '.':
		if (lightFlags[7] == 1) lightFlags[7] = 0;
		else lightFlags[7] = 1;
		break;
	case '-':
		if (lightFlags[8] == 1) lightFlags[8] = 0;
		else lightFlags[8] = 1;
		break;
	case 'g':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'f':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case OF_KEY_LEFT:
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_left_pressed = true;
		break;
	case OF_KEY_RIGHT:
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_right_pressed = true;
		break;
	case OF_KEY_UP:
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_up_pressed = true;
		break;
	case OF_KEY_DOWN:
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_down_pressed = true;
		break;
	case 'Q':
	case 'q' :
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_rotate_left = true;
		break;
	case 'W':
	case 'w':
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.is_rotate_right = true;
		break;
	case ' ':
		if (game_state != "start" && game_state != "end" && game_state != "info") player1.shoot();
		break;
	case 'M':
	case 'm':
		if (game_state == "end") {
			last_game_state = "end";
			game_state = "start";
		}
		else if (game_state != "start") {
			if (game_state == "2d") {
				last_game_state = "2d";
				game_state = "3d";
			}
			else if (game_state == "3d") {
				last_game_state = "3d";
				game_state = "fp";
			}
			else if (game_state == "fp") {
				last_game_state = "fp";
				game_state = "2d";
			}
			else if (game_state == "info") {
				last_game_state = "info";
				game_state = "start";
			}
		}
		else {
			last_game_state = "start";
			game_state = "2d";
		}
		break;
	case 'N':
	case 'n':
		if (game_state == "start") {
			last_game_state = "start";
			game_state = "info";
		}
		break;
	case 'D':
	case 'd':
		if (game_state == "start") {
			if (game_difficulty == "easy") {
				game_difficulty = "hard";
			}
			else {
				game_difficulty = "easy";
			}
		}
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (key) {
	case OF_KEY_LEFT:
		player1.is_left_pressed = false;
		break;
	case OF_KEY_RIGHT:
		player1.is_right_pressed = false;
		break;
	case OF_KEY_UP:
		player1.is_up_pressed = false;
		break;
	case OF_KEY_DOWN:
		player1.is_down_pressed = false;
		break;
	case 'Q':
	case 'q':
		player1.is_rotate_left = false;
		break;
	case 'W':
	case 'w':
		player1.is_rotate_right = false;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	cout << endl << x << " " << y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {


}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::Debug() {
	cout << "Direc Ambient" << lightFlags[0] << endl;
	cout << "Direc Diffuse" << lightFlags[1] << endl;
	cout << "Direc Spec" << lightFlags[2] << endl;
	cout << "Light 4" << lightFlags[3] << endl;
	cout << "Light 5" << lightFlags[4] << endl;
	cout << "Light 6" << lightFlags[5] << endl;
	cout << "Spot Ambient" << lightFlags[6] << endl;
	cout << "Spot Diffuse" << lightFlags[7] << endl;
	cout << "Spot Spec" << lightFlags[8] << endl;

}

void ofApp::exit() {
	floorTexture.clear();
}
