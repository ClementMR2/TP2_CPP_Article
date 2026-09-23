#pragma once
#include "Article.h"
#include <iostream>
#include <vector>

class Gestion
{
	vector<Article*> * mesArticles;
public:
	Gestion(int nbArticles);
	void printArticles();
	Article * getArticle(int index);
	void addArticle(string nom, double prixHT, int stock);
	bool updateArticle(int index, double prixHT, int stock);
	bool deleteArticle(int index);
	int getSize();
	~Gestion();
};

