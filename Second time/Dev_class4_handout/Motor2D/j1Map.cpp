#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2String tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		ret = LoadData(map_file.child("map"));
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!

	if (ret == true)
	{
		ret = LoadTileset(map_file.child("map").child("tileset"));
	}
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::LoadData(const pugi::xml_node& node)
{
	bool ret = true;

	if(ret == true)
		ret = SetOrientation(node);
	if (ret == true)
		ret = SetRenderOrder(node);
	if (data.height = node.attribute("height").as_uint() == 0u)
		ret = false;

	data.width = node.attribute("width").as_uint();
	if (data.width == 0u)
		ret = false;

	data.next_object_id = node.attribute("nextobjectid").as_uint();
	if (data.next_object_id == 0u)
		ret = false;

	data.tile_height = node.attribute("tileheight").as_uint();
	if (data.tile_height == 0u)
		ret = false;

	data.tile_width = node.attribute("tilewidth").as_uint();
	if (data.tile_width == 0u)
		ret = false;
	
	return ret;
}

bool j1Map::SetRenderOrder(const pugi::xml_node & node)
{
	bool ret = false;
	p2String render_order = node.attribute("renderorder").as_string();
	if (render_order == "right-down")
	{
		data.render_order = RenderOrder::RIGHT_DOWN;
		ret = true;
	}

	else if (render_order == "reight-up")
	{
		data.render_order = RenderOrder::RIGHT_UP;
		ret = true;
	}

	else if (render_order == "left-down")
	{
		data.render_order = RenderOrder::LEFT_DOWN;
		ret = true;
	}

	else if (render_order == "left-up")
	{
		data.render_order = RenderOrder::LEFT_UP;
		ret = true;
	}
	else
	{
		data.render_order = RenderOrder::NO_TYPE;
		ret = false;
	}
	return ret;
}

bool j1Map::SetOrientation(const pugi::xml_node & node)
{
	bool ret = false;
	p2String orientation = node.attribute("orientation").as_string();
	if (orientation == "orthogonal")
	{
		data.orientation = Orientation::ORTHOGONAL;
		ret = true;
	}

	else if (orientation == "hexagonal")
	{
		data.orientation = Orientation::HEXAGONAL;
		ret = true;
	}

	else if (orientation == "isometric")
	{
		data.orientation = Orientation::ISOMETRIC;
		ret = true;
	}

	else if (orientation == "staggered")
	{
		data.orientation = Orientation::STAGGERED;
		ret = true;
	}
	else
	{
		data.orientation = Orientation::NO_TYPE;
		ret = false;
	}

	return ret;
}

bool j1Map::LoadTileset(const pugi::xml_node&)
{
	return true;
}

