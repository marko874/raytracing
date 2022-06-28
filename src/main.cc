/**
 * @file main.cc
 * @author Marko Livajusic (marko_livajusic0@protonmail.com)
 * @brief Color calculation and file writing
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "ray.hh"
#include "vec.hh"

#include <array>
#include <cmath>
#include <iostream>

using namespace mt;
using namespace rw;

void write_color(std::ostream& out, Color& rgb) {
  out << static_cast<int>(255.999 * rgb[0]) << " "
      << static_cast<int>(255.999 * rgb[1]) << " "
      << static_cast<int>(255.999 * rgb[2]) << "\n";
}

bool hit_sphere(const Point3D& center, float r, const Ray& ray) {
  Vec3 oc           = ray.get_origin() - center;
  auto a            = dot(ray.get_direction(), ray.get_direction());
  auto b            = 2.0 * dot(oc, ray.get_direction());
  auto c            = dot(oc, oc) - r * r;
  auto discriminant = b * b - 4 * a * c;
  return discriminant > 0;
}

Color ray_color(const Ray& ray) {
  if (hit_sphere(Point3D{0.0f, 0.0f, -1.0f}, 0.5f, ray)) {
    return Color{1.0f, 0.0f, 0.0f};
  }

  Vec3 unit_dir = unit_vector(ray.get_direction());
  auto t        = 0.5 * (unit_dir.get_y() + 1.0f);
  return (1.0 - t) * Color{1.0f, 1.0f, 1.0f} + t * Color{0.5f, 0.7f, 1.0f};
}

int main() {
  constexpr auto ASPECT_RATIO    = 16.0 / 9.0;
  constexpr auto IMG_WIDTH       = 400;
  constexpr auto IMG_HEIGHT      = static_cast<int>(IMG_WIDTH / ASPECT_RATIO);
  constexpr auto VIEWPORT_HEIGHT = 2.0;
  constexpr auto VIEWPORT_WIDTH  = ASPECT_RATIO * VIEWPORT_HEIGHT;
  constexpr float FOCAL_LENGTH   = 1.0f;
  const auto origin              = Point3D{0.0f, 0.0f, 0.0f};
  const auto horizontal          = Vec3{VIEWPORT_WIDTH, 0.0f, 0.0f};
  const auto vertical            = Vec3{0.0f, VIEWPORT_HEIGHT, 0.0f};
  auto lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - Vec3{0.0f, 0.0f, FOCAL_LENGTH};

  std::cout << "P3\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";

  for (int j = IMG_HEIGHT - 1; j >= 0; j--) {
    for (int i = 0; i < IMG_WIDTH; i++) {
      auto u = float(i) / (IMG_WIDTH - 1);
      auto v = float(j) / (IMG_HEIGHT - 1);
      Ray ray{origin,
              lower_left_corner + u * horizontal + v * vertical - origin};
      Color pixel_color = ray_color(ray);
      write_color(std::cout, pixel_color);
    }
  }
  return 0;
}
