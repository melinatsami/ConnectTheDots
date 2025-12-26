#pragma once
#include "GameObject.h"
#include <sgg/graphics.h>
#include <list>
#include "util.h"
class Level :public GameObject 
{
protected:
	graphics::Brush m_brush;
	graphics::MouseState mouse;

	const float dot_radius = 10.0f;
	struct Edge {
		int from;
		int to;
	};
	std::vector<Dot> m_dots;
	std::vector<Edge> m_edges;

	std::vector<GameObject*> m_static_object;
	std::list<GameObject*>m_dynamic_object;
public:
	void update(float dt) override;
	void init() override;
	void draw() override;
	Level(const std::string& name = "level0");
	~Level();
};