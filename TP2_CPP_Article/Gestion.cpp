#include "Gestion.h"
#include <iostream>
#include "Article.h"

using namespace std;

Gestion::Gestion()
{
	cout << "Je suis dans le constructeur!" << endl;

	mesArticles[0] = new Article("Sport");
	mesArticles[1] = new Article("Art");
	mesArticles[2] = new Article("Divertissement");
	//
	deleteArticle(2);
}

Article* Gestion::getArticles()
{
	return *mesArticles;
}

void Gestion::addArticle(string nom, double prixHT, int stock)
{
	cout << "WIP";
}

void Gestion::updateArticle(string nom, double prixHT, int stock)
{
	cout << "WIP";
}

void Gestion::deleteArticle(int index)
{
	if (index < 0 || (index + 1) > getSize())
	{
		return;
	}


	delete mesArticles[index];
	mesArticles[index] = NULL;
	mesArticles[index]->setStock(25);

}

int Gestion::getSize()
{
	int size = sizeof(this->mesArticles) / sizeof(this->mesArticles[0]);
	return size;
}

Gestion::~Gestion()
{
	cout << "[Gestion] Je suis dans le destructeur!" << endl;
}
