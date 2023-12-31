#include <3ds.h>
#include <citro2d.h>
#include <citro3d.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <inttypes.h>

#define MAX_SPRITES 768
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240

// Simple sprite struct
typedef struct {
	C2D_Sprite spr;
	float dx, dy; // velocity
} Sprite;

static C2D_SpriteSheet spriteSheet;
static Sprite sprites[MAX_SPRITES];
static size_t numSprites = MAX_SPRITES / 2;

typedef enum {
	NONE,
  SQUARE_BLOCK,
  T_BLOCK,
  L_BLOCK,
  BACKWARDS_L_BLOCK,
  STRAIGHT_BLOCK,
  S_BLOCK,
  BACKWARDS_S_BLOCK
} BlockType;

enum Direction { LEFT, RIGHT, DOWN };

static BlockType board[12][10];

void initBackground() {
	
}