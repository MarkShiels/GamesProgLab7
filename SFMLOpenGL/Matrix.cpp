#include "Matrix3.h"


// Constructor 1 create a zero matrix
Matrix3::Matrix3()
{
	m_A11 = 0.0;
	m_A12 = 0.0;
	m_A13 = 0.0;
	m_A21 = 0.0;
	m_A22 = 0.0;
	m_A23 = 0.0;
	m_A31 = 0.0;
	m_A32 = 0.0;
	m_A33 = 0.0;
}

// Constructor 2 To allow 3 rows of vectors to be declared as a matrix
Matrix3::Matrix3(MyVector3 r1, MyVector3 r2, MyVector3 r3)
{
	m_A11 = r1.m_x;
	m_A12 = r1.m_y;
	m_A13 = r1.m_z;
	m_A21 = r2.m_x;
	m_A22 = r2.m_y;
	m_A23 = r2.m_z;
	m_A31 = r3.m_x;
	m_A32 = r3.m_y;
	m_A33 = r3.m_z;
}

// Constructor 3 to allow nine float values
Matrix3:: Matrix3(float t_A11, float t_A12, float t_A13,
	float t_A21, float t_A22, float t_A23,
	float t_A31, float t_A32, float t_A33)
{
	m_A11 = t_A11;
	m_A12 = t_A12;
	m_A13 = t_A13;
	m_A21 = t_A21;
	m_A22 = t_A22;
	m_A23 = t_A23;
	m_A31 = t_A31;
	m_A32 = t_A32;
	m_A33 = t_A33;
}

// An overloaded operator * to return the  product of the matrix by a vector
MyVector3 Matrix3::operator *(MyVector3 V1)
{
	return MyVector3( (m_A11 * V1.m_x) + (m_A12 * V1.m_y) + (m_A13 * V1.m_z),
					(m_A21 * V1.m_x) + (m_A22 * V1.m_y) + (m_A23 * V1.m_z),
					(m_A31 * V1.m_x) + (m_A32 * V1.m_y) + (m_A33 * V1.m_z) );
}

// a method to transpose a given matrix
Matrix3 Matrix3::transpose()
{
	return Matrix3(m_A11, m_A21, m_A31,
				   m_A12, m_A22, m_A32,
				   m_A13, m_A23, m_A33);
}

// An overloaded operator + to return the  sum of two matrix 
Matrix3 Matrix3::operator +(Matrix3 M1)
{
	return Matrix3(m_A11 + M1.m_A11, m_A12 + M1.m_A12, m_A13 + M1.m_A13,
				    m_A21 + M1.m_A21, m_A22 + M1.m_A22, m_A23 + M1.m_A23,
					 m_A31 + M1.m_A31, m_A32 + M1.m_A32, m_A33 + M1.m_A33);
}

Matrix3 Matrix3::operator -(Matrix3 M1)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3(m_A11 - M1.m_A11, m_A12 - M1.m_A12, m_A13 - M1.m_A13,
				   m_A21 - M1.m_A21, m_A22 - M1.m_A22, m_A23 - M1.m_A23,
				   m_A31 - M1.m_A31, m_A32 - M1.m_A32, m_A33 - M1.m_A33);
}

// An overloaded operator * to return the  product of the matrix by a scalar
Matrix3 Matrix3::operator *(float x)
{
	Matrix3 answer;

	answer.m_A11 = m_A11 * x;
	answer.m_A12 = m_A12 * x;
	answer.m_A13 = m_A13 * x;

	answer.m_A21 = m_A21 * x;
	answer.m_A22 = m_A22 * x;
	answer.m_A23 = m_A23 * x;

	answer.m_A31 = m_A31 * x;
	answer.m_A32 = m_A32 * x;
	answer.m_A33 = m_A33 * x;

	return answer;
}

// An overloaded operator * to return the  product of two matrix
Matrix3 Matrix3::operator *(Matrix3 M1)
{
	Matrix3 answer;

	answer.m_A11 = (m_A11 * M1.m_A11) + (m_A12 * M1.m_A21) + (m_A13 * M1.m_A31);
	answer.m_A12 = (m_A11 * M1.m_A12) + (m_A12 * M1.m_A22) + (m_A13 * M1.m_A32);
	answer.m_A13 = (m_A11 * M1.m_A13) + (m_A12 * M1.m_A23) + (m_A13 * M1.m_A33);

	answer.m_A21 = (m_A21 * M1.m_A11) + (m_A22 * M1.m_A21) + (m_A23 * M1.m_A31);
	answer.m_A22 = (m_A21 * M1.m_A12) + (m_A22 * M1.m_A22) + (m_A23 * M1.m_A32);
	answer.m_A23 = (m_A21 * M1.m_A13) + (m_A22 * M1.m_A23) + (m_A23 * M1.m_A33);

	answer.m_A31 = (m_A31 * M1.m_A11) + (m_A32 * M1.m_A21) + (m_A33 * M1.m_A31);
	answer.m_A32 = (m_A31 * M1.m_A12) + (m_A32 * M1.m_A22) + (m_A33 * M1.m_A32);
	answer.m_A33 = (m_A31 * M1.m_A13) + (m_A32 * M1.m_A23) + (m_A33 * M1.m_A33);

	return answer;
}

// method to return the determinant of a 3x3 matrix
float Matrix3::determinant()
{
	//                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return (m_A11 * m_A22 * m_A33 - m_A11 * m_A32 * m_A23) + (m_A21 * m_A32 * m_A13 - m_A31 * m_A22 * m_A13) + (m_A31 * m_A12 * m_A23 - m_A21 * m_A12 * m_A33);
}


// a method to return as Row as MyVector3 1 == first row, default == last row
MyVector3 Matrix3::row(int i)
{
	switch (i)
	{
	case 1:
		return MyVector3(m_A11, m_A12, m_A13);
	case 2:
		return MyVector3(m_A21, m_A22, m_A23);
	case 3:
		return MyVector3(m_A31, m_A32, m_A33);
	default:
		break;
	}
}

// a method to return as column as MyVector3 1 == first column
MyVector3 Matrix3::column(int i)
{
	switch (i)
	{
	case 1:
		return MyVector3(m_A11, m_A21, m_A31);
	case 2:
		return MyVector3(m_A12, m_A22, m_A32);
	case 3:
		return MyVector3(m_A13, m_A23, m_A33);
	default:
		break;
	}
}

Matrix3 Matrix3::inverse()
{
	float det = determinant();
	if (det == 0)
		return Matrix3();
	else
	{
		float scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.m_A11 = scale * (m_A22 * m_A33 - m_A23 * m_A32); // ei-fh
		answer.m_A12 = scale * (m_A13 * m_A32 - m_A12 * m_A33); // ch-bi
		answer.m_A13 = scale * (m_A12 * m_A23 - m_A13 * m_A22); // ch-bi

		answer.m_A21 = scale * (m_A23 * m_A31 - m_A21 * m_A33); // fg-di
		answer.m_A22 = scale * (m_A11 * m_A33 - m_A13 * m_A31); // ai-cg
		answer.m_A23 = scale * (m_A13 * m_A21 - m_A11 * m_A23); // cd-af

		answer.m_A31 = scale * (m_A21 * m_A32 - m_A22 * m_A31); // dh-eg
		answer.m_A32 = scale * (m_A12 * m_A31 - m_A11 * m_A32); // bg-ah
		answer.m_A33 = scale * (m_A11 * m_A22 - m_A12 * m_A21); // ae-bd

		return answer;
	}

}

Matrix3 Matrix3::rotation(float angle)
{
	float radians = M_PI / 180 * angle;
	Matrix3 answer = Matrix3();

	answer.m_A11 = cos(radians);
	answer.m_A12 = sin(radians);
	answer.m_A13 = 0;
	answer.m_A21 = -sin(radians);
	answer.m_A22 = cos(radians);
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;

	return answer;
}

Matrix3 Matrix3::translate(float dx, float dy)
{
	Matrix3 answer = Matrix3();
	answer.m_A11 = 1;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = 1;
	answer.m_A23 = 0;
	answer.m_A31 = dx;
	answer.m_A32 = dy;
	answer.m_A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale(float dx, float dy)
{
	Matrix3 answer = Matrix3();
	answer.m_A11 = dx / 100;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = dy / 100;
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;

	return answer;
}

Matrix3 Matrix3::operator -()
{
	return operator*(-1);
}

Matrix3 Matrix3::rotationX(float angle)
{
	float radians = M_PI / 180 * angle;
	Matrix3 answer = Matrix3();
	answer.m_A11 = 1;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = cos(radians);
	answer.m_A23 = -sin(radians);
	answer.m_A31 = 0;
	answer.m_A32 = sin(radians);
	answer.m_A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::rotationY(float angle)
{
	float radians = M_PI / 180 * angle;
	Matrix3 answer = Matrix3();
	answer.m_A11 = cos(radians);
	answer.m_A12 = 0;
	answer.m_A13 = sin(radians);
	answer.m_A21 = 0;
	answer.m_A22 = 1;
	answer.m_A23 = 0;
	answer.m_A31 = -sin(radians);
	answer.m_A32 = 0;
	answer.m_A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::rotationZ(float angle)
{
	float radians = M_PI / 180 * angle;
	Matrix3 answer = Matrix3();
	answer.m_A11 = cos(radians);
	answer.m_A12 = -sin(radians);
	answer.m_A13 = 0;
	answer.m_A21 = sin(radians);
	answer.m_A22 = cos(radians);
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;

	return answer;
}

Matrix3 Matrix3::scale3D(float dx)
{
	Matrix3 answer = Matrix3();
	answer.m_A11 = dx / 100;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = dx / 100;
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = dx / 100;

	return answer;
}