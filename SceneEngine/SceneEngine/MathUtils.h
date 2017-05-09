#pragma once

class MathUtils
{
public:
	static const float PI;
	static float sine(float angle);
	static float cosine(float angle);
	static float tangent(float angle);

	~MathUtils() {}

private:
	MathUtils() {}
};

