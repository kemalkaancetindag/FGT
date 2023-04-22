#include "Core/Engine.h"

int main(int argv, char* argc[]) {

	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning()) {
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
	}

	Engine::GetInstance()->Clean();


	return 0;
}