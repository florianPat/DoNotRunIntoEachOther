#include "Player.h"
#include <assert.h>

Player::Player(Vec2 pos, Keyboard & kbd, TileMap& tileMap, int id, char leftMove, char rightMove, char topMove, char bottomMove) : pos(pos),
	kbd(kbd), tileMap(tileMap), id(id), leftMove(leftMove), rightMove(rightMove), topMove(topMove), bottomMove(bottomMove),
	lastMovet(1.0f, 0.0f), lastPos(pos.x - 1, pos.y - 1)
{
}

bool Player::update(float dt)
{
	bool resultIsColliding = false;

	if (kbd.KeyIsPressed(leftMove))
	{
		pos.x -= speed * dt;
		lastMovet = Vec2(-1.0f, 0.0f);
	}
	else if (kbd.KeyIsPressed(rightMove))
	{
		pos.x += speed * dt;
		lastMovet = Vec2(1.0f, 0.0f);
	}
	else if (kbd.KeyIsPressed(topMove))
	{
		pos.y -= speed * dt;
		lastMovet = Vec2(0.0f, -1.0f);
	}
	else if (kbd.KeyIsPressed(bottomMove))
	{
		pos.y += speed * dt;
		lastMovet = Vec2(0.0f, 1.0f);
	}
	else
	{
		if(lastMovet.x > 0)
			pos.x += speed * dt;
		else if(lastMovet.x < 0)
			pos.x -= speed * dt;
		else if(lastMovet.y > 0)
			pos.y += speed * dt;
		else if(lastMovet.y < 0)
			pos.y -= speed * dt;
	}

	if (pos.x < 0 || pos.x > 100 || pos.y < 0 || pos.y > 80) //TODO: Make these getters if TileMap
		return true;
	
	if ((int)lastPos.x != (int)pos.x || (int)lastPos.y != (int)pos.y) //TODO: Make these operator overloads of Vec2
	{
		if (tileMap.getTileTypeAtPos(pos) == TileMap::TYPE::BLANK)
		{
			tileMap.setTileTypeAtPos(id ? TileMap::TYPE::PLAYER2 : TileMap::TYPE::PLAYER1, pos);
		}
		else
			resultIsColliding = true;
	}

	lastPos = pos;

	return resultIsColliding;
}