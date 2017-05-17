#include "TileMap.h"

TileMap::TileMap(Graphics & gfx) : gfx(gfx)
{
}

void TileMap::draw()
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Color color;
			Vec2 pos(x * tilesSize, y * tilesSize);

			switch (tileMap[x + y * width])
			{
				case TYPE::BLANK:
				{
					color = Colors::Black;
				}	break;
				case TYPE::PLAYER1:
				{
					color = Colors::Green;
				}	break;
				case TYPE::PLAYER2:
				{
					color = Colors::Blue;
				}	break;
			}

			gfx.DrawRect(pos.x, pos.y, pos.x + tilesSize, pos.y + tilesSize, color);
		}
	}
}

void TileMap::setTileTypeAtPos(TYPE type, Vec2 & pos)
{
	tileMap[pos.x + pos.y * width] = type;
}

TileMap::TYPE TileMap::getTileTypeAtPos(Vec2 & pos)
{
	return tileMap[pos.x + pos.y * width];
}
