/*************************************************************************/
/* Stanford Portable Library                                             */
/* Copyright (c) 2014 by Eric Roberts <eroberts@cs.stanford.edu>         */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*************************************************************************/

#include <string>
#include "gevent.h"
#include "gmath.h"
#include "gobjects.h"
#include "gwindow.h"
#include "random.h"
#include "gtimer.h"

using namespace std;

volatile bool stopGame = false;

void DrawTriangle(vector<GPoint>& vertices) {
    cout << "Choose three points in the window." << endl;
    int timeClick = 0;
    GEvent e = waitForClick();
    while (timeClick < 3) {
        GPoint vertex = GPoint(e.getX(), e.getY());
        vertices.push_back(vertex);
        timeClick++;
        if (timeClick <= 2) {
            e = waitForClick();
        }
    }
}

void MouseEventHandler(GEvent e) {
    if (e.getEventType() == MOUSE_CLICKED) {
        stopGame = true;
    }
}

void ChaosGame(vector<GPoint>& vertices, GWindow& gw) {
    int ri = randomInteger(0, 2);
    GPoint currentPoint = vertices[ri];
    GOval* filledCircle = new GOval(currentPoint.x, currentPoint.y, 3, 3);
    filledCircle->setFilled(true);
    filledCircle->setFillColor("RED");
    gw.add(filledCircle);
    gw.setMouseListener(MouseEventHandler);
    while (!stopGame) {
        ri = randomInteger(0, 2);
        GPoint randomVertex = vertices[ri];
        currentPoint = GPoint((currentPoint.x + randomVertex.x) / 2, (currentPoint.y + randomVertex.y) / 2);
        GOval *newCircle = new GOval(currentPoint.x, currentPoint.y, 3, 3);
        newCircle->setFilled(true);
        newCircle->setFillColor("RED");
        gw.add(newCircle);
    }
}

int main() {
    GWindow gw(800, 800);
    vector<GPoint> vertices;
    DrawTriangle(vertices);
    ChaosGame(vertices, gw);
    return 0;
}
