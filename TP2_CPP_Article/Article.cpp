#include "Article.h"
#include <iostream>
#include <string>

using namespace std;

Article::Article(string nom) 
{
	this->nom = nom;
}

string Article::getNom() 
{
	return this->nom;
}

double Article::getPrixHT() 
{
	return this->prixHT;
}

int Article::getStock() 
{
	return this->stock;
}

void Article::setPrixHT(double prix) 
{
	if (prix > 0.0)
		this->prixHT = prix;
}

void Article::setStock(int stock) 
{
	if (stock > 0.0)
		this->stock = stock;
}

Article::~Article() 
{
	//cout << "[Article] Destruction de l'article : " << this->nom << endl;
}