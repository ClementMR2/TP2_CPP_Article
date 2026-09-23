#include <iostream>
#include "Article.h"
#include "Gestion.h"
#include <string>

using namespace std;

int main()
{
	cout << "\t--== [CRUD] Articles ==--\n";
	Gestion * gestion = new Gestion(10);

	int choix;
	bool flag = false;

	do
	{
		cout << "\nChoisir une option : \n\t[0] Terminer le programme\n\t[1] Afficher les articles\n\t[2] Ajouter un article\n\t[3] Modifier un article\n\t[4] Supprimer un article" << endl;
		cin >> choix;

		switch (choix)
		{
			case 0:
			{
				flag = true;
				break;
			}
			case 1:
			{
				gestion->printArticles();
				break;
			}
			case 2:
			{
				string nomArticle;
				double prixHT;
				int stock;

				cout << "Entrer le nom de l'article : " << endl;
				cin >> nomArticle;

				cout << "Entrer le prix de l'article : " << endl;
				cin >> prixHT;

				cout << "Entrer la quantite : " << endl;
				cin >> stock;

				gestion->addArticle(nomArticle, prixHT, stock);
				break;
			}
			case 3:
			{
				int index, question, stock;
				double prixHT;
				cout << "Entrer l'index de l'article a modifier" << endl;
				cin >> index;

				cout << "Entrer un prix" << endl;
				cin >> prixHT;

				cout << "Entrer un stock" << endl;
				cin >> stock;

				if (!gestion->updateArticle(index, prixHT, stock))
				{
					cout << "Impossible de modifier un tel article...";
				}
				break;
			}
			case 4:
			{
				int index;
				cout << "Entrer l'index de l'article a supprimer" << endl;
				cin >> index;

				if (!gestion->deleteArticle(index))
				{
					cout << "Impossible de supprimer un tel article...";
				}
				break;
			}
		}
	} while (!flag);

	delete gestion;

	return 0;
}

/*
int partieUne() {
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

	return 0;
}
*/