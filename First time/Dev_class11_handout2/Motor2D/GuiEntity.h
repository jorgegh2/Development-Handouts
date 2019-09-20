#ifndef __GUIENTITY_H__
#define __GUIENTITY_H__

#include "SDL/include/SDL_rect.h"
#include "p2Point.h"
class SDL_Texture;

enum TYPE{
	NO_TYPE = 0,
	IMAGE,
	TEXT
};

class GuiEntity
{
protected:
	iPoint position;
	SDL_Rect Image;
	TYPE type = NO_TYPE;
	
public:
	void Draw(SDL_Texture* atlas) const;
	bool Update();

};

#endif
