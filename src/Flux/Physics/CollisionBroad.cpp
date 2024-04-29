#include "CollisionBroad.h"
#include "Flux/Core.h"
#include "Flux/Physics/Physics.h"

namespace flux {
namespace physics {

void update_box_aabb(Ecs& ecs) {
    auto view = ecs.view<const Transform, const Box, AABB>();

    for (auto& entity : view) {
        const auto& trans = view.get<const Transform>(entity);
        const auto& box = view.get<const Box>(entity);
        auto& aabb = view.get<AABB>(entity);

        aabb.min = trans.pos - Vec2(box.width / 2.0f, box.height / 2.0f);
        aabb.max = trans.pos + Vec2(box.width / 2.0f, box.height / 2.0f);
    }
}

void update_circle_aabb(Ecs& ecs) {
    auto view = ecs.view<const Transform, const Circle, AABB>();

    for (auto& entity : view) {
        const auto& trans = view.get<const Transform>(entity);
        const auto& circle = view.get<const Circle>(entity);
        auto& aabb = view.get<AABB>(entity);

        aabb.min = trans.pos - Vec2(circle.radius, circle.radius);
        aabb.max = trans.pos + Vec2(circle.radius, circle.radius);
    }
}

void update_aabb(Ecs &ecs) {
    update_box_aabb(ecs);
    update_circle_aabb(ecs);
}




} // namespace physics
} // namespace flux
