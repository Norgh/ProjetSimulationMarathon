#include <SFML/Graphics.hpp>
#include "header.hpp"
using namespace std;
using namespace sf;

Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
	ravitaillement = 0;
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
void Point3D::setRavitaillement(const bool& newravitaillement)
{
	ravitaillement = newravitaillement;
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

bool Point3D::getRavitaillement()
{
	return ravitaillement;
}

float Point3D::distanceTo(const Point3D& otherPoint3D)
{
	float rx = (otherPoint3D.x - x) * (otherPoint3D.x - x);
	float ry = (otherPoint3D.y - y) * (otherPoint3D.y - y);
	return sqrt(rx + ry);
}

void Point3D::print()
{
	cout << "X : " << x << "  Y : " << y << "  Z : " << z << " R : " << ravitaillement << endl;
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
	float x;
	float y;
	float z=0;
	for (int i = 1; i < nbpts; i++)
	{
		x = randomFloat(0, 42.195);
		y = randomFloat(-0.250, 0.250);

		points[i].setXYZ(x, y, z);
	}
	float tmpx, tmpy, tmpz;
	for (int j = 0; j < nbpts; j++)
	{
		for (int i = 0; i < nbpts - 1; i++)
		{
			if (points[i].getX() > points[i + 1].getX())
			{
				tmpx = points[i].getX();
				tmpy = points[i].getY();
				tmpz = points[i].getZ();
				points[i].setXYZ(points[i + 1].getX(), points[i + 1].getY(), points[i + 1].getZ());
				points[i + 1].setXYZ(tmpx, tmpy, tmpz);
			}
		}
	}
	points[nbpts - 1].setXYZ(42.195, 0, 0);
	int rav = 0;
	int i = 0;
	while (rav < 8 && i< nbpts-10)
	{
		if(points[i].distanceTo(points[i + 4])>10)
		{
			points[i + 4].setRavitaillement(1);
			rav++;
			i+=4;
		}
		else
		{
			if (points[i].distanceTo(points[i + 4]) < 5)
			{
				points[i + 9].setRavitaillement(1);
				rav++;
				i += 9;
			}
			else
			{
				points[i + 7].setRavitaillement(1);
				rav++;
				i += 7;
			}
		}
	}

	ofstream file;
	file.open("parcours.txt");
	for (int i = 0;i < nbpts;i++)
	{
		file << points[i].getX() << " " << points[i].getY() << " " << points[i].getZ() << " " << points[i].getRavitaillement() << endl;
	}
	file.close();
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
	name = " ";
	numdossard = 0;
	weight = 0;
	height = 0;
	shoes = 0;
	medspeed = 0;
	amountofweeks = 0;
	speed = 0;
	hydratation = 1;
	distance = 0;
	abandon = 0;
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

int Coureur::getAmountOfWeeks()
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

bool Coureur::getAbandon()
{
	return abandon;
}

int Coureur::getTotalTime()
{
	return tempstotal;
}

bool Coureur::getIsOver()
{
	return isover;
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

void Coureur::setAmountOfWeeks(const int& newamountofweeks)
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

void Coureur::setDistance(const float& newdistance)
{
	distance = newdistance;
}

void Coureur::setAbandon(const bool& newabandon) 
{
	abandon = newabandon;
}

void Coureur::setTotalTime(const int& newtotaltime) 
{
	tempstotal = newtotaltime;
}

void Coureur::setIsOver(const bool over)
{
	isover = over;
}

void Coureur::print()
{
	cout << "Name : " << name << endl << "Num\x82ro de dossard : " << numdossard << endl << "weight : " << weight << endl << "height : " << height << endl << "shoes : " << shoes << endl << "medspeed : " << medspeed << endl << "amountofweeks : " << amountofweeks << endl << endl;
}

Participants::Participants()
{
	coureurs = new Coureur[numberOfLines(text2)];
	nbcoureurs = numberOfLines(text2);
	parcours = new Point3D[numberOfLines(text1)];
	nbpts = numberOfLines(text1);
	ifstream file;
	file.open(text1);
	string line;
	string word;
	if (file.is_open())
	{
		int i = 0;
		int c = 0;
		float p1=0, p2=0, p3=0;
		while (!file.eof())
		{
			getline(file, line);
			stringstream ss(line);
			c = 0;
			while (ss >> word)
			{
				if (c == 0)
				{
					p1 = stof(word);
				}
				if (c == 1)
				{
					p2 = stof(word);
					
				}
				if (c == 2)
				{
					p3 = stof(word);
	
				}
				if (c == 3)
				{
					if (word == "0")
					{
						parcours[i].setRavitaillement(0);
					}
					else if (word == "1")
					{
						parcours[i].setRavitaillement(1);
					}
				}
				parcours[i].setXYZ(p1,p2,p3);
				c++;
			}
			i++;
		}
		file.close();
	}

	ifstream file2;
	file2.open(text2);
	if (file2.is_open())
	{
		int i = 0;
		int c = 0;
		float stat = 0;
		int stat2 = 0;
		while (!file2.eof())
		{
			getline(file2, line);
			stringstream ss(line);
			c = 0;
			while (ss >> word)
			{
				if (c == 0)
				{
					coureurs[i].setName(word);
				}
				if (c == 1)
				{
					stat2 = stoi(word);
					coureurs[i].setNumDossard(stat2);
				}
				if (c == 2)
				{
					stat = stof(word);
					coureurs[i].setWeight(stat);
				}
				if (c == 3)
				{
					stat = stof(word);
					coureurs[i].setHeight(stat);
				}
				if (c == 4)
				{
					stat = stof(word);
					coureurs[i].setShoes(stat);
				}
				if (c == 5)
				{
					stat = stof(word);
					coureurs[i].setMedSpeed(10*stat/3.6);
					coureurs[i].setSpeed(10*stat/3.6);
				}
				if (c == 6)
				{
					stat2 = stoi(word);
					coureurs[i].setAmountOfWeeks(stat2);
				}
				c++;
			}
			i++;
		}
		file2.close();
	}
	float newspeed = 0;
	for (int i = 0; i < nbcoureurs; i++)
	{
		newspeed = (coureurs[i].getSpeed() * (100 - (coureurs[i].getShoes() * 1.1/100))/100);
		coureurs[i].setSpeed(newspeed);
	}
}

Coureur& Participants::getCoureur(const int& n)
{
	return coureurs[n];
}

void Participants::printPoints()
{
	for (int i = 0; i < nbpts; i++)
	{
		parcours[i].print();
	}
}

void Participants::printSpeed() 
{
	cout << coureurs[3].getSpeed();
}

void Participants::printTime()
{
	cout << "Time : " << temps << endl;
}

Point3D& Participants::getPoint(const int& n)
{
	return parcours[n];
}

float Participants::getTotalDistance()
{
	float total = 0;
	for (int i = 0; i < nbpts - 1; i++)
	{
		total += (getPoint(i).distanceTo(getPoint(i + 1)));
	}
	return total;
}

float Participants::getDistanceTo(const int& point)
{
	float total = 0;
	for (int i = 0; i < point - 1; i++)
	{
		total += (getPoint(i).distanceTo(getPoint(i + 1)));
	}
	return total;
}
void Participants::setTime()
{
	temps +=1;
}

float Participants::getPenteCoureur(const int& i)
{
	float newpente = 0;
	float distCoureur = coureurs[i].getDistance();
	int j = 0;
	float distParcours=0;
	do {
		distParcours = getDistanceTo(j);
			j++;
	} 
	while (distCoureur > distParcours);
	if (distParcours >= distCoureur)
	{
		newpente = parcours[j-1].pente(parcours[j]);
	}
	return newpente;
}

void Participants::newSpeed() 
{
	//float pente = 0;
	//for (int i = 0 ; i < nbcoureurs; i++)
	//{
	//	// Weeks of preparation
	//	if (coureurs[i].getAmountOfWeeks()==8)
	//	{
	//		if (coureurs[i].getDistance() > (getTotalDistance() / 2))
	//		{
	//			if (coureurs[i].getSpeed() > 0.8*((coureurs[i].getMedSpeed() * (100 - (coureurs[i].getShoes() * 1.1 / 100)) / 100)))
	//			{
	//				coureurs[i].setSpeed((coureurs[i].getSpeed()) - (0.8 * (coureurs[i].getMedSpeed()) *(coureurs[i].getDistance()*1000 / getTotalDistance()*1000)));
	//			}
	//		}
	//	}
	//	else if (coureurs[i].getAmountOfWeeks() == 16) {
	//		// Speed stays the same till the end
	//	}
	//	else {

	//		if (coureurs[i].getDistance() > 42.195 / 2 * (((coureurs[i].getAmountOfWeeks() - 8) + 1) / 8))
	//		{
	//			if (coureurs[i].getSpeed() > 0.8 * ((coureurs[i].getMedSpeed() * (100 - (coureurs[i].getShoes() * 1.1 / 100)) / 100)))
	//			{
	//				coureurs[i].setSpeed((coureurs[i].getSpeed()) - (0.8 * (coureurs[i].getMedSpeed()) * (coureurs[i].getDistance()*1000 / getTotalDistance()*1000)));
	//			}
	//		}
	//	}
	//	pente = getPenteCoureur(i);
	//	if (pente < 0)
	//	{
	//		coureurs[i].setSpeed((coureurs[i].getSpeed()) - (pente * (coureurs[i].getSpeed()) / 100));
	//	} 
	//	else if (pente > 0)
	//	{
	//		coureurs[i].setSpeed((coureurs[i].getSpeed()) + (pente * (coureurs[i].getSpeed()) / 100));
	//	}
	//	else
	//	{
	//		// C'est plat donc aucun pb, faut courir, aller!
	//	}
	//}
}

void Participants::newHydratation(const int& i) 
{
	float randomamount = randomFloat(0.125, 0.5);
	randomamount += coureurs[i].getHydratation();
	coureurs[i].setHydratation((1 - (randomamount / (0, 5 * temps/60))));
	// Hydration : if not hydrated enough then you'll surrender :/
	if (coureurs[i].getHydratation() < 0.2)
	{
		coureurs[i].setDistance(coureurs[i].getDistance() + 2);
		coureurs[i].setAbandon(1);
	}
}

void Participants::newDistance(const int& i) 
{
	coureurs[i].setDistance(coureurs[i].getDistance()+(coureurs[i].getSpeed())/3.6/100);
}

bool Participants::startMarathon()
{
	setTime();
	newSpeed();
	for (int i = 0;i < nbcoureurs;i++)
	{
		if (coureurs[i].getAbandon()==1)
		{
			coureurs[i].setSpeed(0);
			coureurs[i].setIsOver(1);
			coureurs[i].setTotalTime(temps);
		}
		else 
		{
			if(coureurs[i].getIsOver() == 0)
			{ 
				newDistance(i);
				getPenteCoureur(i);
			}
		}
	}
	
	int finished = 0;
	for (int i = 0;i < nbcoureurs;i++)
	{
		if (coureurs[i].getDistance() >= getTotalDistance())
		{
			if(coureurs[i].getIsOver() == 0)
			{
				coureurs[i].setTotalTime(temps);
				//cout << "le coureur " << i << " a fini de courir en " << coureurs[i].getTotalTime()<<" ses "<< coureurs[i].getDistance() << " km."<< endl;
				coureurs[i].setIsOver(1);
			}
			else 
			{
				coureurs[i].setIsOver(1);
			}
		}
		if (coureurs[i].getIsOver() == 1)
		{
			finished++;
		}
	}
	if (finished == nbcoureurs)
	{
		ofstream file4;
		file4.open("scores.txt");
		for (int i = 0;i < nbcoureurs;i++)
		{
			file4 << "Nom : " << coureurs[i].getName() <<  " Temps total : " <<coureurs[i].getTotalTime() <<" speed : " << (coureurs[i].getDistance() / coureurs[i].getTotalTime())*3.6 << endl;
		}
		file4.close();
		return 1;
	}
	else
	{
		return 0;
	}
}