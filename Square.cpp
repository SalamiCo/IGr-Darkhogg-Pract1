#include "Square.hpp"

#include <math.h>

void Square::draw () {
    Turtle t (x(), y(), ang());

    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++) {
        t.advance(_size);
        t.rotate(M_PI_2);
        glVertex2d(t.x(), t.y());
    }
    glEnd();
}

std::pair<Square,Square> Square::nextLevel (GLfloat angle) {
    Turtle t (x(), y(), ang());
    t.rotate(M_PI_2);
    t.advance(size());
    t.rotate(-angle);

    GLfloat leftSize = size()*sin(angle);
    Square left (t.x(), t.y(), leftSize, t.ang());

    t.advance(leftSize);
    t.rotate(-M_PI_2);

    Square right (t.x(), t.y(), size()*cos(angle), t.ang());
    return std::pair<Square,Square>(left, right);
}