#include "UIImage.h"

#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"

#include "SDL/include/SDL_rect.h"

bool UIImage::PostUpdate()
{
	App->render->Blit(App->gui->GetAtlas(), pos.x, pos.y, &rect_spritesheet);

	return true;
}