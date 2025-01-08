#include "Enemy.h"

Enemy::Enemy() : Tank() {
    decisionTimer = 0;
    decisionShoot = 0;
    decisionShootInterval = 1;
    decisionInterval = 0.1;
	this->playerType = 0;
    this->health = 1;
    this->speed = 0.25;
	pursueDistance = 500;
}

void Enemy::update(const Tank& playerTank) {
    decisionTimer += ofGetLastFrameTime();
    decisionShoot += ofGetLastFrameTime();
    if (decisionTimer >= decisionInterval) {
        chooseAction(playerTank);
        decisionTimer = 0;
    }

    Tank::update(false);
}

void Enemy::chooseAction(const Tank& playerTank) {
    ofVec3f directionToPlayer = playerTank.basePos - this->basePos;
    float distanceToPlayer = directionToPlayer.length();

    if (distanceToPlayer > pursueDistance) {
        is_up_pressed = directionToPlayer.y > 0;
        is_down_pressed = directionToPlayer.y < 0;
        is_left_pressed = directionToPlayer.x < 0;
        is_right_pressed = directionToPlayer.x > 0;

    }
    else {
        is_left_pressed = is_right_pressed = is_up_pressed = is_down_pressed = false;
    }

    float targetAngle = atan2(directionToPlayer.y, directionToPlayer.x) * 180 / PI;
    float angleDiff = targetAngle - rotatorAngle;

    // Ajustar o ângulo para estar entre -180 e 180 graus
    if (angleDiff > 180) angleDiff -= 360;
    if (angleDiff < -180) angleDiff += 360;

    float rotationSpeed = 10;
    if (abs(angleDiff) > rotationSpeed) {

        if (angleDiff > 0) {
            rotatorAngle += rotationSpeed;
        }
        else {
            rotatorAngle -= rotationSpeed;
        }
    }
    else {
        rotatorAngle = targetAngle;
    }


    if (decisionShoot >= decisionShootInterval) {
        shoot();
        decisionShoot = 0;
    }
}

// 0 = easy, 1 = hard
void Enemy::difficulty(int difficulty) {
	if (difficulty) {
		this->speed = 0.75;
		this->decisionInterval = 0.05;
		this->decisionShootInterval = 0.5;
		pursueDistance = 300;
	}
	else {
		this->speed = 0.25;
		this->decisionInterval = 0.1;
		this->decisionShootInterval = 1;
		pursueDistance = 500;
    }
}

void Enemy::beginMaterials(int material) { loadMaterial(material); }