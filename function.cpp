#include <SFML/Graphics.hpp>
#include "header.hpp"
using namespace std;
using namespace sf;

int numberOfLines(string text)
{
	ifstream file;
	file.open(text);
	int nbline = 0;
	string line;
	while (getline(file, line))
	{
		nbline++;
	}
	file.close();
	return nbline;
}

float randomFloat(float const& min, float const& max)
{
	float myRandom;
	do
	{
		myRandom = min + ((float)rand() / ((float)RAND_MAX) * ((float)max + 1 - (float)min));
	} while (myRandom > max);
	return myRandom;
}

void randomCoureurs(const int& nbcoureurs)
{
	ofstream file5;
	string tab[] = {"Pierre", "Mohamed", "Abdoul" , "Augusting" , "Jean_Michel" , "Poele_a_frire", "Louis_du_13" , "Julien-Marie" , "Albert_3eme_du_nom" , "Jaaj" , "Luc" , "Marie", "Camille", "Remiette" , "AlphaRouste" , "Super_Franky" , "Ahzutjairate" , "Croustille" , "Lolo" , "Mamene" , "Rico" , "Julien" , "Margot" , "Candide" , "Agathe" , "Georges" , "Coquillette" , "Arthur" , "Martine" , "Jack_Uzi" , "Le_Roi_du_Nord" , "Denis_Chon" , "Ricardo" , "Pepette" , "Moha" , "Ben_Arfa" , "Sanji" , "Robin" , "Batman_le_Vrai", "Clark_Kent" , "Sadoman" , "Petoman" , "Furax_Barbarossa" , "Karim", "Alkapote" , "Sinik" , "Julien_Schwartzer", "Alie_Yaffa", "Seth_Gueko" };
	float randomstat = nbcoureurs;
	int randomname=0;
	file5.open("coureurs.txt");
	for (int i = 0;i < nbcoureurs;i++)
	{
		randomname = (int)randomFloat(0, 48);
		file5 << tab[randomname] << " " << i << " ";
		randomstat = randomFloat(45, 120);
		file5 << randomstat << " ";
		randomstat = randomFloat(1.3, 2);
		file5 << randomstat << " ";
		randomstat = randomFloat(100, 300);
		file5 << (int)randomstat << " ";
		randomstat = randomFloat(8, 20);
		file5 << randomstat << " ";
		randomstat = randomFloat(8, 16);
		file5 << (int)randomstat << " " << endl;
	}
	file5.close();
	float test = nbcoureurs;
}