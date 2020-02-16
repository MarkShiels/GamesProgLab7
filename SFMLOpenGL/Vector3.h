#pragma once
#include <math.h>
#include <iostream>

class MyVector3
{
public:

	float	m_x;
	float	m_y;
	float	m_z;

	void	setX(float t_x);
	void	setY(float t_y);
	void	setZ(float t_z);

	MyVector3();
	MyVector3(float t_x, float t_y, float t_z);
	~MyVector3();


	float	length();
	float	lengthSquared();
	void	normalise();


	 MyVector3	operator+(MyVector3 v1);
	 MyVector3	operator-(MyVector3 v1);
	 float		operator*(MyVector3 v1);
	 MyVector3	operator *(float k);
	 MyVector3	operator ^(MyVector3 V1);
	 MyVector3	operator - ();


	 friend MyVector3 operator+(const MyVector3& v1, const MyVector3& v2);
	 friend MyVector3 operator-(const MyVector3& v1, const MyVector3& v2);

	 void print();


	
};