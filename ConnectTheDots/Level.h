#pragma once
#include "GameObject.h"
#include <sgg/graphics.h>
#include <list>
#include "util.h"
#include "Dot.h"
class Level :public GameObject 
{
protected:
	graphics::Brush m_brush;

	int m_selected_dot = -1; 
	int m_hover_dot = -1; //last selected dot
	float m_mouse_x = 0.0f; //temporary edge
	float m_mouse_y = 0.0f;
	bool completed = false; //for each level

	const float dot_radius = 25.0f;
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
	Level(const std::string& name = "Level");
	~Level();
};