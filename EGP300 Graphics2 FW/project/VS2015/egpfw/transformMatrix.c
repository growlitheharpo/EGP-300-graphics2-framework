#include "transformMatrix.h"
#include <math.h>

void makeIdentiyMatrix(TransformMatrix* matrix)
{
	matrix->r1c1 = 1.0f;
	matrix->r1c2 = 0.0f;
	matrix->r1c3 = 0.0f;
	matrix->r1c4 = 0.0f;
	matrix->r2c1 = 0.0f;
	matrix->r2c2 = 1.0f;
	matrix->r2c3 = 0.0f;
	matrix->r2c4 = 0.0f;
	matrix->r3c1 = 0.0f;
	matrix->r3c2 = 0.0f;
	matrix->r3c3 = 1.0f; 
	matrix->r3c4 = 0.0f;
}

void makeXDirectionTransformMatrix(TransformMatrix* matrix, float amount)
{
	makeIdentiyMatrix(matrix);
	matrix->r2c2 = cos(amount);
	matrix->r2c3 = sin(amount) * -1.0f;
	matrix->r3c2 = matrix->r2c3 * -1.0f;
	matrix->r3c3 = matrix->r2c2;
}

void makeYDirectionTransformMatrix(TransformMatrix* matrix, float amount)
{
	makeIdentiyMatrix(matrix);
	matrix->r1c1 = cos(amount);
	matrix->r1c3 = sin(amount);
	matrix->r3c1 = matrix->r3c1 * -1.0f;
	matrix->r3c3 = matrix->r1c1;
}

void makeZDirectionTransformMatrix(TransformMatrix* matrix, float amount)
{
	makeIdentiyMatrix(matrix);
	matrix->r1c1 = cos(amount);
	matrix->r1c2 = sin(amount) * -1.0f;
	matrix->r2c1 = matrix->r1c2 * -1.0f;
	matrix->r2c2 = matrix->r1c1;
}

void makeTransformFromRotation(TransformMatrix* matrix, float pitch, float yaw, float roll)
{
	TransformMatrix x, y, z, result;
	makeXDirectionTransformMatrix(&x, pitch);
	makeYDirectionTransformMatrix(&y, yaw);
	makeZDirectionTransformMatrix(&z, roll);

	concatenateTransform(&result, &y, &x);
	concatenateTransform(matrix, &z, &result);
}

void makeTransformFromScale(TransformMatrix* matrix, float x, float y, float z)
{
	makeIdentiyMatrix(matrix);
	matrix->r1c1 = x;
	matrix->r2c2 = y;
	matrix->r3c3 = z;
}

void makeTransformFromUniformScale(TransformMatrix* matrix, float uniformScale)
{
	makeTransformFromScale(matrix, uniformScale, uniformScale, uniformScale);
}

void makeTransformFromTranslation(TransformMatrix* matrix, float dX, float dY, float dZ)
{
	makeIdentiyMatrix(matrix);
	matrix->r1c4 = dX;
	matrix->r2c4 = dY;
	matrix->r3c4 = dZ;
}

void inverseTransform(TransformMatrix* matrix)
{
}

int areTransformsEqual(TransformMatrix* a, TransformMatrix* b)
{
	if (a->r1c1 == b->r1c1 && a->r1c2 == b->r1c2 && a->r1c3 == b->r1c3 && a->r1c4 == b->r1c4 &&
		a->r2c1 == b->r2c1 && a->r2c2 == b->r2c2 && a->r2c3 == b->r2c3 && a->r2c4 == b->r2c4 &&
		a->r3c1 == b->r3c1 && a->r3c2 == b->r3c2 && a->r3c3 == b->r3c3 && a->r3c4 == b->r3c4)
		return 1;
	return 0;
}

void concatenateTransform(TransformMatrix* matrixOut, TransformMatrix* matrixLeft, TransformMatrix* matrixRight)
{
}

void applyTransformToPoint(Vector3* pointInOut, TransformMatrix const* transform)
{
}

void runTransformTestSuite()
{

}
