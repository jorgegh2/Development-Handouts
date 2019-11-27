#ifndef __UIENTITY_H__
#define __UIENTITY_H__

class SDL_Rect;
class iPoint;
class SDL_Texture;

class UIObject
{
public:
	virtual bool PreUpdate() { return true; }
	virtual bool Update(float dt) { return true; }
	virtual bool PostUpdate() { return true; }

public:
	SDL_Texture* text = nullptr;
	iPoint pos;
	SDL_Rect rect;

};

#endif // !__UIENTITY_H__

