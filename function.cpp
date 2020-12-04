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

Trajectory getParcours(string text, int nbline) {

	ifstream file;
	file.open(text);
	string line;
	string word;
	if (file.is_open())
	{
		Trajectory parcours(nbline);
		int i = 0;
		int c = 0;
		float word1 = 0;
		float word2 = 0;
		float word3 = 0;
		while (!file.eof())
		{
			getline(file, line);
			stringstream ss(line);
			c = 0;
			while (ss >> word)
			{
				if (c == 0)
				{
					word1 = stof(word);
				}
				if (c == 1)
				{
					word2 = stof(word);
				}
				if (c == 2)
				{
					word3 = stof(word);
				}
				c++;
			}
			parcours.getPoint(i).setXYZ(word1, word2, word3);
			i++;
		}
		file.close();
		return parcours;
	}
	else {
		return EXIT_FAILURE;
	}
}

Participants getCoureurs(string text, int nbline2) {

	ifstream file;
	file.open(text);
	string line;
	string word;
	int i = 0;
	if (file.is_open())
	{
		Participants coureurs(nbline2);
		int c = 0;
		float stat = 0;
		int stat2 = 0;
		while (!file.eof())
		{
			getline(file, line);
			stringstream ss(line);
			c = 0;
			while (ss >> word)
			{
				if (c == 0)
				{
					coureurs.getCoureur(i).setName(word);
				}
				if (c == 1)
				{
					stat2 = stoi(word);
					coureurs.getCoureur(i).setNumDossard(stat2);
				}
				if (c == 2)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setWeight(stat);
				}
				if (c == 3)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setHeight(stat);
				}
				if (c == 4)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setShoes(stat);
				}
				if (c == 5)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setMedSpeed(stat);
				}
				if (c == 6)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setAmountOfWeeks(stat);
				}
				c++;
			}
			i++;
		}
		file.close();
		return coureurs;
	}
	else
	{
		return EXIT_FAILURE;
	}

}