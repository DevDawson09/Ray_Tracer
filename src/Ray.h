#ifndef RAY_TRACER_RAY_H
#define RAY_TRACER_RAY_H
#include "Vector3D.h"


class Ray {
private:
    Vector3D m_origin {};
    Vector3D m_direction {};
public:
    Ray(const Vector3D &origin, const Vector3D &direction)
        : m_origin{origin}, m_direction(direction)
    {}

    [[nodiscard]] Vector3D getDirection() const {return m_direction;}
    [[nodiscard]] Vector3D getOrigin() const {return m_origin;}

    [[nodiscard]] Vector3D at (const double time) const {return (m_origin + m_direction * time);}
};


#endif //RAY_TRACER_RAY_H
