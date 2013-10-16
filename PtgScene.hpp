#ifndef __PTG_SCENE__H__
#define __PTG_SCENE__H__

#include "skel/skel.h"
#include "Square.hpp"

#include <memory>
#include <vector>
#include <cmath>

class PtgScene : public Scene {
    private:
        GLfloat angle;
        std::vector<std::vector<Square> > squares;

        void grow ();
        void shrink ();
        void regrow ();

    protected:
        void onInitialize ();
        void onUpdate (float delta);
        void onDraw ();
        void onKeyDown (int code);

    public:
        PtgScene () : angle(M_PI_4) {}
        virtual ~PtgScene () {}
};

#endif