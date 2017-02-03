#pragma once
#include "vector3.h"
#include "transformMatrix.h"
#include <array>

class Quaternion
{
private:
	enum Val { X = 0, Y, Z, W, NUMBER_OF_COMPONENTS};
	std::array<float, NUMBER_OF_COMPONENTS> vals;

	float getMagnitude() const;
	float getMagnitudeSqrd() const;
	bool isNormalized() const;
	void normalize();

	Quaternion normalized() const;

	Quaternion operator + (const Quaternion& other) const;
	Quaternion operator - (const Quaternion& other) const;
	Quaternion operator * (float scale) const;
	Quaternion operator / (float scale) const;
	Quaternion& operator += (const Quaternion& other);
	Quaternion& operator -= (const Quaternion& other);
	Quaternion& operator *= (float scale);
	Quaternion& operator /= (float scale);

	float operator[] (Val v) const;

public:
	Quaternion();
	Quaternion(const Quaternion& other);
	Quaternion(float x, float y, float z, float w);
	~Quaternion();

	static Quaternion identity();
	static Quaternion inverse(const Quaternion& original);
	static Quaternion concatenate(const Quaternion& a, const Quaternion& b);
	static Quaternion lerp(const Quaternion& from, const Quaternion& to, float val);
	static Quaternion slerp(const Quaternion& from, const Quaternion& to, float val);
	static float dot(const Quaternion& from, const Quaternion& to);
	
	static TransformMatrix makeTransformationMatrix(const Quaternion& from);

	void makeIdentity() { *this = identity(); }
	void concatenate(const Quaternion& other) { *this = concatenate(*this, other); }
	void inverse() { *this = inverse(*this); }

	void makeRotationXYZ(float x, float y, float z);
	void makeRotationZYX(float z, float y, float x);

	void makeRotationX(float x) { makeRotationXYZ(x, 0.0f, 0.0f); }
	void makeRotationY(float y) { makeRotationXYZ(0.0f, y, 0.0f); }
	void makeRotationZ(float z) { makeRotationXYZ(0.0f, 0.0f, z); }

	TransformMatrix getTransformationMatrix() const { return makeTransformationMatrix(*this); }

	Vector3 applyToPoint(const Vector3& point) const;
	Vector3 operator * (const Vector3& other) const { return this->applyToPoint(other); }

	Quaternion operator * (const Quaternion& other) const;
	Quaternion& operator *= (const Quaternion& other);
	
	Quaternion operator = (const Quaternion& other);
};

