#include "gwindow.h"
#include "gevents.h"
#include "gobjects.h"
#include "gtypes.h"

// int main() {
//     GWindow gw;
//     //GLine line();
//     while (true) {
//         GMouseEvent e = waitForEvent(MOUSE_EVENT);
//         cout << "This program lets the user draw lines by dragging." << endl;
//         if (e.getEventType() == MOUSE_PRESSED) {
//             gw.drawLine(e.getX(), e.getY(), e.getX(), e.getY());
//         } else if (e.getEventType() == MOUSE_DRAGGED) {
//             GLine line = GLine(e.getX(), e.getY(), e.getX(), e.getY());
//             line.setEndPoint(e.getX(), e.getY());
//         }
//     }
// }

void takeAnimationStep() {

}

void handleMouseEvent(GMouseEvent e) {
    cout << e.getX() << endl;
    cout << e.getY() << endl;
}

void handleKeyEvent(GKeyEvent e) {

}


int main() {
    GTimer timer(20);
    timer.start();
    while (true) {
        GEvent e = waitForEvent(TIMER_EVENT + MOUSE_EVENT + KEY_EVENT);
        switch (e.getEventClass()) {
            case TIMER_EVENT:
            takeAnimationStep();
            break;
            case MOUSE_EVENT:
            handleMouseEvent(GMouseEvent(e));
            break;
            case KEY_EVENT:
            handleKeyEvent(GKeyEvent(e));
            break;
        }
    }
    return 0;
}