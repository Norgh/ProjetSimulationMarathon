#include <SFML/Graphics.hpp>
#include "header.hpp"
using namespace std;
using namespace sf;

Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
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

float Point3D::pente(const Point3D& otherPoint3D)
{
	float rx = (otherPoint3D.x - x);
	float ry = (otherPoint3D.y - y);
	return ((ry / rx) * 100);
}

Trajectory::Trajectory(int size)
{
	points = new Point3D[size];
	nbpts = size;
	for (int i = 0; i < nbpts-1; i++)
	{
		points[i].setXYZ(0, 0, 0);
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

Coureur::Coureur() 
{
	name = "AZERTY";
	numdossard = 0;
	weight = 0;
	height = 0;
	shoes = 0;
	medspeed = 0;
	amountofweeks = 0;
	speed = 0;
	hydratation = 1;
	distance = 0;
}

string Coureur::getName()
{
	return name;
}

int Coureur::getNumDossard()
{
	return numdossard;
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

float Coureur::getDistance()
{
	return distance;
}

void Coureur::setName(const string& newname)
{
	name = newname;
}

void Coureur::setNumDossard(const int& newnumdossard)
{
	numdossard = newnumdossard;
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

void Coureur::setDistance(const float& newatmo)
{
	distance = newatmo;
}

void Coureur::print()
{
	cout << "Name : " << name << endl << "Num\x82ro de dossard : " << numdossard << endl << "weight : " << weight << endl << "height : " << height << endl << "shoes : " << shoes << endl << "medspeed : " << medspeed << endl << "amountofweeks : " << amountofweeks << endl << endl;
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
