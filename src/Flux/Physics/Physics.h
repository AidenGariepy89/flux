#pragma once

#include "Flux/Core.h"

namespace flux {
namespace physics {

struct Box {
    float width;
    float height;
    float mass;
};

struct Circle {
    float radius;
    float mass;
};

struct RigidBody {
    Vec2 velocity;
    Vec2 accel;

    float ang_velocity;
    float ang_accel;
};

struct StaticBody;

RigidBody rb_with_linear(Vec2 vel, Vec2 accel);
RigidBody rb_with_angular(float vel, float accel);
RigidBody rb_with(Vec2 vel, Vec2 accel, float ang_vel, float ang_accel);

void update(Ecs& ecs, float dt);

} // namespace physics
} // namespace flux
