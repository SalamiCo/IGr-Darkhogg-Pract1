#include "PtgScene.hpp"

#include <iostream>
#include <utility>

void PtgScene::onInitialize () {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Initialize the first level...
    std::vector<Square> lvl0;
    lvl0.push_back(Square(-50.0, -200.0, 100, 0.0));

    // ...and insert it
    squares.push_back(lvl0);

    // Grow 8 levels
    for (int i = 0; i < 8; i++) {
        grow();
    }
}

void PtgScene::onUpdate (float delta) {
    /* WASD for basic movement */
    if (isKeyPressed(KEY_W)) {
        move(0, 50*delta);
    }
    if (isKeyPressed(KEY_S)) {
        move(0, -50*delta);
    }
    if (isKeyPressed(KEY_D)) {
        move(50*delta, 0);
    }
    if (isKeyPressed(KEY_A)) {
        move(-50*delta, 0);
    }

    /* RT for zooming */
    if (isKeyPressed(KEY_R)) {
        zoom(0.5*delta);
    }
    if (isKeyPressed(KEY_T)) {
        zoom(-0.5*delta);
    }

    /* VB for angle change */
    if (isKeyPressed(KEY_V) && angle > 0.3) {
        angle -= 0.2 * delta;
        regrow();
    }
    if (isKeyPressed(KEY_B) && angle < M_PI_2 - 0.3) {
        angle += 0.2 * delta;
        regrow();
    }
}

GLdouble interpolate (int lvl, int step, int color) {
    int c = ((lvl/step - color*2) % 6 + 6) % 6;
    int m = (lvl % step + step) % step;

    switch (c) {
        case 0: return 1.0;
        case 1: return 1.0;
        case 2: return (GLdouble) (step - m) / step;
        case 3: return 0.0;
        case 4: return 0.0;
        case 5: return (GLdouble) m / step;
    }
}

void PtgScene::onDraw () {
    glClear(GL_COLOR_BUFFER_BIT);

    int idxInit = 0;//floor(zoom() / 1);
    int idxEnd = 20;//idxInit + 10;

    for (int i = std::max(0, idxInit); i < idxEnd &&i < squares.size(); i++) {
        const int step = 3;
        GLdouble red = interpolate(i, step, 0);
        GLdouble green = interpolate(i, step, 1);
        GLdouble blue = interpolate(i, step, 2);
        GLdouble alpha = 1.0;

        glColor4d(red, green, blue, alpha);
        for (std::vector<Square>::iterator lit = squares[i].begin(); lit != squares[i].end(); ++lit) {
            lit->draw();
        }
    }
}

void PtgScene::onKeyDown (int code) {
    switch (code) {
        case KEY_F:
            shrink();
            break;

        case KEY_G:
            grow();
            break;
    }
}

void PtgScene::grow () {
    const int next = squares.size();
    const int prev = next - 1;

    std::vector<Square> level;
    squares.push_back(level);

    for (std::vector<Square>::iterator it = squares[prev].begin(); it != squares[prev].end(); ++it) {
        std::pair<Square,Square> nexts = it->nextLevel(angle);
        squares[next].push_back(nexts.first);
        squares[next].push_back(nexts.second);
    }
}

void PtgScene::shrink () {
    if (squares.size() > 1) {
        squares.pop_back();
    }
}

void PtgScene::regrow () {
    int size = squares.size();

    while (squares.size() > 1) {
        shrink();
    }

    while (squares.size() < size) {
        grow();
    }
}