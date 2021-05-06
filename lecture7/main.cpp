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

void CantorSet(GWindow &gw, int x, int y, int length, int level) {
    if (level > 0) {
        CantorSet(gw, x, y + 20, length / 3, level-1);
        CantorSet(gw, x + length * 2 / 3, y + 20, length / 3, level-1);
        gw.drawLine(x, y, x + length, y);
        gw.pause(100);
    }
}

int main() {
    GWindow gw(600, 600);
    gw.setColor("BLACK");
    CantorSet(gw, 50, 50, 500, 5);
    return 0;
}
