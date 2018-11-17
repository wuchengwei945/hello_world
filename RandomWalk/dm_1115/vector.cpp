#include "pch.h"
#include <iostream>
#include <cmath>
#include "vector.h"


using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::sqrt;
using std::cout;
using std::endl;
using std::ostream;

namespace VECTOR {

	const double Rag_to_deg = 45.0 / atan(1.0);

	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		mag = ang = x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form== POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument for Vector() "
				<< "Reset argument to default"<<endl;
			mag = ang = x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument for Vector() "
				<< "Reset argument to default" << endl;
			mag = ang = x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x*n, y*n);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector::operator double() const
	{
		return mag;
	}

	//friend function
	Vector operator*(double n, const Vector & b)
	{
		return b * n;
	}

	ostream & operator<<(ostream & co, const Vector & b)
	{
		if (b.mode == Vector::RECT)
		{
			co << "(" << b.x << ", " << b.y << ")\n";
		}
		else if (b.mode == Vector::POL)
		{
			co << "(m,a): (" << b.mag << "," << b.ang*Rag_to_deg <<")";
		}
		else
			co << "The Vector's mode is wrong." << endl;
		return co;
	}


}