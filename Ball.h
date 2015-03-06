/*
 * Ball.h
 *
 *  Created on: Mar 4, 2015
 *      Author: naiello
 */

#ifndef BALL_H_
#define BALL_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Geom.h"

#define BALL_R 32
#define GRAVITY 400.0
#define BOUNCE_COEFF 0.9

using namespace std;

class Ball
{
public:
	Ball(SDL_Renderer*);
	virtual ~Ball();

	void update(Uint32);
	void draw();
	void handleEvent(SDL_Event&);

private:
	SDL_Texture* tex;
	SDL_Renderer* renderer;
	Vector2 pos, vel;
	bool carried;

	void loadTexture(string);
};

#endif /* BALL_H_ */
