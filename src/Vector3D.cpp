#include "Vector3D.h"
#include <cassert>
#include <math.h>
#include <ostream>

Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2)  {
    return Vector3D{vec1.m_xpos - vec2.m_xpos, vec1.m_ypos - vec2.m_ypos, vec1.m_zpos - vec2.m_zpos};
};

Vector3D operator+ (const Vector3D& vec1, const Vector3D& vec2) {
    return Vector3D{vec1.m_xpos + vec2.m_xpos, vec1.m_ypos + vec2.m_ypos, vec1.m_zpos + vec2.m_zpos};
};

double Vector3D::dotProduct(const Vector3D& vec2) const {
    return (m_xpos * vec2.m_xpos + m_ypos * vec2.m_ypos + m_zpos * vec2.m_zpos);
}

double Vector3D::getLength() const {
    return sqrt(m_xpos*m_xpos + m_ypos*m_ypos + m_zpos*m_zpos);
}

Vector3D Vector3D::normalisation() const {

    if (getLength() != 0) {
        return Vector3D {*this/getLength()};
    }
    return Vector3D {0,0,0};
}

std::ostream& operator<< (std::ostream& out, const Vector3D& vector)
{
    out << vector.m_xpos << ' ' << vector.m_ypos << ' ' << vector.m_zpos;

    return out;
}

Vector3D operator*(const Vector3D& vec1, double multiplier) {
    return Vector3D {vec1.m_xpos * multiplier, vec1.m_ypos * multiplier, vec1.m_zpos * multiplier};
};

 Vector3D operator/(const Vector3D& vec1, double divisor) {
     assert(divisor != 0);
     return Vector3D {vec1.m_xpos / divisor, vec1.m_ypos / divisor, vec1.m_zpos / divisor};
 };
