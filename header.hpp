#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
using namespace sf;

class Point3D {
private:
	float x, y, z; // private attributes
public:
	// constuctors
	Point3D(); // fill X Y Z with random values (from 0 to 100)
	// Setters and getters
	void setXYZ(const float& newx, const float& newy, const float
		& newz);
	void setX(const float& newx);
	void setY(const float& newy);
	void setZ(const float& newz);
	float getX();
	float getY();
	float getZ();
	// other methods
	void print(); // prints the coordinates of the point
	float pente(const Point3D& otherPoint3D);
};

class Trajectory {
private:
	Point3D* points;
	int nbpts = 0;
public:
	void print(); // print the coordinates of all points
	Point3D& getPoint(const int& n); // returns the reference of point n
	Trajectory(int size);
};

class Coureur {
private:
	string name;
	int numdossard;
	float weight;
	float height;
	float shoes;
	float medspeed;
	float amountofweeks;
	float speed;
	float hydratation;
	float distance;
public:
	Coureur();
	string getName();
	int getNumDossard();
	float getWeight();
	float getHeight();
	float getShoes();
	float getMedSpeed();
	float getAmountOfWeeks();
	float getSpeed();
	float getHydratation();
	float getDistance();
	void setName(const string& newweight);
	void setNumDossard(const int& newnumdossard);
	void setWeight(const float& newweight);
	void setHeight(const float& newheight);
	void setShoes(const float& newshoes);
	void setMedSpeed(const float& newmedspeed);
	void setAmountOfWeeks(const float& newamountofweeks);
	void setSpeed(const float& newspeed);
	void setHydratation(const float& newhydratation);
	void setDistance(const float& newatmo);
	void print();
};

class Participants {
private:
	Coureur* coureurs;
	int nbcoureurs = 0;
public:
	Participants(int number);
	Coureur& getCoureur(const int& n); // returns the reference of coureur n
};

Participants getCoureurs(string text, int nbline);
Trajectory getParcours(string text, int nbline);
int numberOfLines(string text);