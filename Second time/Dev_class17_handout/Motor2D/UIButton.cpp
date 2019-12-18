#include "UIButton.h"

UIButton::UIButton(UIType _type, iPoint pos, SDL_Rect rect_spritesheet) : UIObject(pos, rect_spritesheet)
{
	type = _type; 

}