#include "Vector3.h"

void MyVector3::setX(float t_x)
{
	m_x = t_x;
}

void MyVector3::setY(float t_y)
{
	m_y = t_y;
}

void MyVector3::setZ(float t_z)
{
	m_z = t_z;
}

MyVector3::MyVector3()
{
	setX(0.0f);
	setY(0.0f);
	setZ(0.0f);
}

MyVector3::MyVector3(float t_x, float t_y, float t_z)
{
	setX(t_x);
	setY(t_y);
	setZ(t_z);
}

MyVector3::~MyVector3()
{
}

float MyVector3::length()
{
	// A method to return the length of the vector
	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

float MyVector3::lengthSquared()
{
	// A method to return the length squared of the vector
	return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
}

void MyVector3::normalise()
{
	// A method to reduce the length of the vector to 1.0 
	// keeping the direction the same
		if (length() > 0.0)
		{  // Check for divide by zero
			float magnitude = length();
			m_x /= magnitude;
			m_y /= magnitude;
			m_z /= magnitude;
		}
}

MyVector3 MyVector3::operator+(MyVector3 v1)
{
	return MyVector3(m_x + v1.m_x, m_y + v1.m_y, m_z + v1.m_z);
}

MyVector3 MyVector3::operator-(MyVector3 v1)
{
	return MyVector3(m_x - v1.m_x, m_y - v1.m_y, m_z - v1.m_z);
}

float MyVector3::operator*(MyVector3 v1)
{
	return float(m_x * v1.m_x + m_y * v1.m_y + m_z * v1.m_z);
}

 MyVector3 operator+(const MyVector3& v1, const MyVector3& v2)
{
	// An overloaded operator + to return the sum of 2 vectors
	return MyVector3(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

 MyVector3 operator-(const MyVector3& v1, const MyVector3& v2)
 {
	 // An overloaded operator - to return the difference of 2 vectors
	 return MyVector3(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
 }

 MyVector3 MyVector3::operator - ()
 {
	 // An overloaded operator - to return the negation of a single vector
	 return MyVector3(m_x = -m_x, m_y = -m_y, m_z = -m_z);
 }

MyVector3 MyVector3::operator *(float k)
 {
	// An overloaded operator * to return the product of a scalar by a vector
	 return MyVector3(m_x * k, m_y * k, m_z * k);
 }

MyVector3 MyVector3::operator ^(MyVector3 V1)
{
	// An overloaded operator ^ to return the vector product of 2 vectors
	return MyVector3((m_y * V1.m_z - m_z * V1.m_y), -(m_x * V1.m_z - m_z * V1.m_x), (m_x * V1.m_y - m_y * V1.m_x));
}

void MyVector3::print()
{
	std::cout << " " << m_x << " " << m_y << " " << m_z << std::endl;
}