#include "Engine.h";

bool collision() {
	const auto entities = getEntities();
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		Entity entity = **it;
		
	}

	return false;
}

void update() {
	collision();
}
