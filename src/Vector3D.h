//
// Created by kaicd on 15/11/2026.
//

#ifndef RAY_TRACER_VECTOR3D_H
#define RAY_TRACER_VECTOR3D_H
#include <iosfwd>


class Vector3D {
private:
    double m_xpos {};
    double m_ypos {};
    double m_zpos {};

public:
    explicit Vector3D(double xpos =0.0, double ypos =0.0, double zpos =0.0)
        : m_xpos{xpos}, m_ypos{ypos}, m_zpos{zpos}
    {}

    friend Vector3D operator+ (const Vector3D& vec1, const Vector3D& vec2);
    friend Vector3D operator-(const Vector3D& vec1, const Vector3D& vec2);
    friend Vector3D operator*(const Vector3D& vec1, double multiplier);
    friend Vector3D operator*(const Vector3D& vec1, const Vector3D& vec2);
    friend Vector3D operator/(const Vector3D& vec1, double divisor);
    friend Vector3D operator/(const Vector3D& vec1, const Vector3D& vec2);


    [[nodiscard]] double dotProduct(const Vector3D& vec2) const;
    [[nodiscard]] double getLength () const;
    [[nodiscard]] Vector3D normalisation()const;


    [[nodiscard]] double get_xpos() const {return m_xpos;}
    [[nodiscard]] double get_ypos() const {return m_ypos;}
    [[nodiscard]] double get_zpos() const {return m_zpos;}

    Vector3D operator*=(double multiplier) {m_xpos *= multiplier, m_ypos *= multiplier, m_zpos *= multiplier; return *this;}
    Vector3D operator/=(double divisor) {m_xpos /= divisor, m_ypos /= divisor, m_zpos /= divisor; return *this;}
    bool operator!() const {return (m_xpos ==0 and m_ypos == 0 and m_zpos == 0);}

    friend std::ostream& operator<< (std::ostream& out, const Vector3D& vector);
};


#endif //RAY_TRACER_VECTOR3D_H
