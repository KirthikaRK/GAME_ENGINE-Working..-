#pragma once
#ifndef Input_hpp
#define Input_hpp

#include<SFML/Graphics.hpp>
#include "Bitmask.hpp"

class Input
{
public:
    enum class Key
    {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };

    void Update();

	bool IsKeyPressed(Key keycode);
	bool IsKeyDown(Key keycode);
	bool IsKeyUp(Key keycode);
    

private:
    Bitmask thisFrameKeys; //Bitmask variable to store the keys status this frame
    Bitmask lastFrameKeys;//Bitmask variable to store the previous frames key status
    /*We store two frames worth of data so that we can determine if a key was just 
    released or pressed by checking its current status against last frames status*/
};
#endif