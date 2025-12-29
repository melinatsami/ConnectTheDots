#include "sgg/graphics.h"
#include <stdio.h>
#include "util.h"
#include <string>
#include "GlobalState.h"


void init() {
	GlobalState::getInstance()->init();
}

void draw() { //dhmiourgei ta koutakia
	GlobalState::getInstance()->draw();
}

void update(float dt) { //kouniete to player
	GlobalState::getInstance()->update(dt);
}

int main(int argc, char** argv) {

	graphics::createWindow(800, 800, "Connect The Dots");

	init();

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(GlobalState::getInstance()->getCanvasWidth(),
		GlobalState::getInstance()->getCanvasHeight());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::startMessageLoop();
	return 0;
}