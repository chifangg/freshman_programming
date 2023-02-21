#include<iostream>
#include<string>
#include"function.h"

namespace oj
{
		
	Sphere::Sphere(double a, double b)
	{
		this -> radius = a;
		this -> pi = b;
		if(a > 0 && b > 0)
		setVolume(4.0/3.0 * b * a * a * a);
		else
		setVolume(0);
		
	}
	Cone::Cone(double a, double b, double c)
	{
		this -> radius = a;
		this -> height = b;
		this -> pi = c;
		if(a > 0 && b > 0 && c > 0)
		setVolume(1.0/3.0 * c * a * a * b);
		else
		setVolume(0);
	}
	Cuboid::Cuboid(double a, double b, double c)
	{
		this -> length = a;
		this -> width = b;
		this -> height = c;
		if(a > 0 && b > 0 && c > 0)
		setVolume(a * b * c);
		else
		setVolume(0);
	}
	Cube::Cube(double a) : Cuboid::Cuboid(a, a, a)
	{
		if(a > 0)
		setVolume(a * a * a);
		else
		setVolume(0); 
		
	}
	
}








