#pragma once
namespace tw
{
	class Point2D
	{
		int x;
		int y;

	public:
		Point2D(int x, int y);
		~Point2D();

		inline int getX() {
			return x;
		}

		inline int getY() {
			return y;
		}
	};
}