#pragma once

#include "ofMain.h"	
#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "cg_cam_extras.h"
#include "Tank.h"


class Enemy : public Tank {
public:
    Enemy();
    void update(const Tank& playerTank);
	void difficulty(int difficulty);
	void beginMaterials(int material);
private:
    void chooseAction(const Tank& playerTank);
    float decisionTimer;
    float decisionInterval;
    float pursueDistance;
    float decisionShoot;
    float decisionShootInterval;
};