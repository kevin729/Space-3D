#include "Engine.h";
#include <iostream>;

bool collision() {
	const auto entities = getEntities();
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		Entity entity = **it;
		
	}

	return false;
}

void updateKeyboard(Keyboard& keyboard) {
	keyboard.UP = keyboard.keys['W'];
	keyboard.DOWN = keyboard.keys['S'];
	keyboard.LEFT = keyboard.keys['A'];
	keyboard.RIGHT = keyboard.keys['D'];
}

void update() {
	collision();
}

void updatePlayer(Entity& player, Keyboard& keyboard) {
	updateKeyboard(keyboard);

	if (keyboard.UP) {
		player.rotation[2] = 0;
		player.y += 0.01;
	}

	if (keyboard.DOWN) {
		player.rotation[2] = 180;
		player.y -= 0.01;
	}

	if (keyboard.LEFT) {
		player.rotation[2] = 90;
		player.x -= 0.01;
	}

	if (keyboard.RIGHT) {
		player.rotation[2] = 270;
		player.x += 0.01;
	}
}
