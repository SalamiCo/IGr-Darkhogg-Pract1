#ifndef __PTG_SCENE__H__
#define __PTG_SCENE__H__

#include "skel/skel.h"

class PtgScene : public Scene {
    protected:
        void onDraw ();

    public:
        PtgScene () {}
        virtual ~PtgScene () {}
};

#endif