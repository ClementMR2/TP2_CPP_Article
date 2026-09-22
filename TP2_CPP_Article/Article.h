#pragma once
#include <string>

using namespace std;

class Article
{
	string nom;
	double prixHT;
	int stock;
public:
	Article(string n);
	string getNom();
	double getPrixHT();
	int getStock();
	void setPrixHT(double);
	void setStock(int);
	~Article();
};