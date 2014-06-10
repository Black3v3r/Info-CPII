/**********************************************************/
/* Développé par : LABARRE Florian – fushia_1			  */
/* Source : exo3.c – TP n°5 - le 05/05/2014 			  */
/* Description : Replissage d'une matrice de rang choisi  */
/* dans le sens trigo, en partant du milieu.			  */
/**********************************************************/

/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>

/* fonction main : fonction principale du programme */
int main(int argc, char const *argv[])
{

	/* variables locales */
	int tab[15][15];
	int rang = 1;
	int row = 0, col = 0;
	int num = 1;

	/* instructions */
	#if defined _WIN32
	system("chcp 65001"); // Permet d'afficher les accents et les carctères ASCII étendus sous Windows (ne pas chercher à retenir/comprendre, on peut faire sans...)
	#endif

	system("clear"); // Efacer la console (Linux)
	system("cls"); // Effacer la console (Windows)

	for (row = 0; row < 15; ++row) // Intialisation à 0 de toutes les cases du tableau
	{
		for (col = 0; col < 15; ++col)
		{
			tab[row][col] = 0;
		}
	}
	
	do
	{
		printf("Entez un rang impair <= 15\n");
		scanf("%d", &rang);
	}
	while (rang%2 == 0 || rang < 1 || rang > 15 );
	printf("Rang choisi: %d\n", rang);

	row = col = rang/2; // On cale le curseur sur la case du milieu
	tab[row][col] = num++; // On inscrit 1 dans la case centrale

	while (num < rang*rang)
	{
		do
		{
			tab[row][++col] = num++; // On remplit la case de droite ...
		}
		while ((tab[row-1][col]) && num <= (rang*rang)); // ...tant que celle du dessus est vide et que le rang maximal n'est pas atteint
		if (num < rang*rang) // Le rang maximal est atteint après un décalage vers la droite, il faut donc échapper les instructions suivantes
		{
			do
			{
				tab[--row][col] = num++; // On remplit la case du dessus ...
			}
			while(tab[row][col-1]); // ...tant que celle de gauche est vide
			do
			{
				tab[row][--col] = num++; // On remplit la case de gauche ...
			}
			while(tab[row+1][col]); // ...tant que celle du dessous est vide
			do
			{
				tab[++row][col] = num++; // On remplit la case du dessous ...
			}
			while(tab[row][col+1]); // ...tant que celle de droite est vide
		}
	}

	/* Affichage de la matrice */
	printf("┌");

	for (col = 1; col < rang*4; ++col)
	{
		if (col % 4 == 0)
			printf("┬");
		else
			printf("─");
	}
	printf("┐");
	printf("\n");
	for (row = 0; row < rang; ++row)
	{
		if (row > 0)
		{

			printf("├");

			for (col = 1; col < rang*4; ++col)
			{
				if (col % 4 == 0)
					printf("┼");
				else
					printf("─");
			}
			printf("┤");
			printf("\n");
		}
		printf("│");
		for (col = 0; col < rang; ++col)
		{
			printf("%3d│", tab[row][col]);
		}
		printf("\n");
	}
	printf("└");
	for (col = 1; col < rang*4; ++col)
	{
		if (col % 4 == 0)
			printf("┴");
		else
			printf("─");
	}
	printf("┘\n");
	return 0;
}
