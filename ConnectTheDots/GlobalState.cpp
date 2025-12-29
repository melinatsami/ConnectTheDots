#include "GlobalState.h"
#include "Level.h"

GlobalState::GlobalState()
{
}

void GlobalState::init()
{
	m_current_level = new Level();
	m_current_level->init();

	graphics::preloadBitmaps(getAssetDir());
}

void GlobalState::draw()
{
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