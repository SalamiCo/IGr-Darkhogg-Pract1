#include "PtgScene.hpp"

#include <iostream>
#include <utility>

void PtgScene::onInitialize () {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void PtgScene::onUpdate (float delta) {
    fflush(stdout);
    
    /* WASD for basic movement */
    if (isKeyPressed(KEY_W)) {
        move(0, 150*delta);
    }
    if (isKeyPressed(KEY_S)) {
        move(0, -150*delta);
    }
    if (isKeyPressed(KEY_D)) {
        move(150*delta, 0);
    }
    if (isKeyPressed(KEY_A)) {
        move(-150*delta, 0);
    }

    /* RT for zooming */
    if (isKeyPressed(KEY_R)) {
        zoom(0.8*delta);
    }
    if (isKeyPressed(KEY_T)) {
        zoom(-0.8*delta);
    }

    /* VB for angle change */
    if (isKeyPressed(KEY_V)) {
        _tree.rotate(-0.2 * delta);
        _tree.regrow();
        _selected.size(0);
    }
    if (isKeyPressed(KEY_B)) {
        _tree.rotate(0.2 * delta);
        _tree.regrow();
        _selected.size(0);
    }

}

void PtgScene::onDraw () {
    _tree.draw();

    if (_selected.size() > 0) {
        glColor3f(1, 1, 1);
        _selected.draw();
    }
}

void PtgScene::onKeyDown (int code) {
    switch (code) {
        case KEY_ESCAPE: 
            quit();
            break;
        /* FG for shrinking/growing */
        case KEY_F:
            _tree.shrink();
            _selected.size(0);
            break;

        case KEY_G:
            _tree.grow();
            _selected.size(0);
            break;

        /* 12 for color mode */
        case KEY_1: {
            _tree.colorMode(CM_RAINBOW);
            break;
        }

        case KEY_2: {
            _tree.colorMode(CM_TREE);
            break;
        }

        /* 89 for angle mode */
        case KEY_8: {
            _tree.angleMode(AM_FIXED);
            _tree.regrow();
            _selected.size(0);
            break;
        }

        case KEY_9: {
            _tree.angleMode(AM_RANDOM);
            _tree.regrow();
            _selected.size(0);
            break;
        }

        /* YU and HJ for cameras */
        case KEY_Y: {
            _camCols = std::max(1, _camCols-1);
            configScreen(_camRows, _camCols);
            break;
        }
        case KEY_U: {
            _camCols = _camCols+1;
            configScreen(_camRows, _camCols);
            break;
        }

        case KEY_H: {
            _camRows = std::max(1, _camRows-1);
            configScreen(_camRows, _camCols);
            break;
        }
        case KEY_J: {
            _camRows = _camRows+1;
            configScreen(_camRows, _camCols);
            break;
        }
    }
}

void PtgScene::onMouseDown (int button) {
    Point2D wmp = getMouseWorldPosition();

    switch (button) {
        case MOUSE_RIGHT: {
            _tree = PtgTree(wmp.x - 50, wmp.y - 50);
            _selected.size(0);
            break;
        }
        case MOUSE_LEFT: {
            _selected = _tree.getSmallestSquareAt(wmp);
            break;
        }
    }
}