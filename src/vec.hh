/**
 * @file vec.hh
 * @author Marko Livajusic (marko_livajusic0@protonmail.com)
 * @brief Vec3 header
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef VEC_HH_
#define VEC_HH_

#include <array>
#include <iostream>

namespace mt {
class Vec3 {
public:
  explicit Vec3() = default;
  explicit Vec3(float n_1, float n_2, float n_3);

  Vec3 operator-() const {
    return Vec3{-m_values[0], -m_values[1], -m_values[2]};
  }

  float operator[](int i) const {
    return m_values[i];
  }

  float& operator[](int i) {
    return m_values[i];
  }

  Vec3& operator+=(const Vec3& other) {
    m_values[0] += other[0];
    m_values[1] += other[1];
    m_values[2] += other[2];
    return *this;
  }

  Vec3& operator*=(const float t) {
    m_values[0] *= t;
    m_values[1] *= t;
    m_values[2] *= t;
    return *this;
  }

  Vec3& operator/=(const float t) {
    return *this *= 1 / t;
  }

  float length() const;
  float length_squared() const;

  float get_x() const;
  float get_y() const;
  float get_z() const;

private:
  std::array<float, 3> m_values;
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& vec) {
  return out << vec[0] << " " << vec[1] << " " << vec[2];
}

inline Vec3 operator+(const Vec3& first, const Vec3& second) {
  return Vec3{first[0] + second[0], first[1] + second[1], first[2] + second[2]};
}

inline Vec3 operator-(const Vec3& first, const Vec3& second) {
  return Vec3{first[0] - second[0], first[1] - second[1], first[2] - second[2]};
}

inline Vec3 operator*(const Vec3& first, const Vec3& second) {
  return Vec3{first[0] * second[0], first[1] * second[1], first[2] * second[2]};
}

inline Vec3 operator*(const float t, const Vec3& other) {
  return Vec3{t * other[0], t * other[1], t * other[2]};
}

inline Vec3 operator*(const Vec3& vec, const float t) {
  return t * vec;
}

inline Vec3 operator/(const Vec3& vec, const float t) {
  return (1 / t) * vec;
}

inline float dot(const Vec3& first, const Vec3& second) {
  return (first[0] * second[0] + first[1] * second[1] + first[2] * second[2]);
}

inline Vec3 cross(const Vec3& first, const Vec3& second) {
  return Vec3{
      first[1] * second[2] - first[2] - second[1],
      first[2] * second[0] - first[0] - second[2],
      first[0] * second[1] - first[1] - second[0],
  };
}

inline Vec3 unit_vector(const Vec3& vec) {
  return vec / vec.length();
}

/**
 * Type aliases
 */
using Point3D = Vec3;
using Color   = Vec3;
} // namespace mt
#endif
