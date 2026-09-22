#include "Article.h"
#include <iostream>
#include <string>

using namespace std;

Article::Article(string nom) 
{
	this->nom = nom;
	cout << "[Article] Je suis dans le constructeur!" << endl;
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
	this->prixHT = prix;
}

void Article::setStock(int stock) 
{
	this->stock = stock;
}

Article::~Article() 
{
	cout << "[Article] Je suis dans le destructeur!" << endl;
}