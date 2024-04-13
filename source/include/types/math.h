#ifndef SARDELKA_MATH_H
#define SARDELKA_MATH_H

#include <include/core/proto-core.h>
#include <include/types/math/math_complex.h>


// alias
typedef			double				precision;


namespace SARDELKA
{
	// constants
	const precision pi	=	3.1415926535897932; // 16 digits precision
	const precision c	=	299792458; // meters/second, speed of electromagnetic wave in vacuum
	
	// fwd
	struct		Vec2;
	struct		Vec3;
	
	precision	vec2_product_scalar(const Vec2& vec1, const Vec2& vec2);
	precision	vec3_product_scalar(const Vec3& vec1, const Vec3& vec2);
	
	// alias
	typedef 	Vec2				cplx;
	
	// implementation
	struct Vec2
	{
		precision x = 0.0; // meters
		precision y = 0.0; // meters
		
		Vec2(precision x_, precision y_) : x(x_), y(y_) {}
		Vec2(precision x_) : x(x_), y(x_) {}
		
		bool operator=(const Vec2& vec)
		{
			x = vec.x;
			y = vec.y;
			return true;
		}
		
		Vec2 operator+(const Vec2& vec)
		{
			precision x_, y_;
			x_ = x + vec.x;
			y_ = y + vec.y;
			return Vec2(x_, y_);
		}
		
		Vec2 operator-(const Vec2& vec)
		{
			precision x_, y_;
			x_ = x - vec.x;
			y_ = y - vec.y;
			return Vec2(x_, y_);
		}
		
		bool operator==(const Vec2& vec)
		{
			bool isEqual = false;
			if ((x == vec.x) && (y == vec.y))
				isEqual = true;
			return isEqual;
		}
		
		bool operator+=(const Vec2& vec)
		{
			x += vec.x;
			y += vec.y;
			return true;
		}
		
		bool operator-=(const Vec2& vec)
		{
			x -= vec.x;
			y -= vec.y;
			return true;
		}
		
		precision operator*(const Vec2& vec2)
		{
			return vec2_product_scalar(*this, vec2);
		}
	};
	
	struct Vec3
	{
		precision x = 0.0; // meters
		precision y = 0.0; // meters
		precision z = 0.0; // meters
		
		Vec3(precision x_, precision y_, precision z_) : x(x_), y(y_), z(z_) {}
		Vec3(precision x_) : x(x_), y(x_), z(x_) {}
		
		bool operator=(const Vec3& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
			return true;
		}
		
		Vec3 operator+(const Vec3& vec)
		{
			precision x_, y_, z_;
			x_ = x + vec.x;
			y_ = y + vec.y;
			z_ = z + vec.z;
			return Vec3(x_, y_, z_);
		}
		
		Vec3 operator-(const Vec3& vec)
		{
			precision x_, y_, z_;
			x_ = x - vec.x;
			y_ = y - vec.y;
			z_ = z - vec.z;
			return Vec3(x_, y_, z_);
		}
		
		bool operator==(const Vec3& vec)
		{
			bool isEqual = false;
			if ((x == vec.x) && (y == vec.y) && (z == vec.z))
				isEqual = true;
			return isEqual;
		}
		
		bool operator+=(const Vec3& vec)
		{
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return true;
		}
		
		bool operator-=(const Vec3& vec)
		{
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return true;
		}
		
		precision operator*(const Vec3& vec2)
		{
			return vec3_product_scalar(*this, vec2);
		}
	};
	
	precision vec2_product_scalar(const Vec2& vec1, const Vec2& vec2)
	{
		precision result = 0;
		result = (vec1.x * vec2.x) + (vec1.y * vec2.y);
		return result;
	}
	
	precision vec3_product_scalar(const Vec3& vec1, const Vec3& vec2)
	{
		precision result = 0;
		result = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
		return result;
	}
}

#endif
