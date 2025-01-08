#include "Lights.h"

Lights::Lights() {

	GLfloat spotTheta = 0;
	GLfloat spot2Theta = 0;

	setUpDirectionalLight();
	setUpPontualLights();
	setUpSpotLights();
}

void Lights::setUpDirectionalLight() {

	this->Position[0] = 0.0;
	this->Position[1] = 0.0;
	this->Position[2] = 1.;
	this->Position[3] = 0.;

	this->Ambient[0] = 0.;
	this->Ambient[1] = 0.;
	this->Ambient[2] = 0.;
	this->Ambient[3] = 1.;

	this->Difuse[0] = 0.1;
	this->Difuse[1] = 0.1;
	this->Difuse[2] = 0.1;
	this->Difuse[3] = 1.0;

	this->Specular[0] = 0.1;
	this->Specular[1] = 0.1;
	this->Specular[2] = 0.1;
	this->Specular[3] = 1.;
}

void Lights::setUpPontualLights() {

	// Player 1
	this->ponPostition[3] = 1.;

	this->ponAmbient[0] = 0.;
	this->ponAmbient[1] = 0.;
	this->ponAmbient[2] = 0.;
	this->ponAmbient[3] = 1.;

	this->ponDifuse[0] = 0.0;
	this->ponDifuse[1] = 1.0;
	this->ponDifuse[2] = 0.2;
	this->ponDifuse[3] = 1.0;

	this->ponSpecular[0] = 0.;
	this->ponSpecular[1] = 1.;
	this->ponSpecular[2] = 1.;
	this->ponSpecular[3] = 1.;

	// Player 2
	this->pon2Postition[3] = 1.;
	
	this->pon2Ambient[0] = 0.;
	this->pon2Ambient[1] = 0.;
	this->pon2Ambient[2] = 0.;
	this->pon2Ambient[3] = 1.;
	
	this->pon2Difuse[0] = 1.;
	this->pon2Difuse[1] = 0.0;
	this->pon2Difuse[2] = 0.2;
	this->pon2Difuse[3] = 1.0;

	this->pon2Specular[0] = 1.;
	this->pon2Specular[1] = 0.;
	this->pon2Specular[2] = 1.;
	this->pon2Specular[3] = 1.;

	// Player 1 bullet
	this->pon3Postition[3] = 1.;

	this->pon3Ambient[0] = 0.;
	this->pon3Ambient[1] = 0.;
	this->pon3Ambient[2] = 0.;
	this->pon3Ambient[3] = 1.;

	this->pon3Difuse[0] = 0.0;
	this->pon3Difuse[1] = 1.0;
	this->pon3Difuse[2] = 0.2;
	this->pon3Difuse[3] = 1.0;

	this->pon3Specular[0] = 0.;
	this->pon3Specular[1] = .5;
	this->pon3Specular[2] = .5;
	this->pon3Specular[3] = 1.;

	// Player 2 bullet
	this->pon4Postition[3] = 1.;

	this->pon4Ambient[0] = 0.;
	this->pon4Ambient[1] = 0.;
	this->pon4Ambient[2] = 0.;
	this->pon4Ambient[3] = 1.;

	this->pon4Difuse[0] = 1.0;
	this->pon4Difuse[1] = 0.0;
	this->pon4Difuse[2] = 0.2;
	this->pon4Difuse[3] = 1.0;

	this->pon4Specular[0] = .5;
	this->pon4Specular[1] = 0.;
	this->pon4Specular[2] = .5;
	this->pon4Specular[3] = 1.;
}

void Lights::setUpSpotLights() {
	
	// SpotLight Player 1

	this->spotPosition[0] = gw() * 0.5;
	this->spotPosition[1] = 0.;
	this->spotPosition[2] = 500.;
	this->spotPosition[3] = 1.;

	ofVec3f Aux = (ofVec3f(0, 0, 0) - ofVec3f(0, 0, 100)).normalize();

	this->spotDirection[0] = Aux.x;
	this->spotDirection[1] = Aux.y;
	this->spotDirection[2] = Aux.z;

	this->spotAmbient[0] = 0.7;
	this->spotAmbient[1] = 0.7;
	this->spotAmbient[2] = 0.1;
	this->spotAmbient[3] = 1.;

	this->spotDifuse[0] = 0.7;
	this->spotDifuse[1] = 0.7;
	this->spotDifuse[2] = 0.2;
	this->spotDifuse[3] = 1.0;

	this->spotSpecular[0] = 0.8;
	this->spotSpecular[1] = 0.8;
	this->spotSpecular[2] = 0.2;
	this->spotSpecular[3] = 1.;

	this->spotCutoff = 60;
	this->spotExponent = 30;

	this->spotAtC = 1.;
	this->spotAtL = 0.;
	this->spotAtQ = 0.;

	// Spotlight Player 2

	this->spot2Position[0] = -gw() * 0.5;
	this->spot2Position[1] = 0.;
	this->spot2Position[2] = 500.;
	this->spot2Position[3] = 1.;

	ofVec3f Aux2 = (ofVec3f(0, 0, 0) - ofVec3f(0, 0, 100)).normalize();

	this->spot2Direction[0] = Aux2.x;
	this->spot2Direction[1] = Aux2.y;
	this->spot2Direction[2] = Aux2.z;

	this->spot2Ambient[0] = 0.6;
	this->spot2Ambient[1] = 0.3;
	this->spot2Ambient[2] = 0.;
	this->spot2Ambient[3] = 1.;

	this->spot2Difuse[0] = 0.8;
	this->spot2Difuse[1] = 0.4;
	this->spot2Difuse[2] = 0.2;
	this->spot2Difuse[3] = 1.0;

	this->spot2Specular[0] = 0.6;
	this->spot2Specular[1] = 0.3;
	this->spot2Specular[2] = 0.1;
	this->spot2Specular[3] = 1.;

	this->spot2Cutoff = 60.0;
	this->spot2Exponent = 30;

	this->spot2AtC = 1.;
	this->spot2AtL = 0.;
	this->spot2AtQ = 0.;

}

void Lights::setLight(ofVec3f player1Pos, 
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
						int lightFlags[9]) {

	glEnable(GL_LIGHTING);//habilita o uso de ilumina��o
	glEnable(GL_NORMALIZE);//utiliza versores para normais (normais normalizadas)
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, false);

	// Difusal light
	glLightfv(GL_LIGHT0, GL_POSITION, this->Position);
	if (lightFlags[0]) glLightfv(GL_LIGHT0, GL_AMBIENT, this->Ambient); 
	else {
		GLfloat AmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientZero);
	}
	if (lightFlags[1]) glLightfv(GL_LIGHT0, GL_DIFFUSE, this->Difuse); 
	else {
		GLfloat DifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, DifuseZero);
	}
	if (lightFlags[2]) glLightfv(GL_LIGHT0, GL_SPECULAR, this->Specular);
	else {
		GLfloat SpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularZero);
	}

	// Player 1 Pontual light
	this->ponPostition[0] = player1Pos.x;
	this->ponPostition[1] = player1Pos.y;
	this->ponPostition[2] = player1Pos.z + 200;

	glLightfv(GL_LIGHT1, GL_POSITION, this->ponPostition);
	if (lightFlags[3]) glLightfv(GL_LIGHT1, GL_AMBIENT, this->ponAmbient);
	else {
		GLfloat ponAmbienteZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, ponAmbienteZero);
	}
	if (lightFlags[4]) glLightfv(GL_LIGHT1, GL_DIFFUSE, this->ponDifuse);
	else {
		GLfloat ponDifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_DIFFUSE, ponDifuseZero);
	}
	if (lightFlags[5]) glLightfv(GL_LIGHT1, GL_SPECULAR, this->ponSpecular);
	else {
		GLfloat ponSpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, ponSpecularZero);
	}

	// Player 2 Pontual light
	this->pon2Postition[0] = player2Pos.x;
	this->pon2Postition[1] = player2Pos.y;
	this->pon2Postition[2] = player2Pos.z + 200;

	glLightfv(GL_LIGHT2, GL_POSITION, this->pon2Postition);
	if (lightFlags[3]) glLightfv(GL_LIGHT2, GL_AMBIENT, this->pon2Ambient);
	else {		
		GLfloat pon2AmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, pon2AmbientZero);
	}
	if (lightFlags[4]) glLightfv(GL_LIGHT2, GL_DIFFUSE, this->pon2Difuse);
	else {
		GLfloat pon2DifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT2, GL_DIFFUSE, pon2DifuseZero);
	}
	if (lightFlags[5]) glLightfv(GL_LIGHT2, GL_SPECULAR, this->pon2Specular);
	else {
		GLfloat pon2SpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, pon2SpecularZero);
	}

	// Player 1 bullet Pontual light
	this->pon3Postition[0] = player1Bullet.x;
	this->pon3Postition[1] = player1Bullet.y;
	this->pon3Postition[2] = player1Bullet.z + 200;

	glLightfv(GL_LIGHT3, GL_POSITION, this->pon3Postition);
	if (lightFlags[3]) glLightfv(GL_LIGHT3, GL_AMBIENT, this->pon3Ambient);
	else {
		GLfloat pon3AmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, pon3AmbientZero);
	}
	if (lightFlags[4])glLightfv(GL_LIGHT3, GL_DIFFUSE, this->pon3Difuse);
	else {
		GLfloat pon3DifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT3, GL_DIFFUSE, pon3DifuseZero);
	}
	if (lightFlags[5]) glLightfv(GL_LIGHT3, GL_SPECULAR, this->pon3Specular);
	else {
		GLfloat pon3SpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, pon3SpecularZero);
	}

	// Player 2 bullet Pontual light
	this->pon4Postition[0] = player2Bullet.x;
	this->pon4Postition[1] = player2Bullet.y;
	this->pon4Postition[2] = player2Bullet.z + 200;

	glLightfv(GL_LIGHT4, GL_POSITION, this->pon4Postition);
	if (lightFlags[3]) glLightfv(GL_LIGHT4, GL_AMBIENT, this->pon4Ambient);
	else {
		GLfloat pon4AmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, pon4AmbientZero);
	}
	if (lightFlags[4]) glLightfv(GL_LIGHT4, GL_DIFFUSE, this->pon4Difuse);
	else {
		GLfloat pon4DifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT4, GL_DIFFUSE, pon4DifuseZero);
	}
	if (lightFlags[5]) glLightfv(GL_LIGHT4, GL_SPECULAR, this->pon4Specular);
	else {
		GLfloat pon4SpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, pon4SpecularZero);
	}

	// Spot light 1

	glLightfv(GL_LIGHT5, GL_POSITION, this->spotPosition);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, this->spotDirection);
	if (lightFlags[6]) glLightfv(GL_LIGHT5, GL_AMBIENT, this->spotAmbient);
	else {
		GLfloat spotAmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, spotAmbientZero);
	}
	if (lightFlags[7]) glLightfv(GL_LIGHT5, GL_DIFFUSE, this->spotDifuse);
	else {
		GLfloat spotDifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT5, GL_DIFFUSE, spotDifuseZero);
	}
	if (lightFlags[8]) glLightfv(GL_LIGHT5, GL_SPECULAR, this->spotSpecular);
	else {
		GLfloat spotSpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, spotSpecularZero);
	}
	
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, this->spotCutoff);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, this->spotExponent);

	glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, this->spotAtC);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, this->spotAtL);
	glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, this->spotAtQ);

	// Spot light 2

	glLightfv(GL_LIGHT6, GL_POSITION, this->spot2Position);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, this->spot2Direction);
	if (lightFlags[6]) glLightfv(GL_LIGHT6, GL_AMBIENT, this->spot2Ambient);
	else {
		GLfloat spot2AmbientZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_AMBIENT, spot2AmbientZero);
	}
	if (lightFlags[7]) glLightfv(GL_LIGHT6, GL_DIFFUSE, this->spot2Difuse);
	else {
		GLfloat spot2DifuseZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT6, GL_DIFFUSE, spot2DifuseZero);
	}
	if (lightFlags[8]) glLightfv(GL_LIGHT6, GL_SPECULAR, this->spot2Specular);
	else {
		GLfloat spot2SpecularZero[4] = { 0, 0, 0, 1 };
		glLightfv(GL_LIGHT1, GL_SPECULAR, spot2SpecularZero);
	}

	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, this->spot2Cutoff);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, this->spot2Exponent);

	glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, this->spot2AtC);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, this->spot2AtL);
	glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, this->spot2AtQ);


	// Enable lights
	
	if (isDirOn) { glEnable(GL_LIGHT0); }
	else { glDisable(GL_LIGHT0); }
	if (isP1PontOn) { glEnable(GL_LIGHT1); }
	else { glDisable(GL_LIGHT1); }
	if (isP2PontOn) { glEnable(GL_LIGHT2); }
	else { glDisable(GL_LIGHT2); }
	
	
	if (isP1BulletPontOn) { if (isShooted1) glEnable(GL_LIGHT3); else glDisable(GL_LIGHT3); }
	else { glDisable(GL_LIGHT3); }
	
	if (isP2BulletPontOn) { if (isShooted2) glEnable(GL_LIGHT4); else glDisable(GL_LIGHT4); }
	else { glDisable(GL_LIGHT4); }

	if (isSpot1On) glEnable(GL_LIGHT5);
	else glDisable(GL_LIGHT5);

	if (isSpot2On) glEnable(GL_LIGHT6);
	else glDisable(GL_LIGHT6);
}

//void Lights::lightComponents(int lightFlags[9]) {
//	if (!lightFlags[0]) {
//		this->Ambient = 0;
//		this->Difuse = 0;
//		this->Specular = 0;
//
//	} else { 
//		this->Ambient = ;
//
//	}
//}

void Lights::updateSpotLight() {


	float sx = gh() * 0.3 * cos(spotTheta * PI / 180.) + spotPosition[0];
	float sy = gh() * 0.3 * sin(spotTheta * PI / 180.) + spotPosition[1];
	spotDirection[0] = sx - spotPosition[0];
	spotDirection[1] = sy - spotPosition[1];
	spotDirection[2] = -spotPosition[2];
	spotTheta -= 1;

	float sx2 = gh() * 0.3 * cos(spot2Theta * PI / 180.) + spot2Position[0];
	float sy2 = gh() * 0.3 * sin(spot2Theta * PI / 180.) + spot2Position[1];
	spot2Direction[0] = sx2	- spot2Position[0];
	spot2Direction[1] = sy2 - spot2Position[1];
	spot2Direction[2] = -spot2Position[2];
	spot2Theta += 1;

	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, this->spotDirection);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, this->spot2Direction);
}

void Lights::disableLight() {glDisable(GL_LIGHTING);}