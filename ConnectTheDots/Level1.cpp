#include "Level1.h"
void Level1:: init(){
        m_dots.clear();
        m_edges.clear(); //clear existing data

        int rows = 3;
        int cols = 3;

        float spacing = 150.0f; // distance between dots
        float offsetX = 100.0f;
        float offsetY = 100.0f; //starting dot

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Dot d;
                d.x = offsetX + (j * spacing);
                d.y = offsetY + (i * spacing);
                if ((j == 2) || (i==0) || (i==2)){
                    d.graph_id = 0;
                }
                else {
                    d.graph_id = 2;
                }
                m_dots.push_back(d);

            }
        }
}