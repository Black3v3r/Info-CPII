/**********************************************************/
/* Développé par : LABARRE Florian – fushia_1			  */
/* Source : exo1.c – TP n°5 - le 05/05/2014 			  */
/* Description : Manipulation de tableaux 2D		      */
/* Commentaires : EMPTY 								  */
/* Arguments : EMPTY 									  */
/**********************************************************/

/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* fonction main : fonction principale du programme */
int main(int argc, char const *argv[])
{
	system("clear"); // Efacer la console (Linux)
	system("cls"); // Effacer la console (Windows)
	srand(time(NULL));
	/* variables locales */
	int i = 0;
	int j = 0;
	int nLig = 0;
	int nCol = 0;
	int sum = 0;
	int prod = 1;
	int tab[10][10];

	/* instructions */
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j] = 0;
		}
	}

	// Entrée des bornes pour les lignes/colonnes
	do
	{
		printf("Entrez un nombre de colonnes\n");
		scanf("%d", &nCol);
	}
	while (nCol < 1 || nCol > 10);

	do
	{
		printf("Entrez un nombre de lignes\n");
		scanf("%d", &nLig);
	}
	while (nLig < 1 || nLig > 10);
	
	// Génération du tableau
	for (i = 0; i < nLig; ++i)
	{
		for (j = 0; j < nCol; ++j)
		{
			tab[i][j] = rand()%5+1;
		}
	}

	// Affichage du tableau
	for (i = 0; i < nLig; ++i)
	{
		for (j = 0; j < nCol; ++j)
		{
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}

	// Calcul et affichage des sommes de chaque ligne
	for (i = 0; i < nLig; ++i)
	{
		for (j = 0; j < nCol; ++j)
		{
			sum += tab[i][j];
		}
		printf("Somme de la ligne %d: %d\n", i+1, sum);
		sum = 0;
	}

	// Calcul et affichage des produits de chaque colonne
	for (j = 0; j < nCol; ++j)
	{
		for (i = 0; i < nLig; ++i)
		{
			prod *= tab[i][j];
		}
		printf("Produit de la colone %d: %d\n", j+1, prod);
		prod = 1;
	}

	return 0;
}