#include "0416329_matrix33.h"
#include "0416329_vector3.h"
#include <iostream>

using namespace std;

matrix33::matrix33(vector3 a, vector3 b, vector3 c)
{
    v1=a;
    v2=b;
    v3=c;
}

void matrix33::printMatrix() const
{
    cout << v1.x <<  " " << v2.x << " " <<  v3.x << endl;
    cout << v1.y <<  " " << v2.y << " " <<  v3.y << endl;
    cout << v1.z <<  " " << v2.z << " " <<  v3.z << endl;
}

matrix33::matrix33()
{
    v1=vector3();
    v2=vector3();
    v3=vector3();
}

vector3& matrix33::operator [] (unsigned int index)
{
    if (index==0)
        return this->v1;
    if (index==1)
        return this->v2;
    if (index==2)
        return this->v3;
}

const vector3& matrix33::operator [] (unsigned int index) const
{
    if (index==0)
        return v1;
    if (index==1)
        return v2;
    if (index==2)
        return v3;
}


matrix33 matrix33::invert()
{
    matrix33 temp;

    temp[0][0] = (this->v2[1]*this->v3[2]) - (this->v2[2]*this->v3[1]);
    temp[0][0] = temp[0][0] * -1;
    temp[0][1] = (this->v1[1]*this->v3[2]) - (this->v1[2]*this->v3[1]);
    temp[0][2] = (this->v1[1]*this->v2[2]) - (this->v1[2]*this->v2[1]);
    temp[0][2] = temp[0][2] * -1;
    temp[1][0] = (this->v2[0]*this->v3[2]) - (this->v2[2]*this->v3[0]);
    temp[1][1] = (this->v1[0]*this->v3[2]) - (this->v1[2]*this->v3[0]);
    temp[1][1] = temp[1][1] * -1;
    temp[1][2] = (this->v1[0]*this->v2[2]) - (this->v1[2]*this->v2[0]);
    temp[2][0] = (this->v2[0]*this->v3[1]) - (this->v2[1]*this->v3[0]);
    temp[2][0] = temp[2][0] * -1;
    temp[2][1] = (this->v1[0]*this->v3[1]) - (this->v1[1]*this->v3[0]);
    temp[2][2] = (this->v1[0]*this->v2[1]) - (this->v1[1]*this->v2[0]);
    temp[2][2] = temp[2][2] * -1;

    return temp;

}


matrix33 operator * (const matrix33 &m, const matrix33 &n)
{
    matrix33 mult_matrix;

    vector3 temp((m.v1.x*n.v1.x)+(m.v2.x*n.v1.y)+(m.v3.x*n.v1.z),(m.v1.y*n.v1.x)+(m.v2.y*n.v1.y)+(m.v3.y*n.v1.z),(m.v1.z*n.v1.x)+(m.v2.z*n.v1.y)+(m.v3.z*n.v1.z));
    vector3 temp1((m.v1.x*n.v2.x)+(m.v2.x*n.v2.y)+(m.v3.x*n.v2.z),(m.v1.y*n.v2.x)+(m.v2.y*n.v2.y)+(m.v3.y*n.v2.z),(m.v1.z*n.v2.x)+(m.v2.z*n.v2.y)+(m.v3.z*n.v2.z));
    vector3 temp2((m.v1.x*n.v3.x)+(m.v2.x*n.v3.y)+(m.v3.x*n.v3.z),(m.v1.y*n.v3.x)+(m.v2.y*n.v3.y)+(m.v3.y*n.v3.z),(m.v1.z*n.v3.x)+(m.v2.z*n.v3.y)+(m.v3.z*n.v3.z));

    mult_matrix.v1 = temp;
    mult_matrix.v2 = temp1;
    mult_matrix.v3 = temp2;

    return mult_matrix;

}

matrix33 matrix33::identity()
{
    this->v1=vector3(1,0,0);
    this->v2=vector3(0,1,0);
    this->v3=vector3(0,0,1);
    return *this;

}

matrix33 &matrix33::operator *= (float f)
{
    v1*=f;
    v2*=f;
    v3*=f;
    return *this;

}

matrix33 operator * (const matrix33 &m, float f)
{
    matrix33 temp;

    temp.v1 = m.v1*f;
    temp.v2 = m.v2*f;
    temp.v3 = m.v3*f;

    return temp;
}

matrix33 operator + (const matrix33 &m, const matrix33 &n)
{
    matrix33 temp;

    temp.v1 = (m.v1+n.v1);
    temp.v2 = (m.v2+n.v2);
    temp.v3 = (m.v3+n.v3);

    return temp;

}

bool operator == (const matrix33 &m, const matrix33 &n)
{
    if(m.v1==n.v1&&m.v2==n.v2&&m.v3==n.v3)
    {
        return 1;
    }else return 0;
}

bool operator != (const matrix33 &m, const matrix33 &n)
{
    if(m.v1==n.v1&&m.v2==n.v2&&m.v3==n.v3)
    {
        return 0;
    }
    else return 1;
}

float matrix33::determinant()
{
    float a,b,c;

    a=(v2.y*v3.z)-(v3.y*v2.z);
    b=(v1.y*v3.z)-(v3.y-v1.z);
    c=(v1.y*v2.z)-(v2.y-v3.z);

    return (a*v1.x)-(b*v2.x)+(c*v3.x);
}

