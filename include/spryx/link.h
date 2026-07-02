#ifndef SPRYX_LINK_H
#define SPRYX_LINK_H
#include "primitives.h"

struct Link {
    double mass = 0.0;
    Vec3 axis = Vec3(0, 0, 1);
    Vec3 com{};
    Rot3 inertia;
    Vec3 parentVec{};
    Rot3 parentRot;
};

struct LinkState {
    double q{}, qd{}, qdd{};
    Rot3 R;
    Vec3 w{}, v{}, dw{}, dv{}, f{}, n{};
};


#endif //SPRYX_LINK_H
