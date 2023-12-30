//
// Created by Duzhong Chen on 2023/12/29.
//

#ifndef FCL_FCL_HELPER_H
#define FCL_FCL_HELPER_H
#include <memory>
#include <emscripten.h>

#include "fcl/broadphase/broadphase_dynamic_AABB_tree.h"
#include "fcl/broadphase/broadphase_dynamic_AABB_tree_array.h"
#include "fcl/broadphase/default_broadphase_callbacks.h"

using GJKSolverType = fcl::GJKSolverType;

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

  inline void collideWith(DynamicAABBTreeCollisionManager* manager, void* cdata) const {
    this->collide(manager, cdata, fcl::DefaultCollisionFunction);
  }

};

class DynamicAABBTreeCollisionManager_Array : public fcl::DynamicAABBTreeCollisionManager_Array<double> {
public:

  inline void defaultCollide(fcl::CollisionObjectd* obj, void* cdata) const {
    this->collide(obj, cdata, fcl::DefaultCollisionFunction);
  }

  inline void internalCollide(void* cdata) const {
    this->collide(cdata, fcl::DefaultCollisionFunction);
  }

  inline void collideWith(DynamicAABBTreeCollisionManager_Array* manager, void* cdata) const {
    this->collide(manager, cdata, fcl::DefaultCollisionFunction);
  }

};

using DefaultCollisionDatad = fcl::DefaultCollisionData<double>;

class FclHelper {
public:

  inline void vector3_set_x(fcl::Vector3d* vec3, double x) {
    vec3->x() = x;
  }

  inline void vector3_set_y(fcl::Vector3d* vec3, double y) {
    vec3->y() = y;
  }

  inline void vector3_set_z(fcl::Vector3d* vec3, double z) {
    vec3->z() = z;
  }

  inline void vector3_set_values(fcl::Vector3d* vec3, double x, double y, double z) {
    vec3->x() = x;
    vec3->y() = y;
    vec3->z() = z;
  }

};

#endif  // FCL_FCL_HELPER_H
