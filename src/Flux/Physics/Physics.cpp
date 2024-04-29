#include "Physics.h"
#include "Flux/Core.h"
#include "Flux/Physics/CollisionBroad.h"

namespace flux {
namespace physics {

RigidBody Rb_with_linear(Vec2 vel, Vec2 accel) {
    return RigidBody{
        vel,
        accel,
        0.0f,
        0.0f
    };
}

RigidBody Rb_with_angular(float vel, float accel) {
    return RigidBody{
        Vec2(),
        Vec2(),
        vel,
        accel
    };
}

RigidBody rb_with(Vec2 vel, Vec2 accel, float ang_vel, float ang_accel) {
    return RigidBody{
        vel,
        accel,
        ang_vel,
        ang_accel
    };
}

void collision(Ecs& ecs) {
    update_aabb(ecs);
}

void update_box(Ecs& ecs, float dt) {
    auto view = ecs.view<Transform, Box, RigidBody>();

    for (auto& entity : view) {
        auto& transform = view.get<Transform>(entity);
        auto& box = view.get<Box>(entity);
        auto& rb = view.get<RigidBody>(entity);

        rb.ang_velocity += rb.ang_accel * dt;
        transform.rot += rb.ang_velocity * dt;

        rb.velocity += rb.accel * dt;
        transform.pos += rb.velocity * dt;
    }
}

void update_circle(Ecs& ecs, float dt) {
    auto view = ecs.view<Transform, Circle, RigidBody>();

    for (auto& entity : view) {
        auto& transform = view.get<Transform>(entity);
        auto& circle = view.get<Circle>(entity);
        auto& rb = view.get<RigidBody>(entity);

        rb.ang_velocity += rb.ang_accel * dt;
        transform.rot += rb.ang_velocity * dt;

        rb.velocity += rb.accel * dt;
        transform.pos += rb.velocity * dt;
    }
}

void update(Ecs& ecs, float dt) {
    update_box(ecs, dt);
    update_circle(ecs, dt);

    collision(ecs);
}

} // namespace physics
} // namespace flux
