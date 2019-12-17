#include "UIObject.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"


UIObject::UIObject(iPoint pos, SDL_Rect rect_spritesheet) : pos(pos), rect_spritesheet(rect_spritesheet) {}

bool UIObject::PostUpdate(SDL_Texture* atlas)
{
	App->render->Blit(atlas, pos.x, pos.y, &rect_spritesheet);

	return true;
}