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
	int nbword = 0;
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
	};
}

Participants getCoureurs(string text, int nbline) {

	ifstream file;
	file.open(text);
	string line;
	string word;
	int nbword = 0;
	if (file.is_open())
	{
		Participants coureurs(nbline);
		int i = 0;
		int c = 0;
		float stat = 0;
		while (!file.eof())
		{
			getline(file, line);
			stringstream ss(line);
			c = 0;
			while (ss >> word)
			{
				if (c == 0)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setWeight(stat);
				}
				if (c == 1)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setHeight(stat);
				}
				if (c == 2)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setShoes(stat);
				}
				if (c == 3)
				{
					stat = stof(word);
					coureurs.getCoureur(i).setMedSpeed(stat);
				}
				if (c == 4)
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
	};
}