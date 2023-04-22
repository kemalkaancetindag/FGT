#include "Engine.h"
#include "../Graphics/TextureManager.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initilaize SDL: %s", SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow("Softengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (m_Window == nullptr) {
		SDL_Log("Failed to create Window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create Renderer: %s", SDL_GetError());
		return false;
	}


	TextureManager::GetInstance()->Load("test", "assets/test.png");
	

	return m_IsRunning = true;



}

bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	IMG_Quit();
	SDL_Quit();
	return true;
}


void Engine::Quit() {
	

	m_IsRunning = false;
}

void Engine::Update() {
	
}

void Engine::Render() {
	SDL_RenderClear(m_Renderer);
	TextureManager::GetInstance()->Draw("test", 0, 0, 32, 32, SDL_FLIP_NONE);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		Quit();
	break;
	}

}