#include <SFML/Graphics.hpp>
#include "header.hpp"
using namespace std;
using namespace sf;

Point3D::Point3D()
{
	x = (float)(rand() % 99);
	y = (float)(rand() % 99);
	z = (float)(rand() % 99);
}

Point3D::Point3D(const float& newx, const float& newy, const float& newz)
{
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz)
{
	x = newx;
	y = newy;
	z = newz;
}

void Point3D::setX(const float& newx)
{
	x = newx;
}

void Point3D::setY(const float& newy)
{
	y = newy;
}

void Point3D::setZ(const float& newz)
{
	z = newz;
}

float Point3D::getX()
{
	return x;
}

float Point3D::getY()
{
	return y;
}

float Point3D::getZ()
{
	return z;
}

void Point3D::print()
{
	cout << "X : " << x << "  Y : " << y << "  Z : " << z << endl;
}

float Point3D::distanceTo(const Point3D& otherPoint3D)
{
	float rx = (otherPoint3D.x - x) * (otherPoint3D.x - x);
	float ry = (otherPoint3D.y - y) * (otherPoint3D.y - y);
	float rz = (otherPoint3D.z - z) * (otherPoint3D.z - z);
	return sqrt(rx + ry + rz);
}

Trajectory::Trajectory(int size)
{
	points = new Point3D[size];
	nbpts = size;
	float x = (float)(rand() % 11);
	float y = (float)(rand() % 11);
	float z = (float)(rand() % 11);
	float t;
	for (int i = 0; i < nbpts; i++)
	{
		t = (float)(rand() % 11);
		points[i].setXYZ(x * t, y * t, z * t);
	}
	float tmpx, tmpy, tmpz;
	for (int i = 0; i < nbpts; i++)
	{
		for (int i = 0; i < nbpts - 1; i++)
		{

			if (points[i].getX() > points[i + 1].getX() || points[i].getY() > points[i + 1].getY() || points[i].getZ() > points[i + 1].getZ())
			{
				tmpx = points[i].getX();
				tmpy = points[i].getY();
				tmpz = points[i].getZ();
				points[i].setXYZ(points[i + 1].getX(), points[i + 1].getY(), points[i + 1].getZ());
				points[i + 1].setXYZ(tmpx, tmpy, tmpz);
			}
		}
	}
}

void Trajectory::print()
{
	for (int i = 0; i < nbpts; i++)
	{
		points[i].print();
	}
}

Point3D& Trajectory::getPoint(const int& n)
{
	return points[n];
}

float Trajectory::getTotalDistance()
{
	float total = 0;
	for (int i = 0; i < nbpts - 1; i++)
	{
		total = total + (getPoint(i).distanceTo(getPoint(i + 1)));
	}
	return total;
}

float Trajectory::getFirstLastPointDistance()
{
	float distFirstLast = 0;
	distFirstLast = getPoint(0).distanceTo(getPoint(nbpts - 1));
	return distFirstLast;
}

void Trajectory::destructor()
{
	delete[] points;
}

Coureur::Coureur() 
{
	weight = 0;
	height = 0;
	shoes = 0;
	medspeed = 0;
	amountofweeks = 0;
	speed = 0;
	hydratation = 1;
	atmo = 0;
}

float Coureur::getWeight()
{
	return weight;
}

float Coureur::getHeight()
{
	return height;
}

float Coureur::getShoes()
{
	return shoes;
}

float Coureur::getMedSpeed()
{
	return medspeed;
}

float Coureur::getAmountOfWeeks()
{
	return amountofweeks;
}

float Coureur::getSpeed()
{
	return speed;
}

float Coureur::getHydratation()
{
	return hydratation;
}

float Coureur::getAtmo()
{
	return atmo;
}

void Coureur::setWeight(const float& newweight)
{
	weight = newweight;
}

void Coureur::setHeight(const float& newheight)
{
	height = newheight;
}

void Coureur::setShoes(const float& newshoes)
{
	shoes = newshoes;
}

void Coureur::setMedSpeed(const float& newmedspeed)
{
	medspeed = newmedspeed;
}

void Coureur::setAmountOfWeeks(const float& newamountofweeks)
{
	amountofweeks = newamountofweeks;
}

void Coureur::setSpeed(const float& newspeed)
{
	speed = newspeed;
}

void Coureur::setHydratation(const float& newhydratation)
{
	hydratation = newhydratation;
}

void Coureur::setAtmo(const float& newatmo)
{
	atmo = newatmo;
}

void Coureur::print()
{
	cout << "weight : " << weight << endl << "height : " << height << endl << "shoes : " << shoes << endl << "medspeed : " << medspeed << endl << "amountofweeks : " << amountofweeks << endl;
}

Participants::Participants(int number)
{
	coureurs = new Coureur[number];
	nbcoureurs = number;
}

Coureur& Participants::getCoureur(const int& n)
{
	return coureurs[n];
}
