#include "Gestion.h"
#include <iostream>
#include "Article.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Gestion::Gestion(int nbArticles)
{
	mesArticles = new vector<Article*>();
}

string Gestion::printArticles()
{
	string output = "";
	for (int i = 0; i < getSize(); i++)
	{
		output += "[ " + to_string(i) + " ] >> " + mesArticles->at(i)->getNom() + ", " +
			"Prix HT : " + to_string(mesArticles->at(i)->getPrixHT()) + ", " +
			"Quantite : " + to_string(mesArticles->at(i)->getStock()) + "\n";
	}

	return output;
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

bool Gestion::sauvegarderFichier(string fileName)
{
	ofstream fichier(fileName);

	if (!fichier.is_open())
		return false;

	for (int i = 0; i < getSize(); i++)
	{
		Article * article = mesArticles->at(i);

		fichier << article->getNom() << ";" << article->getPrixHT() << ";" << article->getStock() << "\n";
	}

	fichier.close();
	return true;
}

bool Gestion::recupererFichier(string fileName)
{
	ifstream fichier(fileName);

	if (!fichier.is_open())
		return false;

	string ligne;

	while (getline(fichier, ligne))
	{
		stringstream ss(ligne);

		string nom;
		string prix;
		string stock;

		getline(ss, nom, ';');
		getline(ss, prix, ';');
		getline(ss, stock, ';');

		addArticle(
			nom,
			stod(prix),
			stoi(stock)
		);
	}

	fichier.close();
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

	delete mesArticles;
	//cout << "[Gestion] Destruction..." << endl;
}
