//
// Created by Duzhong Chen on 2023/12/29.
//

#ifndef FCL_FCL_HELPER_H
#define FCL_FCL_HELPER_H
#include <memory>

#include "fcl/broadphase/broadphase_dynamic_AABB_tree.h"
#include "fcl/broadphase/default_broadphase_callbacks.h"

class CollisionObjectDelegate : public fcl::CollisionObjectd {
public:
  inline CollisionObjectDelegate(fcl::CollisionGeometry<double> *cgeom): CollisionObject(std::shared_ptr<fcl::CollisionGeometry<double>>(cgeom)) {
  }
};

using DefaultCollisionDatad = fcl::DefaultCollisionData<double>;

#endif  // FCL_FCL_HELPER_H
