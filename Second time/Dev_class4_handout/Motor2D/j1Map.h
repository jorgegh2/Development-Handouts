#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "p2String.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct Tileset
{
	p2String name;
	uint first_gid = 0u;
	uint tile_width = 0u;
	uint tile_height = 0u;
	uint spacing = 0u;
	uint margin = 0u;
	const char* image_path;
};
// TODO 1: Create a struct needed to hold the information to Map node
enum class Orientation : uint
{
	NO_TYPE = 0u,
	ORTHOGONAL,
	ISOMETRIC,
	STAGGERED,
	HEXAGONAL
};

enum class RenderOrder : uint
{
	NO_TYPE = 0u,
	RIGHT_DOWN,
	RIGHT_UP,
	LEFT_DOWN,
	LEFT_UP
};

struct Data
{
	Orientation orientation;
	RenderOrder render_order;
	uint width = 0u;
	uint height = 0u;
	uint tile_width = 0u;
	uint tile_height = 0u;
	uint next_object_id = 0u;
};


// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:
	bool LoadData(const pugi::xml_node&);

	bool LoadTileset(const pugi::xml_node&);

	bool SetRenderOrder(const pugi::xml_node & node);

	bool SetOrientation(const pugi::xml_node & node);

public:

	// TODO 1: Add your struct for map info as public for now
	Tileset tileset;
	Data data;

private:

	pugi::xml_document	map_file;
	p2String			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__