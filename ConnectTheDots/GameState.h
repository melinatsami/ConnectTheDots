#pragma once
#include <string>
#include <sgg/graphics.h>

class GameState
{
private:
	std::string m_asset_path = "assets\\";

	float m_canvas_width = 4.0f;
	float m_canvas_height = 4.0f;

	static GameState* m_unique_instance;

	GameState();

	class Level* m_current_level = 0;

public:
	void init();
	void draw();
	void update(float dt);

	static GameState* getInstance();
	~GameState();

	float getCanvasWidth() { return m_canvas_width; };
	float getCanvasHeight() { return m_canvas_height; };

	std::string getAssetDir();
	std::string getFullAssetPath(const std::string& asset);

};