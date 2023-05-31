#pragma once
#include <vector>
#include "Vector4.h"
#include "Vector3.h"
#include <math.h>

class Matrix4x4
{
public:
	float mat[16];

	Matrix4x4();
	Matrix4x4(const std::initializer_list<float> data);
		
	static Matrix4x4 identity();
	
	Matrix4x4 transpose();

	static Matrix4x4 translate3D(const Vector3& v);
	static Matrix4x4 scaling3D(const Vector3& v);
	static Matrix4x4 rotate3DX(float angle);
	static Matrix4x4 rotate3DY(float angle);
	static Matrix4x4 rotate3DZ(float angle);
	static Matrix4x4 rotate(const Vector3& angles);
	static Matrix4x4 TRS(const Matrix4x4& rota, const Vector3& trans, const Vector3& scale);
	static Matrix4x4 TRS(const Vector3& rota, const Vector3& trans, const Vector3& scale);

	static Matrix4x4 PerspectiveProjection(float fovy, float aspect, float zNear, float zFar);
	static Matrix4x4 ViewMatrix(const Vector3& eye, const Vector3& center, const Vector3& up);


	Matrix4x4 operator*(const Matrix4x4& a);
	Vector4 operator*(const Vector4& v);
};
