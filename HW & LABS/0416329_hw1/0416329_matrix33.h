#ifndef _0416329_MATRIX33_H_
#define _0416329_MATRIX33_H_
#include "0416329_vector3.h"
#include <iostream>

class matrix33
{
public:

    vector3 v1,v2,v3;

    matrix33(vector3 a, vector3 b, vector3 c);

    matrix33();


public:

    void printMatrix() const;

    matrix33 invert();

    matrix33 identity();

    float determinant();

    float smalldet(const float a,const float b,const float c,const float d);


public:


		vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;

	matrix33               &operator =  (const matrix33 &m);
	matrix33               &operator += (const matrix33 &m);
	matrix33               &operator -= (const matrix33 &m);
	matrix33               &operator *= (float f);
	matrix33               &operator *= (const matrix33 &n);
	matrix33               &operator /= (float f);
	friend bool           operator == (const matrix33 &m, const matrix33 &n);
	friend bool           operator != (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator - (const matrix33 &m);
	friend matrix33        operator + (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator - (const matrix33 &m, const matrix33 &n);
	friend matrix33        operator * (const matrix33 &m, float f);
	friend matrix33        operator * (float f, const matrix33 &m);
	friend matrix33        operator * (const matrix33 &m, const matrix33 &n);
    friend matrix33        operator / (const matrix33 &m, float f);

};

#endif
