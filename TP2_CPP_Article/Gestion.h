#pragma once
#include "Article.h"
#include <iostream>

class Gestion
{
	Article * mesArticles[3];
public:
	Gestion();
	Article * getArticles();
	void addArticle(string nom, double prixHT, int stock);
	void updateArticle(string nom, double prixHT, int stock);
	void deleteArticle(int index);
	int getSize();
	~Gestion();
};

