#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "UIObject.h"
#include "p2Point.h"


#define CURSOR_WIDTH 2

class UIText;

// TODO 1: Create your structure of classes

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	UIObject* CreateUIObject(UIType type, iPoint pos, SDL_Rect rect_sprisheet);

	UIText* CreateUIText(iPoint pos, p2SString text);

	SDL_Texture* GetAtlas() const;

private:

	p2List<UIObject*> UI_objects;
	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__