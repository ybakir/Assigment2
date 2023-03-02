#include <iostream>
#include <cmath>
using namespace std;

class points
{
	private:
		float x;
		float y;

	public:
		points()
		{
			x = 0;
			y = 0;
		}

		points(float x_value, float y_value)
		{
			x = x_value;
			y = y_value;
		}

		void setX(float x1)
		{
			x = x1;
		}

		void setY(float y1)
		{
			y = y1;
		}

		 float GetX()
		{
			 return x;
		}

		float GetY()
		{
			return y;
		}


		void display()
		{
			cout << "X value is " << x << endl;
			cout << "Y value is " << y << endl;
		}

		float distance(points u1, points u2)
		{
			float d;

			d = sqrt(pow((u2.x - u1.x), 2) + pow((u2.x - u1.x), 2));
			return d;
		}

};
