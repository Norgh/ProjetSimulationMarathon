#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>
#include<cmath>
#include <ctime>
using namespace std;
using namespace sf;

class Point3D {
private:
	float x, y, z; // private attributes
	bool ravitaillement;
public:
	// constuctors
	Point3D(); // fill X Y Z with random values (from 0 to 100)
	// Setters and getters
	void setXYZ(const float& newx, const float& newy, const float
		& newz);
	void setX(const float& newx);
	void setY(const float& newy);
	void setZ(const float& newz);
	void setRavitaillement(const bool& newravitaillement);
	float getX();
	float getY();
	float getZ();
	bool getRavitaillement();
	float distanceTo(const Point3D& otherPoint3D);
	// other methods
	void print(); // prints the coordinates of the point
	float pente(const Point3D& otherPoint3D);
};

class Trajectory {
private:
	Point3D* points;
	int nbpts = 0;
public:
	Point3D& getPoint(const int& n); // returns the reference of point n
	Trajectory(int size);
	void print();
};

class Coureur {
private:
	string name;
	int numdossard;
	float weight;
	float height;
	float shoes;
	float medspeed;
	int amountofweeks;
	float speed;
	float hydratation;
	float distance;
	bool abandon;
	int tempstotal = 0;
	bool isover = 0;
public:
	Coureur();
	string getName();
	int getNumDossard();
	float getWeight();
	float getHeight();
	float getShoes();
	float getMedSpeed();
	int getAmountOfWeeks();
	float getSpeed();
	float getHydratation();
	float getDistance();
	bool getAbandon();
	int getTotalTime();
	bool getIsOver();
	void setName(const string& newweight);
	void setNumDossard(const int& newnumdossard);
	void setWeight(const float& newweight);
	void setHeight(const float& newheight);
	void setShoes(const float& newshoes);
	void setMedSpeed(const float& newmedspeed);
	void setAmountOfWeeks(const int& newamountofweeks);
	void setSpeed(const float& newspeed);
	void setHydratation(const float& newhydratation);
	void setDistance(const float& newdistance);
	void setAbandon(const bool& newabandon);
	void setTotalTime(const int& newtotaltime);
	void setIsOver(const bool over);
	void print();
};

class Participants {
private:
	string text1 = "parcours.txt";
	string text2 = "coureurs.txt";
	int temps = 0;
	Coureur* coureurs;
	int nbcoureurs = 0;
	Point3D* parcours;
	int nbpts = 0;

public:
	Participants();
	float getPenteCoureur(const int& i);
	Coureur& getCoureur(const int& n); // returns the reference of coureur n
	void printPoints(); // print the coordinates of all points
	void printSpeed(); // print the speed
	void printTime();
	Point3D& getPoint(const int& n); // returns the reference of point n
	float getTotalDistance();
	float getDistanceTo(const int& point);
	void newSpeed();
	void setTime();
	void newHydratation(const int& i);
	void newDistance(const int& i);
	bool startMarathon();
};

int numberOfLines(string text);
float randomFloat(float const& min, float const& max);
void randomCoureurs(const int& nbcoureurs);