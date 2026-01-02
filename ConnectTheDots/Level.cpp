#include "Level.h"
#include "GlobalState.h"
void Level::update(float dt)
{
	bool completed = false;
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	int mx = mouse.cur_pos_x;
	int my = mouse.cur_pos_y;
	if (mouse.button_left_pressed) { //check if dot was selected. if yes, mark it as first node
		m_selected_dot = -1; 
		for (int i = 0; i < m_dots.size(); i++)
		{
			float dx = mx - m_dots[i].x; //distance between mouse and dot 
			float dy = my - m_dots[i].y;

			if (dx * dx + dy * dy <= dot_radius * dot_radius)
			{
				m_selected_dot = i; //save dots index 
				break; //first dot found
			}
		}
	}
	if (mouse.button_left_down && m_selected_dot != -1) { 
		m_mouse_x = mx;
		m_mouse_y = my; //keep mouse location
	}

	if (mouse.button_left_released && m_selected_dot != -1){
		m_hover_dot = -1;

		for (int i = 0; i < m_dots.size(); i++) //check last selected dot
		{
			float dx = mx - m_dots[i].x;
			float dy = my - m_dots[i].y;

			if (dx * dx + dy * dy <= dot_radius * dot_radius)
			{
				m_hover_dot = i;
				break;
			}
		}

		//if dot belongs in the same graph as previous, connect them
		if (m_hover_dot != -1 && m_hover_dot != m_selected_dot &&
			m_dots[m_hover_dot].graph_id == m_dots[m_selected_dot].graph_id)
		{
			Edge e;
			e.from = m_selected_dot;
			e.to = m_hover_dot;
			m_edges.push_back(e);
		}
		m_selected_dot = -1; //reset
		m_hover_dot = -1;
		if (m_edges.size() == m_dots.size() + 1) {
			completed = true;
		}
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
		const Dot& a = m_dots[e.from];
		const Dot& b = m_dots[e.to];
		switch (a.graph_id)
		{
		case 0: SETCOLOR(m_brush.outline_color, 1, 0, 0); break; // red
		case 1: SETCOLOR(m_brush.outline_color, 0, 1, 0); break; // green
		case 2: SETCOLOR(m_brush.outline_color, 0, 0, 1); break; // blue
		}

		m_brush.outline_opacity = 1.0f;
		graphics::drawLine(a.x, a.y, b.x, b.y, m_brush);
	}
	
	for (auto& d : m_dots) //draws the dots
	{
		switch (d.graph_id)
		{
		case 0: SETCOLOR(m_brush.fill_color, 1, 0, 0); break;
		case 1: SETCOLOR(m_brush.fill_color, 0, 1, 0); break;
		case 2: SETCOLOR(m_brush.fill_color, 0, 0, 1); break;
		}

		m_brush.fill_opacity = 1.0f;
		graphics::drawDisk(d.x, d.y, dot_radius, m_brush);
	}
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
