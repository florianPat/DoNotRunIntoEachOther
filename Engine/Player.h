#pragma once

#include "TileMap.h"
#include "Keyboard.h"
#include "Vec2.h"

class Player
{
	Vec2 pos;
	static constexpr int speed = 10;
	char leftMove, rightMove, topMove, bottomMove;
	Keyboard& kbd;

	int id;

	Vec2 lastMovet;
	Vec2 lastPos;

	TileMap& tileMap;
public:
	Player(Vec2 pos, Keyboard& kbd, TileMap& tileMap, int id, char leftMove, char rightMove, char topMove, char bottomMove);
	bool update(float dt);
};