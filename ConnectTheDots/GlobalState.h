#pragma once
#include <string>
#include <sgg/graphics.h>

class GlobalState
{
private:
	std::string m_asset_path = "assets\\";

	float m_canvas_width = 800.0f;
	float m_canvas_height = 800.0f;

	static GlobalState* m_unique_instance;
	bool m_game_over = false;

	GlobalState();

	class Level* m_current_level = 0;
	int m_level_count = 0;
	
public:
	void init();
	void draw();
	void update(float dt);
	void nextLevel();
	void setGameOver(bool state) {m_game_over = state;};
	bool GameOver() { return m_game_over; };
	static GlobalState* getInstance();
	~GlobalState();

	float getCanvasWidth() { return m_canvas_width; };
	float getCanvasHeight() { return m_canvas_height; };

	std::string getAssetDir();
	std::string getFullAssetPath(const std::string& asset);

};