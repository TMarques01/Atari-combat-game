#ifndef MATERIALS_H
#define MATERIALS_H
#include "ofMain.h"

#define NUM_MAT 18

inline extern string Materiais[] = {
	"Esmerald",  "Jade",  "obsidian",    "Pearl",        "Ruby",
	"Turquoise", "Brass", "Bronze",      "Chrome",       "Copper",
	"Gold",      "Silver","blackPlastic","cyankPlastic", "greenPlastic",
	"redPlastic", "whitePlastic","yellowPlastic" };


inline void loadMaterial(int material) {

	GLfloat  esmeraldAmb[] = { 0.0215 ,0.1745 ,0.0215, 1. };
	GLfloat  esmeraldDif[] = { 0.07568 ,0.61424 ,0.07568, 1. };
	GLfloat  esmeraldSpec[] = { 0.633 ,0.727811 ,0.633, 1. };
	GLint    esmeraldCoef = 0.6 * 128;

	GLfloat  jadeAmb[] = { 0.135 ,0.2225 ,0.1575, 1. };
	GLfloat  jadeDif[] = { 0.54 ,0.89 ,0.63, 1. };
	GLfloat  jadeSpec[] = { 0.316228 ,0.316228 ,0.316228, 1. };
	GLint   jadeCoef = 0.1 * 128;

	GLfloat  obsidianAmb[] = { 0.05375 ,0.05 ,0.06625, 1. };
	GLfloat  obsidianDif[] = { 0.18275 ,0.17 ,0.22525, 1. };
	GLfloat  obsidianSpec[] = { 0.332741 ,0.328634 ,0.346435, 1. };
	GLint  obsidianCoef = 0.6 * 128;

	GLfloat  pearlAmb[] = { 0.25 ,0.20725 ,0.20725, 1. };
	GLfloat  pearlDif[] = { 1.0 ,0.829 ,0.829, 1. };
	GLfloat  pearlSpec[] = { 0.296648 ,0.296648 ,0.296648, 1. };
	GLint  pearlCoef = 0.088 * 128;

	GLfloat  rubyAmb[] = { 0.1745 ,0.01175 ,0.01175, 1. };
	GLfloat  rubyDif[] = { 0.61424 ,0.04136 ,0.04136, 1. };
	GLfloat  rubySpec[] = { 0.727811 ,0.626959 ,0.626959, 1. };
	GLint  rubyCoef = 0.6 * 128;

	GLfloat  turquoiseAmb[] = { 0.1 ,0.18725 ,0.1745, 1. };
	GLfloat  turquoiseDif[] = { 0.396 ,0.74151 ,0.40102, 1. };
	GLfloat  turquoiseSpec[] = { 0.297254 ,0.60829 ,0.306678, 1. };
	GLint  turquoiseCoef = 0.6 * 128;

	GLfloat  brassAmb[] = { 0.329412 ,0.223529 ,0.027451, 1. };
	GLfloat  brassDif[] = { 0.780392 ,0.568627 ,0.113725, 1. };
	GLfloat  brassSpec[] = { 0.992157 ,0.941176 ,0.807843, 1. };
	GLint  brassCoef = 0.21794872 * 128;

	GLfloat  bronzeAmb[] = { 0.2125 ,0.1275 ,0.054, 1. };
	GLfloat  bronzeDif[] = { 0.714 ,0.4284 ,0.18144, 1. };
	GLfloat  bronzeSpec[] = { 0.393548 ,0.271906 ,0.166721, 1. };
	GLint  bronzeCoef = 0.2 * 128;

	GLfloat  chromeAmb[] = { 0.25 ,0.25 ,0.25, 1. };
	GLfloat  chromeDif[] = { 0.4 ,0.4 ,0.4, 1. };
	GLfloat  chromeSpec[] = { 0.774597 ,0.774597 ,0.774597, 1. };
	GLint  chromeCoef = 0.6 * 128;

	GLfloat  copperAmb[] = { 0.19125 ,0.0735 ,0.0225, 1. };
	GLfloat  copperDif[] = { 0.7038 ,0.27048 ,0.0828, 1. };
	GLfloat  copperSpec[] = { 0.256777 ,0.137622 ,0.086014, 1. };
	GLint  copperCoef = 0.1 * 128;

	GLfloat  goldAmb[] = { 0.24725 ,0.1995 ,0.0745, 1. };
	GLfloat  goldDif[] = { 0.75164 ,0.60648 ,0.22648, 1. };
	GLfloat  goldSpec[] = { 0.628281 ,0.555802 ,0.366065, 1. };
	GLint  goldCoef = 0.4 * 128;

	GLfloat  silverAmb[] = { 0.19225 ,0.19225 ,0.19225, 1. };
	GLfloat  silverDif[] = { 0.50754 ,0.50754 ,0.50754, 1. };
	GLfloat  silverSpec[] = { 0.508273 ,0.508273 ,0.508273, 1. };
	GLint  silverCoef = 0.4 * 128;

	GLfloat blackPlasticAmb[] = { 0.0 ,0.0 ,0.0, 1. };
	GLfloat blackPlasticDif[] = { 0.00 ,0.00 ,0.00, 1. };
	GLfloat blackPlasticSpec[] = { 0.0 ,0.00 ,0.0, 1. };
	GLint blackPlasticCoef = 0.25 * 128;

	GLfloat  cyanPlasticAmb[] = { 0.0 ,0.1 ,0.06, 1. };
	GLfloat  cyanPlasticDif[] = { 0.0 ,0.50980392 ,0.50980392, 1. };
	GLfloat  cyanPlasticSpec[] = { 0.0 ,0.50196078 ,0.50196078, 1. };
	GLint  cyanPlasticCoef = 0.25 * 128;

	GLfloat greenPlasticAmb[] = { 0.0 ,0.2 ,0.0, 1. };
	GLfloat greenPlasticDif[] = { 0.0 ,0.35 ,0.0, 1. };
	GLfloat greenPlasticSpec[] = { 0.0 ,0.55 ,0.0, 1. };
	GLint greenPlasticCoef = 0.25 * 128;

	GLfloat  redPlasticAmb[] = { 0.2 ,0.0 ,0.0, 1. };
	GLfloat  redPlasticDif[] = { 0.5 ,0.0 ,0.0, 1. };
	GLfloat  redPlasticSpec[] = { 0.7 ,0.0 ,0.0, 1. };
	GLint  redPlasticCoef = 0.25 * 128;

	GLfloat whitePlasticAmb[] = { 0.8 ,0.8 ,0.8, 1. };
	GLfloat whitePlasticDif[] = { 0.55 ,0.55 ,0.55, 1. };
	GLfloat whitePlasticSpec[] = { 0.870 ,0.870 ,0.870, 1. };
	GLint whitePlasticCoef = 0.25 * 128;

	GLfloat yellowPlasticAmb[] = { 0.2 ,0.2 ,0.0, 1. };
	GLfloat yellowPlasticDif[] = { 0.5 ,0.5 ,0.0, 1. };
	GLfloat yellowPlasticSpec[] = { 0.60 ,0.60 ,0.00, 1. };
	GLint yellowPlasticCoef = 0.25 * 128;

	GLfloat costumAmb[] = { 0.2 ,0.2 ,0.0, 1. };
	GLfloat costumDif[] = { 0.5 ,0.5 ,0.0, 1. };
	GLfloat costumSpec[] = { 0.60 ,0.60 ,0.00, 1. };
	GLint costumCoef = 0.25 * 128;


	switch (material) {
	case 0: //……………………………………………………………………………………………esmerald
		glMaterialfv(GL_FRONT, GL_AMBIENT, esmeraldAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, esmeraldDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, esmeraldSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, esmeraldCoef);
		break;
	case 1: //……………………………………………………………………………………………jade
		glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
		break;
	case 2: //……………………………………………………………………………………………obsidian
		glMaterialfv(GL_FRONT, GL_AMBIENT, obsidianAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, obsidianDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, obsidianSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, obsidianCoef);
		break;
	case 3: //……………………………………………………………………………………………pearl
		glMaterialfv(GL_FRONT, GL_AMBIENT, pearlAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pearlDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, pearlSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, pearlCoef);
		break;
	case 4: //……………………………………………………………………………………………ruby
		glMaterialfv(GL_FRONT, GL_AMBIENT, rubyAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, rubyDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, rubySpec);
		glMaterialf(GL_FRONT, GL_SHININESS, rubyCoef);
		break;
	case 5: //……………………………………………………………………………………………turquoise
		glMaterialfv(GL_FRONT, GL_AMBIENT, turquoiseAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, turquoiseDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, turquoiseSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, turquoiseCoef);
		break;
	case 6: //……………………………………………………………………………………………brass
		glMaterialfv(GL_FRONT, GL_AMBIENT, brassAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, brassDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, brassSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, brassCoef);
		break;
	case 7: //……………………………………………………………………………………………bronze
		glMaterialfv(GL_FRONT, GL_AMBIENT, bronzeAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, bronzeDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, bronzeSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, bronzeCoef);
		break;
	case 8: //……………………………………………………………………………………………chrome
		glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, chromeSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, chromeCoef);
		break;
	case 9: //……………………………………………………………………………………………copper
		glMaterialfv(GL_FRONT, GL_AMBIENT, copperAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, copperDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, copperSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, copperCoef);
		break;
	case 10: //……………………………………………………………………………………………gold
		glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
		break;
	case 11: //……………………………………………………………………………………………silver
		glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
		break;
	case 12: //……………………………………………………………………………………………blackPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
		break;
	case 13: //……………………………………………………………………………………………cyankPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, cyanPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, cyanPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, cyanPlasticCoef);
		break;
	case 14: //……………………………………………………………………………………………greenPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, greenPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, greenPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, greenPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, greenPlasticCoef);
		break;
	case 15: //……………………………………………………………………………………………redPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
		break;
	case 16: //……………………………………………………………………………………………yellowPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, whitePlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, whitePlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, whitePlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, whitePlasticCoef);
		break;
	case 17: //……………………………………………………………………………………………yellowPlastic
		glMaterialfv(GL_FRONT, GL_AMBIENT, yellowPlasticAmb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowPlasticDif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, yellowPlasticSpec);
		glMaterialf(GL_FRONT, GL_SHININESS, yellowPlasticCoef);
		break;
	}

}

#endif