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

class DynamicAABBTreeCollisionManager : public fcl::DynamicAABBTreeCollisionManagerd {
 public:

  inline void defaultCollide(fcl::CollisionObjectd* obj, void* cdata) const {
    this->collide(obj, cdata, fcl::DefaultCollisionFunction);
  }

  inline void internalCollide(void* cdata) const {
    this->collide(cdata, fcl::DefaultCollisionFunction);
  }

};

using DefaultCollisionDatad = fcl::DefaultCollisionData<double>;

#endif  // FCL_FCL_HELPER_H
