#include "transformMatrix.h"

void makeTransformFromRotation(TransformMatrix* matrix, float pitch, float yaw, float roll)
{
}

void makeTransformFromScale(TransformMatrix* matrix, float x, float y, float z)
{
}

void makeTransformFromUniformScale(TransformMatrix* matrix, float uniformScale)
{
}

void makeTransformFromTranslation(TransformMatrix* matrix, float dX, float xY, float dZ)
{
}

void inverseTransform(TransformMatrix* matrix)
{
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
