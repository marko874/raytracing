/**
 * @file ray.hh
 * @author Marko Livajusic (marko_livajusic0@protonmail.com)
 * @brief Ray header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef RAY_HH_
#define RAY_HH_

#include "vec.hh"

namespace rw {
class Ray {
public:
  explicit Ray() = default;
  explicit Ray(const mt::Point3D& origin, const mt::Vec3& direction);

  mt::Point3D get_origin() const;
  mt::Vec3 get_direction() const;

  mt::Point3D at(const float t) const;

private:
  mt::Point3D m_origin;
  mt::Vec3 m_direction;
};

}; // namespace rw

#endif
