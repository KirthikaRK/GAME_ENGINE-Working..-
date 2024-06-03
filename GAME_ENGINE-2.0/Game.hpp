#pragma once
#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "WorkingDirectory.hpp"
#include "Input.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp" 
#include "SceneGame.hpp" 

class Game {
public:
	Game();

	void ProcessInput();
	void Update();
	void LateUpdate();
	void Draw();
	bool IsRunning()const;
	void CalculateDeltaTime();
	//void CaptureInput();

private:
	Window window;
	WorkingDirectory workingDir;
	sf::Texture vikingTexture;
	sf::Sprite vikingSprite;
	sf::Clock clock;
	float deltaTime;
	//Input input;

	SceneStateMachine sceneStateMachine;
};
#endif 