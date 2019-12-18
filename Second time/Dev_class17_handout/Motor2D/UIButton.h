#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include "UIImage.h";
#include "UIText.h"
class UIButton : public UIObject
{
public:
	UIButton(UIType _type, iPoint pos, SDL_Rect rect_spritesheet);

public:
	UIImage* background;
	UIText* text;

};

#endif // !__UIIMAGE_H__
