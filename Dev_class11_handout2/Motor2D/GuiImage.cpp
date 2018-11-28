#include "GuiImage.h"

GuiImage::GuiImage(int x, int y, SDL_Rect Image_rect) 
{
	position = { x,y };
	Image = Image_rect;
}

GuiImage::~GuiImage()
{}


