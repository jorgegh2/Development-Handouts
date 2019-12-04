#ifndef __UIENTITY_H__
#define __UIENTITY_H__

#include "p2Point.h"
#include "SDL/include/SDL_rect.h"
#include "j1Textures.h"

class SDL_Texture;


enum class UIType
{
	NONE = -1,
	IMAGE,
	TEXT
};

class UIObject
{
public:
	UIObject(iPoint pos, SDL_Rect rect_spritesheet);
	virtual bool PreUpdate() { return true; }
	virtual bool Update(float dt) { return true; }
	virtual bool PostUpdate() { return true; }

public:
	UIType type = UIType::NONE;
	iPoint pos;
	SDL_Rect rect_spritesheet;

};

#endif // !__UIENTITY_H__

