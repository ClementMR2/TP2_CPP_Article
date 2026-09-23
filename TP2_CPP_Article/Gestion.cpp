#include "Gestion.h"
#include <iostream>
#include "Article.h"
#include <vector>

using namespace std;

Gestion::Gestion(int nbArticles)
{
	mesArticles = new vector<Article*>();

	for (int i = 0; i < nbArticles; i++)
	{
		mesArticles->push_back(new Article("Article N-" + to_string(i)));
		mesArticles->at(i)->setPrixHT(10.0+i);
		mesArticles->at(i)->setStock(10 + i);
	}
}

void Gestion::printArticles()
{
	for (int i = 0; i < getSize(); i++)
	{
		cout << "[" << i << "] ->" << mesArticles->at(i)->getNom() << ", PrixHT :  " << mesArticles->at(i)->getPrixHT() << ", Stock : " << mesArticles->at(i)->getStock() << endl;
	}
}

Article * Gestion::getArticle(int index)
{
	return mesArticles->at(index);
}

void Gestion::addArticle(string nom, double prixHT, int stock)
{
	mesArticles->push_back(new Article(nom));
	mesArticles->at(this->getSize()-1)->setPrixHT(prixHT);
	mesArticles->at(this->getSize()-1)->setStock(stock);
}

bool Gestion::updateArticle(int index, double prixHT, int stock)
{
	if ((index + 1) > this->getSize() || index < 0 || getArticle(index) == NULL)
		return false;

	cout << "Maj de l'article : " << mesArticles->at(index)->getNom() << endl;
	mesArticles->at(index)->setPrixHT(prixHT);
	mesArticles->at(index)->setStock(stock);
	return true;
}

bool Gestion::deleteArticle(int index)
{
	if (index < 0 || (index + 1) > getSize())
		return false;

	delete mesArticles->at(index); // Supprimer la référence
	mesArticles->at(index) = nullptr; // Supprimer l'article du tas
	mesArticles->erase(mesArticles->begin() + index); // Forcer l'effacement
	return true;
}

int Gestion::getSize()
{
	return mesArticles->size();
}

Gestion::~Gestion()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete mesArticles->at(i);
		mesArticles->at(i) = nullptr;
	}

	cout << "[Gestion] Destruction..." << endl;
}
