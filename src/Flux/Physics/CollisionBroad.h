#pragma once

#include "Flux/Core.h"

namespace flux {
namespace physics {

struct AABB {
    Vec2 min;
    Vec2 max;
};

void update_aabb(Ecs& ecs);



} // namespace physics
} // namespace flux
