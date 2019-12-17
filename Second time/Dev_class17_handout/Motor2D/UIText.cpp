#include "UIText.h"

#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"

bool UIText::PostUpdate(SDL_Texture* atlas) //don't use the atlas in text. Override the function and use their own texture.
{
	App->render->Blit(texture_text, pos.x, pos.y, &rect_spritesheet);

	return true;
}