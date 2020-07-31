#include "0416329_vector3.h"
#include <iostream>
#include <math.h>

using namespace std;

vector3::vector3(float inX, float inY, float inZ)
{
    x=inX;
    y=inY;
    z=inZ;
}

vector3::vector3(const vector3 &v)
{
     x=v.x;
    y=v.y;
    z=v.z;
}

vector3::vector3()
{
    x=0;
	y=0;
	z=0;
}

void vector3::printVector3() const
{
    cout << x  << "," << y << "," << z << endl;
}

float& vector3::operator [] (unsigned int index)
    {

	 if (index==0)
      return this->x;
      if (index==1)
      return this->y;
      if (index==2)
        return this->z;
	}

const float& vector3::operator [] (unsigned int index) const
	{
	    if (index==0)
      return x;
      if (index==1)
      return y;
      if (index==2)
        return z;
	}


vector3& vector3::operator= (const vector3 &v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;

    return *this;
}

vector3& vector3::operator+= (const vector3 &v)
{
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    this->z = this->z + v.z;

    return *this;
}

vector3& vector3::operator-= (const vector3 &v)
{
    this->x = this->x - v.x;
    this->y = this->y - v.y;
    this->z = this->z - v.z;

    return *this;
}

vector3& vector3::operator*= (float f)
{
    this->x = this->x * f;
    this->y = this->y * f;
    this->z = this->z * f;

    return *this;
}

vector3& vector3::operator/= (float f)
{
    this->x = this->x / f;
    this->y = this->y / f;
    this->z = this->z / f;

    return *this;
}

bool operator==(const vector3 &a, const vector3 &b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z) {

        return true;
    }
    else {
        return false;
    }
}

bool operator!=(const vector3 &a, const vector3 &b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z) {
        return false;
    }
    else {
        return true;
    }
}


vector3 operator+(const vector3 &a, const vector3 &b)
{
    vector3 temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    temp.z = a.z + b.z;

    return temp;
}

vector3 operator-(const vector3 &a, const vector3 &b)
{
    vector3 temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    temp.z = a.z - b.z;

    return temp;
}

vector3 operator*(const vector3 &v, float f)
{
    vector3 temp;
    temp.x = v.x*f;
    temp.y = v.y*f;
    temp.z = v.z*f;

    return temp;
}

vector3 operator* (float f, const vector3 &v)
{
    vector3 temp;
    temp.x = f*v.x;
    temp.y = f*v.y;
    temp.z = f*v.z;

    return temp;
}

vector3 operator/(const vector3 &v, float f)
{
    vector3 temp;
    temp.x = v.x * (1/f);
    temp.y = v.y * (1/f);
    temp.z = v.z * (1/f);

    return temp;
}


float vector3::length() const
{
    float l = sqrt((x*x)+(y*y)+(z*z));

    return l;
}




