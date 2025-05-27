#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<iostream>

class vec3{

public:

    //for holding 3 dimensional double values
    double p[3];

    //constructors(default and paramterized)
    vec3():p{0,0,0}{}
    vec3(double p1,double p2,double p3):p{p1,p2,p3}{}

    //functions for returning coordinate values
    double x() const
    {
        return p[0];
    }
    double y() const
    {
        return p[1];
    }
    double z() const
    {
        return p[2];
    }

    //Operator overloaded functions for utility

    vec3 operator - () const 
    {
        return vec3(-p[0],-p[1],-p[2]);
    }

    double operator [](int i) const
    {
        return p[i];
    }

    double& operator[](int i)
    {
        return p[i];
    }

    vec3& operator+=(const vec3& v)
    {
        p[0]+=v.p[0];
        p[1]+=v.p[1];
        p[2]+=v.p[2];
        return *this;
    }


    vec3& operator*=(double t)
    {
        p[0]*=t;
        p[1]*=t;
        p[2]*=t;
        return *this;
    }

    vec3& operator/=(double t)
    {
        return *this *= 1/t;
    }

    double length_squared()const
    {
        return (p[0]*p[0])+(p[1]*p[1])+(p[2]*p[2]);
    }

    double length() const
    {
        return std::sqrt(length_squared());
    }

};

using point3=vec3;

//vector operations for vector utility

inline std::ostream& operator<< (std::ostream& out,const vec3& v)
{
    return out<<v.p[0]<<" "<<v.p[1]<<" "<<v.p[2];
}

inline vec3 operator+(const vec3& a,const vec3& b)
{
    return vec3(a.p[0]+b.p[0],a.p[1]+b.p[1],a.p[2]+b.p[2]);
}

inline vec3 operator-(const vec3& a,const vec3& b)
{
    return vec3(a.p[0]-b.p[0],a.p[1]-b.p[1],a.p[2]-b.p[2]);
}

inline vec3 operator*(const vec3& a,const vec3& b)
{
    return vec3(a.p[0]*b.p[0],a.p[1]*b.p[1],a.p[2]*b.p[2]);
}

inline vec3 operator*(const double t,const vec3& b)
{
    return vec3(t*b.p[0],t*b.p[1],t*b.p[2]);
}

inline vec3 operator*(const vec3& b,const double t)
{
    return t*b;
}

inline vec3 operator/(const vec3& a,double t)
{
    return (1/t)*a;
}

inline double dot(const vec3& a,const vec3& b)
{
    return (a.p[0]*b.p[0])+(a.p[1]*b.p[1])+(a.p[2]*b.p[2]);
}

inline vec3 cross(const vec3& a,const vec3& b)
{
    return vec3((a.p[1]*b.p[2]-a.p[2]*b.p[1]),
               (a.p[2]*b.p[0]-a.p[0]*b.p[2]),
            (a.p[0]*b.p[1]-a.p[1]*b.p[0]));
}

inline vec3 unit_vector(const vec3& v)
{
return v/v.length();
}

#endif
