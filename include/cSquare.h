//////////////////////////////////////////////////////////////////////////////////
// cSquare.h
// - represents an individual square in Falling Blocks
//////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <citro2d.h>
#include <citro3d.h>
#include "Enums.h"
#include "Defines.h"


struct R {
	int x, y, width, height;
};

class cSquare
{
private:
	// Location of the center of the square
	int m_CenterX;
	int m_CenterY;

	// Type of block. Needed to locate the correct square in our bitmap
	BlockType m_BlockType;

	// Definitions for colors
	u32 clrBlue = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);
	u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	u32 clrRed = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
	u32 clrYellow = C2D_Color32(0xFF, 0xFF, 0x00, 0xFF);
	u32 clrPurple = C2D_Color32(0x7F, 0x00, 0xFF24, 0xFF);
	u32 clrOrange = C2D_Color32(0xFF, 0x6A, 0x00, 0xFF);
	u32 clrLightBlue = C2D_Color32(0x00, 0xFF, 0xFF, 0xFF);

public:
	// Default constructor, your compiler will probably require this
	cSquare()
	{
	}

	// Main constructor takes location and type of block,
	// and pointer to our bitmap surface.
	cSquare(int x, int y, BlockType type) : m_CenterX(x), m_CenterY(y), m_BlockType(type)
	{
	}

	// Draw() takes a pointer to the surface to draw to (our window)
	void Draw()
	{
        R destination = { m_CenterX - SQUARE_MEDIAN, m_CenterY - SQUARE_MEDIAN, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2 };

		switch (m_BlockType)
		{
		case SQUARE_BLOCK:
			{
				drawImage(GFX_TOP, block_yellow_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case T_BLOCK:
			{
				drawImage(GFX_TOP, block_purple_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case L_BLOCK:
			{
				drawImage(GFX_TOP, block_blue_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case BACKWARDS_L_BLOCK:
			{
				drawImage(GFX_TOP, block_orange_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case STRAIGHT_BLOCK:
			{
				drawImage(GFX_TOP, block_lightblue_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case S_BLOCK:
			{
				drawImage(GFX_TOP, block_green_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		case BACKWARDS_S_BLOCK:
			{
				drawImage(GFX_TOP, block_red_bgr, SQUARE_MEDIAN * 2, SQUARE_MEDIAN * 2, destination.x - destination.width/2, destination.y);
			} break;
		}
	}

	// Remember, SQUARE_MEDIAN represents the distance from the square's center to
	// its sides. SQUARE_MEDIAN*2 gives us the width and height of our squares.
	void Move(Direction dir)
	{
		switch (dir)
		{
		case LEFT:
			{
				m_CenterX -= SQUARE_MEDIAN * 2;
			} break;
		case RIGHT:
			{
				m_CenterX += SQUARE_MEDIAN * 2;
			} break;
		case DOWN:
			{
				m_CenterY += SQUARE_MEDIAN*2;
			} break;
		}
	}

	// Accessors
	int GetCenterX() { return m_CenterX; }
	int GetCenterY() { return m_CenterY; }

	// Mutators
	void SetCenterX(int x) { m_CenterX = x; }
	void SetCenterY(int y) { m_CenterY = y; }
};