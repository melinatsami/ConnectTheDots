#include "Level3.h"
#include "GlobalState.h"
void Level3 :: init() {
    completed = false; // Reset for the new level
    m_dots.clear();
    m_edges.clear(); //clear existing data

    int rows = 2;
    int cols = 2;
    float canvasW = GlobalState::getInstance()->getCanvasWidth();
    float canvasH = GlobalState::getInstance()->getCanvasHeight();
    float spacing = 100.0f; // distance between dots
    float gridW = (cols - 1) * spacing;
    float gridH = (rows - 1) * spacing;
    float offsetX = (canvasW - gridW) / 2.0f;
    float offsetY = (canvasH - gridH) / 2.0f; //starting dot

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Dot d;
            d.x = offsetX + (j * spacing);
            d.y = offsetY + (i * spacing);
            if (i == 0) {
                d.graph_id = 0;
            }
            else if (j==2) {
                d.graph_id = 1;
            }
            else {
                d.graph_id = 2;
            }
            m_dots.push_back(d);
        }
    }
    
}