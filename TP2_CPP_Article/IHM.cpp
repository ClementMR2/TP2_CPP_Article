#include <iostream>
#include "Article.h"
#include "Gestion.h"

using namespace std;

int main() {
	cout << "Partie 1 : " << endl;
	Article * art1 = new Article("Sport");
	Article *  art2 = new Article("Art");

	Article * mesArticles[3];

	mesArticles[0] = art1, mesArticles[1] = art2, mesArticles[2] = new Article("Élément du tableau pouvant être détruit");

	mesArticles[0]->setPrixHT(12), mesArticles[0]->setStock(99);
	mesArticles[1]->setPrixHT(2.50), mesArticles[1]->setStock(67);

	cout << "Nom : " << mesArticles[0]->getNom() << ", Prix HT : " << mesArticles[0]->getPrixHT() << ", Stock : " << mesArticles[0]->getStock() << endl;
	cout << "Nom : " << mesArticles[1]->getNom() << ", Prix HT : " << mesArticles[1]->getPrixHT() << ", Stock : " << mesArticles[1]->getStock() << endl;

	delete mesArticles[2]; // Intéressant ça
	//cout << "Article 1 : " << (*art1).getNom() << endl;
	delete art1, delete art2;
	//cout << "Article 1 : " << (*mesArticles[0]).getNom() << endl;


	cout << "Partie 2 : " << endl;

	Gestion* qqArticles = new Gestion();
	cout << "Taille du tableau : " << qqArticles->getSize();

	return 0;
}