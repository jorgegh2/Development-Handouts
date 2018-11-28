#ifndef __ENEMY_FLY_H__
#define __ENEMY_FLY_H__

#include "GuiEntity.h"

class GuiImage : public GuiEntity
{
private:
	
public:
	GuiImage(int x, int y, SDL_Rect Image_rect);
	~GuiImage();

};

#endif
