#pragma once
#include "Article.h"
#include <iostream>
#include <vector>

class Gestion
{
	vector<Article*> * mesArticles;
public:
	Gestion(int nbArticles);
	string printArticles();
	Article * getArticle(int index);
	void addArticle(string nom, double prixHT, int stock);
	bool updateArticle(int index, double prixHT, int stock);
	bool recupererFichier(string fileName);
	bool sauvegarderFichier(string fileName);
	bool deleteArticle(int index);
	int getSize();
	~Gestion();
};

