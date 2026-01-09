#include "Level3.h"
#include "GlobalState.h"
void Level3 :: init() {
    completed = false; // Reset for the new level
    m_dots.clear();
    m_edges.clear(); //clear existing data

    int rows = 6;
    int cols = 6;
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
            if (i == 5 && j<4 || i !=0 && j==1 || i>=4 && j<2) {
                d.graph_id = 1; //green
            }
            else if (j==5 || i<4 && j>=3) {
                d.graph_id = 2; // blue
            }
            else {
                d.graph_id = 0;//red
            }
            m_dots.push_back(d);
        }
    }
    
}