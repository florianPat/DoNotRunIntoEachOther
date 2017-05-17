#pragma once

#include "Graphics.h"
#include "Vec2.h"

class TileMap
{
public:
	enum class TYPE
	{
		BLANK,
		PLAYER1,
		PLAYER2
	};
private:
	static constexpr int width = 100, height = 75, tilesSize = 8;
	TYPE tileMap[width * height] = { TYPE::BLANK };

	Graphics& gfx;
public:
	TileMap(Graphics& gfx);
	void draw();
	void setTileTypeAtPos(TYPE type, Vec2& pos);
	TYPE getTileTypeAtPos(Vec2& pos);
};