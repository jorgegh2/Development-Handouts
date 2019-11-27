#include "UIImage.h"

#include "j1App.h"
#include "j1Render.h"

#include "SDL/include/SDL_rect.h"

bool UIImage::PostUpdate()
{
	App->render->Blit(text, pos.x, pos.y, &rect);
}