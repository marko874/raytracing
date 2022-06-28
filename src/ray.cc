/**
 * @file ray.cc
 * @author Marko Livajusic (marko_livajusic0@protonmail.com)
 * @brief Ray implementation
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "ray.hh"

namespace rw {
Ray::Ray(const mt::Point3D& origin, const mt::Vec3& direction)
    : m_origin(origin), m_direction(direction) {
}

mt::Point3D Ray::get_origin() const {
  return m_origin;
}

mt::Vec3 Ray::get_direction() const {
  return m_direction;
}

mt::Point3D Ray::at(const float t) const {
  return m_origin + t * m_direction;
}

} // namespace rw
