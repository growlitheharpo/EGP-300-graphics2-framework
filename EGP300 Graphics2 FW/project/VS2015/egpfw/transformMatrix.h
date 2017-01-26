#ifndef __TRANSFORM_MATRIX_H
#define __TRANSFORM_MATRIX_H


#ifdef __cplusplus
extern "C"
{
#endif	// __cplusplus

struct Vector3_struct;
typedef struct Vector3_struct Vector3;

typedef struct TransformMatrix_struct
{
	float r1c1, r1c2, r1c3, r1c4,
		r2c1, r2c2, r2c3, r2c4,
		r3c1, r3c2, r3c3, r3c4;
} TransformMatrix;

void makeTransformFromRotation(TransformMatrix* matrix, float pitch, float yaw, float roll);
void makeTransformFromScale(TransformMatrix* matrix, float x, float y, float z);
void makeTransformFromUniformScale(TransformMatrix* matrix, float uniformScale);
void makeTransformFromTranslation(TransformMatrix* matrix, float dX, float xY, float dZ);
void inverseTransform(TransformMatrix* matrix);
void concatenateTransform(TransformMatrix* matrixOut, TransformMatrix* matrixLeft, TransformMatrix* matrixRight);
void applyTransformToPoint(Vector3* pointInOut, TransformMatrix const* transform);

void runTransformTestSuite();


#ifdef __cplusplus
}
#endif	// __cplusplus


#endif