#include "MathUtils.h"

#include <math.h>

const float MathUtils::PI = 3.14159265358979323846f;

float MathUtils::sine(float angle)
{
	return sin(angle);
}

float MathUtils::cosine(float angle)
{
	return cos(angle);
}

float MathUtils::tangent(float angle)
{
	return tan(angle);
}
