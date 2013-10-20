#ifndef __PTG_SCENE__H__
#define __PTG_SCENE__H__

#include "skel/skel.h"
#include "PtgSquare.hpp"
#include "PtgTree.hpp"

#include <memory>
#include <vector>
#include <cmath>

class PtgScene : public Scene {
    private:
        PtgTree _tree;
        int _camCols, _camRows;
        PtgSquare _selected;

        void grow ();
        void shrink ();
        void regrow ();

    protected:
        void onInitialize ();
        void onUpdate (float delta);
        void onDraw ();
        void onKeyDown (int code);
        void onMouseDown (int button);

    public:
        PtgScene () : _camCols(1), _camRows(1), _selected(0, 0, 0, 0) {}
        virtual ~PtgScene () {}
};

#endif