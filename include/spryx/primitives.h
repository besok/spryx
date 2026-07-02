#ifndef SPRYX_ELEMS_H
#define SPRYX_ELEMS_H
#include <cmath>

static double degToRad(const double deg) {
    return deg * M_PI / 180.0;
}

struct Vec3 {
    double x, y, z;

    Vec3 operator+(const Vec3 &other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3 &other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(const double scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator*(const Vec3 &other) const {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    Vec3 operator/(const double scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    [[nodiscard]] Vec3 cross(const Vec3 &o) const {
        return Vec3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
    }
};

struct Rot3 {
    double mx[3][3] = {};

    Rot3() = default;

    Vec3 operator*(const Vec3 &v) const {
        return Vec3(
            mx[0][0] * v.x + mx[0][1] * v.y + mx[0][2] * v.z,
            mx[1][0] * v.x + mx[1][1] * v.y + mx[1][2] * v.z,
            mx[2][0] * v.x + mx[2][1] * v.y + mx[2][2] * v.z
        );
    }

    static Rot3 diag(double a, double b, double c) {
        Rot3 r;
        r.mx[0][0] = a;
        r.mx[1][1] = b;
        r.mx[2][2] = c;
        return r;
    }

    static Rot3 identity() {
        return diag(1.0, 1.0, 1.0);
    }

    static Rot3 rotX(const double angle) {
        Rot3 r;
        const double c = std::cos(angle);
        const double s = std::sin(angle);
        // clang-format off
        r.mx[0][0] = 1; r.mx[0][1] = 0; r.mx[0][2] =  0;
        r.mx[1][0] = 0; r.mx[1][1] = c; r.mx[1][2] = -s;
        r.mx[2][0] = 0; r.mx[2][1] = s; r.mx[2][2] =  c;
        // clang-format on
        return r;
    }

    static Rot3 rotY(const double angle) {
        Rot3 r;
        const double c = std::cos(angle);
        const double s = std::sin(angle);
        // clang-format off
        r.mx[0][0] =  c; r.mx[0][1] = 0; r.mx[0][2] = s;
        r.mx[1][0] =  0; r.mx[1][1] = 1; r.mx[1][2] = 0;
        r.mx[2][0] = -s; r.mx[2][1] = 0; r.mx[2][2] = c;
        // clang-format on
        return r;
    }

    static Rot3 rotZ(const double angle) {
        Rot3 r;
        const double c = std::cos(angle);
        const double s = std::sin(angle);
        // clang-format off
        r.mx[0][0] = c; r.mx[0][1] = -s; r.mx[0][2] = 0;
        r.mx[1][0] = s; r.mx[1][1] =  c; r.mx[1][2] = 0;
        r.mx[2][0] = 0; r.mx[2][1] =  0; r.mx[2][2] = 1;
        // clang-format on
        return r;
    }

    [[nodiscard]] Rot3 transpose() const {
        Rot3 t;
        for(int r=0; r<3; ++r)
            for(int c=0; c<3; ++c)
                t.mx[r][c] = mx[c][r];
        return t;
    }

    static double degToRad(const double deg) {
        return deg * M_PI / 180.0;
    }

    static Rot3 rotXDeg(const double angleDeg) {
        return rotX(degToRad(angleDeg));
    }

    static Rot3 rotYDeg(const double angleDeg) {
        return rotY(degToRad(angleDeg));
    }

    static Rot3 rotZDeg(const double angleDeg) {
        return rotZ(degToRad(angleDeg));
    }
};


#endif //SPRYX_ELEMS_H
