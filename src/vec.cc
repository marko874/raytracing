#include "vec.hh"

#include <cmath>

namespace mt {
Vec3::Vec3(float n_1, float n_2, float n_3) {
  m_values[0] = n_1;
  m_values[1] = n_2;
  m_values[2] = n_3;
}

float Vec3::get_x() const {
  return m_values[0];
}

float Vec3::get_y() const {
  return m_values[1];
}

float Vec3::get_z() const {
  return m_values[2];
};

float Vec3::length() const {
  return std::sqrt(length_squared());
}

float Vec3::length_squared() const {
  return m_values[0] * m_values[0] + m_values[1] * m_values[1] +
         m_values[2] * m_values[2];
}
} // namespace mt