#include "gwindow.h"
#include "gtypes.h"
#include "gevents.h"
#include "random.h"
#include "gobjects.h"

int main() {
    GWindow gw;
    cout << "Pick three points on the window" << endl;
    Vector<GPoint> pointsSet;
    double vertexX;
    double vertexY;
    for (int i = 0; i < 3; i++) {
        GMouseEvent mouseEvent = waitForEvent();
        if (mouseEvent.getEventType() == MOUSE_CLICKED) {
            vertexX = mouseEvent.getX();
            vertexY = mouseEvent.getY();
            GPoint vertex = GPoint(vertexX, vertexY);
            pointsSet.add(vertex);
        }
        gw.repaint();
    }
    gw.drawLine(pointsSet[0], pointsSet[1]);
    gw.drawLine(pointsSet[1], pointsSet[2]);
    gw.drawLine(pointsSet[2], pointsSet[0]);
    int randomVertex = randomInteger(0, 3);
    gw.setColor("BLUE");
    gw.drawOval(pointsSet[randomVertex].getX(), pointsSet[randomVertex].getY(), 2, 2);
    return 0;
}
