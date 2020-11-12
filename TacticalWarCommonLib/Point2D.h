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

		inline int getX() const {
			return x;
		}

		inline int getY() const {
			return y;
		}

		bool operator==(Point2D &p) const
		{
			return (x == p.getX() && y == p.getY());
		}
	};
}