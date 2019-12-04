#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UIText.h"
#include "p2Point.h"


j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (p2List_item<UIObject*>* iter = UI_objects.start; iter; iter = iter->next)
		iter->data->PostUpdate();

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

UIObject* j1Gui::CreateUIObject(UIType type, iPoint pos, SDL_Rect rect_spritesheet)
{
	UIObject* ret = nullptr;
	switch (type)
	{
	case UIType::IMAGE:
		ret = new UIImage(type, pos, rect_spritesheet);
		break;
	case UIType::TEXT:
		break;
	default:
		break;
	}

	UI_objects.add(ret);

	return ret;
}

// class Gui ---------------------------------------------------

