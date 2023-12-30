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

static void initSprites() {
	size_t numImages = C2D_SpriteSheetCount(spriteSheet);
	srand(time(NULL));

	for (size_t i = 0; i < MAX_SPRITES; i++) {
		Sprite *sprite = &sprites[i];

		// Random image, position, rotation and speed
		C2D_SpriteFromSheet(&sprite->spr, spriteSheet, rand() % numImages);
		C2D_SpriteSetCenter(&sprite->spr, 0.5f, 0.5f);
		C2D_SpriteSetPos(&sprite->spr, rand() % SCREEN_WIDTH,
										 rand() % SCREEN_HEIGHT);
		C2D_SpriteSetRotation(&sprite->spr, C3D_Angle(rand() / (float)RAND_MAX));
		sprite->dx = rand() * 4.0f / RAND_MAX - 2.0f;
		sprite->dy = rand() * 4.0f / RAND_MAX - 2.0f;
	}
}