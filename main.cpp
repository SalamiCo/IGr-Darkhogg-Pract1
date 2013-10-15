#include <stdio.h>
#include <memory>

#include "skel/skel.h"
#include "PtgScene.hpp"

int main (int argc, char** argv) {
    std::auto_ptr<Scene> scene (new PtgScene());
    return scene->run();
}