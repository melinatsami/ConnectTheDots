#include "Level.h"
#include "GlobalState.h"
#include "Dot.h"
void Level::update(float dt)
{
	float mx = mouse.cur_pos_x;
	float my = mouse.cur_pos_y;
	if (mouse.button_left_pressed) {

	}
	if (mouse.button_left_down) {

	}

	GameObject::update(dt);
}

void Level::init()
{
	for (auto p_gob : m_static_object)
		if (p_gob) p_gob->init();
	for (auto p_gob : m_dynamic_object)
		if (p_gob) p_gob->init();
}

void Level::draw()
{
	for (auto& e : m_edges) { //draws edges
		const Dot& a = m_dots[e.first];
		const Dot& b = m_dots[e.second];
		switch (a.graph_id)
		{
		case 0: SETCOLOR(m_brush.outline_color, 255, 255, 0); break; // yellow
		case 1: SETCOLOR(m_brush.outline_color, 127, 0, 255); break; // purple
		case 2: SETCOLOR(m_brush.outline_color, 0, 0, 1); break; // blue
		}

		m_brush.outline_opacity = 1.0f;
		graphics::drawLine(a.x, a.y, b.x, b.y, m_brush);
	}

	for (auto& d : m_dots) //draws the dots
	{
		switch (d.graph_id)
		{
		case 0: SETCOLOR(m_brush.fill_color, 255, 255, 0); break;
		case 1: SETCOLOR(m_brush.fill_color, 127, 0, 255); break;
		case 2: SETCOLOR(m_brush.fill_color, 0, 0, 1); break;
		}

		m_brush.fill_opacity = 1.0f;
		graphics::drawDisk(d.x, d.y, dot_radius, m_brush);
	}

	for (auto p_gob : m_static_object)
		if (p_gob) p_gob->draw();
	for (auto p_gob : m_dynamic_object)
		if (p_gob) p_gob->draw();

}

Level::Level(const std::string& name)
{
}

Level::~Level()
{
	for (auto p_gob : m_static_object)
		if (p_gob) delete p_gob;
	for (auto p_gob : m_dynamic_object)
		if (p_gob) delete p_gob;

}
