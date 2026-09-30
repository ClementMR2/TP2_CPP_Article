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
	string fileName = "articles.csv";

	do
	{
		cout << "\nChoisir une option : \n\t[0] Terminer le programme\n\t[1] Afficher les articles\n\t[2] Ajouter un article\n\t[3] Modifier un article\n\t[4] Supprimer un article\n\t[5] Sauvegarder les articles" << endl;
		cin >> choix;

		bool ok = gestion->recupererFichier(fileName);
		if (ok) {
			cout << "Article(s) recupere(s) : " << gestion->getSize() << endl;
		}

		switch (choix)
		{
			case 0:
			{
				flag = true;
				break;
			}
			case 1:
			{
				if (gestion->getSize() == 0) {
					cout << "La liste est vide!";
					break;
				}

				cout << gestion->printArticles();
				break;
			}
			case 2:
			{
				string nomArticle;
				double prixHT;
				int stock;

				cout << "Entrer le nom de l'article : " << endl;
				cin >> nomArticle;
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Entrer le prix de l'article : " << endl;
				cin >> prixHT;
				cin.ignore(1000, '\n');

				cout << "Entrer la quantite : " << endl;
				cin >> stock;
				cin.ignore(1000, '\n');

				gestion->addArticle(nomArticle, prixHT, stock);
				break;
			}
			case 3:
			{
				int index, question, stock;
				double prixHT;
				cout << "Entrer l'index de l'article a modifier" << endl;
				cin >> index;
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Entrer un prix" << endl;
				cin >> prixHT;
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Entrer un stock" << endl;
				cin >> stock;
				cin.clear();
				cin.ignore(1000, '\n');

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
			case 5:
			{
				bool ok = gestion->sauvegarderFichier(fileName);
				if (!ok)
				{
					cout << "Impossible de sauvegarder dans \"" << fileName << "\"";
					break;
				}

				cout << "Article(s) sauvegarde(s) : " << gestion->getSize() << endl;
			}
		}
	} while (!flag);

	delete gestion;

	return 0;
}