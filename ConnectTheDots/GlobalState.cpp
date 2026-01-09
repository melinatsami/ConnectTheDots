#include "GlobalState.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"


GlobalState::GlobalState()
{
}

void GlobalState::init()
{
	m_level_count = 1; //handles level 1 
	m_current_level = new Level1();
	m_current_level->init();

	graphics::preloadBitmaps(getAssetDir());
	graphics::setFont(getAssetDir() + "GravitasOne-Regular.ttf");
}

void GlobalState::draw()
{
	graphics::Brush m_brush;
	//draw Congratulations
	if (GameOver()) {
		//black background
		m_brush.outline_opacity = 0.0f;
		m_brush.fill_opacity = 1.0f;
		m_brush.fill_color[0] = 0.0f;
		m_brush.fill_color[1] = 0.0f;
		m_brush.fill_color[2] = 0.0f;
		graphics::drawRect(GlobalState::getInstance()->getCanvasWidth() / 2,
			GlobalState::getInstance()->getCanvasHeight() / 2, GlobalState::getInstance()->getCanvasWidth(),
			GlobalState::getInstance()->getCanvasHeight(), m_brush);

		//white text
		m_brush.outline_opacity = 1.0f;
		m_brush.fill_opacity = 1.0f;
		m_brush.fill_color[0] = 1.0f;
		m_brush.fill_color[1] = 1.0f;
		m_brush.fill_color[2] = 1.0f;

		graphics::drawText(GlobalState::getInstance()->getCanvasWidth() / 5,
			GlobalState::getInstance()->getCanvasHeight() / 2, 40.0f, "CONGRATULATIONS!", m_brush);
		return;
	}
	if (!m_current_level)
		return;
	m_current_level->draw();
}

void GlobalState::update(float dt)
{
	if (dt > 500)
		return; 
	if (!m_current_level)
		return;
	m_current_level->update(dt);
}

void GlobalState::nextLevel() {
	
	m_level_count++;

	if (m_current_level) {
		delete m_current_level;
		m_current_level = nullptr;
	}

	if (m_level_count == 1) {
		m_current_level = new Level1(); 
	}
	else if (m_level_count == 2) {
		m_current_level = new Level2();
	}
	else if(m_level_count == 3){
		m_current_level = new Level3();
	}
	else {
		GlobalState::getInstance()->setGameOver(true);
	}
	

	if (m_current_level) {
		m_current_level->init();
	}
}
GlobalState* GlobalState::getInstance()
{
	if (m_unique_instance == nullptr)
		m_unique_instance = new GlobalState(); //dhmiourgei instance ayths ths klaseis
	return m_unique_instance;
}

GlobalState::~GlobalState()
{
	if (m_current_level) //gia pollapla levels theloume for loop poy tha diagrafei kathe level
		delete m_current_level;
}

std::string GlobalState::getAssetDir()
{
	return m_asset_path;
}

std::string GlobalState::getFullAssetPath(const std::string& asset)
{
	return m_asset_path + asset;
}

GlobalState* GlobalState:: m_unique_instance=nullptr;