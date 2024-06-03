#include "Game.hpp"

Game::Game():window("that Game Engine")
{
	
	//vikingTexture.loadFromFile(workingDir.Get() + "viking.png");   	
	//vikingSprite.setTexture(vikingTexture);
	std::shared_ptr<SceneSplashScreen> splashScreen =
		std::make_shared<SceneSplashScreen>(workingDir,sceneStateMachine,window); 

	std::shared_ptr<SceneGame> gameScene =
		std::make_shared<SceneGame>(workingDir);

	unsigned int splashScreenID = sceneStateMachine.Add(splashScreen); 
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	splashScreen->SetSwitchToScene(gameSceneID); 

	sceneStateMachine.SwitchTo(splashScreenID);

	deltaTime = clock.restart().asSeconds();
}
/*void Game::CalculateDeltaTime()
{
	
}*/
void Game::ProcessInput()
{
	sceneStateMachine.ProcessInput();
}
void Game::Update() {
	window.Update();
	/*const sf::Vector2f& spritePos = vikingSprite.getPosition();
	//vikingSprite.setPosition(spritePos.x+1 , spritePos.y);
	//const int pixelsToMovePerSec = 100;//how many pixels we want our sprite to move in one second
	//const float frameMovement = pixelsToMovePerSec * deltaTime;
	//vikingSprite.setPosition(spritePos.x + frameMovement, spritePos.y);
	const int moveSpeed = 100;

	int xMove = 0;
	if (input.IsKeyPressed(Input::Key::Left))
	{
		xMove = -moveSpeed;
	}
	else if (input.IsKeyPressed(Input::Key::Right))
	{
		xMove = moveSpeed;
	}
	int yMove = 0;
	if (input.IsKeyPressed(Input::Key::Up))
	{
		yMove = -moveSpeed;
	}
	else if (input.IsKeyPressed(Input::Key::Down))
	{
		yMove = moveSpeed;
	}
	float xFrameMove = xMove * deltaTime; 
	float yFrameMove = yMove * deltaTime;

	vikingSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);*/
	sceneStateMachine.Update(deltaTime);
}

void Game::LateUpdate() {
	sceneStateMachine.LateUpdate(deltaTime);
}
void Game::Draw() {
	window.BeginDraw();

	sceneStateMachine.Draw(window);

	window.EndDraw();
}

void Game::CalculateDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

bool Game::IsRunning() const
{
	return window.IsOpen();
}

/*void Game::CaptureInput()
{
	input.Update();
}*/
