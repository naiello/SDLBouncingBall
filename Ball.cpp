/*
 * Ball.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: naiello
 */

#include "Ball.h"

Ball::Ball(SDL_Renderer* ren)
{
	tex = NULL;
	renderer = ren;
	loadTexture("ball.png");
	carried = false;

	pos.x = 300;
	pos.y = 300;
	vel.x = 0;
	vel.y = 0;
}

Ball::~Ball()
{
	if (tex)
	{
		SDL_DestroyTexture(tex);
		tex = NULL;
	}
}

void Ball::loadTexture(string fname)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* surf = IMG_Load(fname.c_str());

	texture = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	tex = texture;
}

void Ball::update(Uint32 time)
{
	double secs = time / 1000.;
	if (carried)
	{
		int mx, my;
		SDL_GetMouseState(&mx, &my);
		pos.x = mx;
		pos.y = my;
		vel.x = 0;
		vel.y = 0;
	}
	else
	{
		pos.x += vel.x * secs;
		pos.y += vel.y * secs;
		vel.y += GRAVITY * secs;

		if (pos.y > (480 - BALL_R))
		{
			vel.y = -vel.y * BOUNCE_COEFF;
			pos.y -= 10;
		}
	}
}

void Ball::draw()
{
	SDL_Rect dest;
	dest.x = pos.x - BALL_R;
	dest.y = pos.y - BALL_R;
	dest.w = BALL_R * 2;
	dest.h = BALL_R * 2;
	SDL_RenderCopy(renderer, tex, NULL, &dest);
}

void Ball::handleEvent(SDL_Event& e)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	if ((e.type == SDL_MOUSEBUTTONDOWN) && (mx > (pos.x - BALL_R)) && (mx < (pos.x + BALL_R))
			&& (my > (pos.y - BALL_R)) && (my < (pos.y + BALL_R)))
	{
		carried = true;
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		carried = false;
	}
}
