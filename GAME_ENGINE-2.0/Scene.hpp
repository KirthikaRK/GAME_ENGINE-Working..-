#pragma once
#ifndef Scene_hpp
#define Scene_hpp

#include "Window.hpp"

class Scene
{
public:
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnActivate() {};
	virtual void OnDeactivate() {};

	// The below functions can be overridden as necessary in our scenes.
	virtual void ProcessInput() {};
	virtual void Update(float deltaTime) {};
	virtual void LateUpdate(float deltaTime) {};
	virtual void Draw(Window& window) {};
};
#endif

