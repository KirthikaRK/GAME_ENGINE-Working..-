#pragma once
#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp
using namespace std;

#include <memory>
#include <unordered_map>

#include "Scene.hpp"
#include "Window.hpp"
class SceneStateMachine
{
public:
	SceneStateMachine();
	
	virtual void ProcessInput();
	virtual void Update(float deltaTime);
	virtual void LateUpdate(float deltaTime);
	virtual void Draw(Window& window);

	unsigned int Add(shared_ptr<Scene> scene);
	void SwitchTo(unsigned int id);
	void Remove(unsigned int id);

private:
	unordered_map<unsigned int, shared_ptr<Scene>> scenes;
	shared_ptr<Scene> curScene;
	unsigned int insertedSceneId;
};
#endif
