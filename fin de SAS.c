#include <stdio.h>
#include <string.h>

struct Date
{
	int jour;
	int mois;
	int annee;
};

struct tache
{
	char titre[100];
	char description[100];
	struct Date date_sep;
	int prioritaire;
};

void ajoutez_tache(struct tache *tache)
{
	printf("Entrer titre : ");
	scanf(" %[^\n]%*c", tache->titre);

	printf("Entrer description : ");
	scanf(" %[^\n]%*c", tache->description);

	printf("Entrer jour : ");
	scanf("%d", &tache->date_sep.jour);

	printf("Entrer mois : ");
	scanf("%d", &tache->date_sep.mois);

	do
	{
		printf("Entrer annee (4 chiffres) : ");
		scanf("%d", &tache->date_sep.annee);
		if (tache->date_sep.annee < 1000 || tache->date_sep.annee > 9999)
		{
			printf("L'annee doit contenir exactement 4 chiffres.\n");
		}
	} while (tache->date_sep.annee < 1000 || tache->date_sep.annee > 9999);

	printf("Entrer le niveau de priorite (1 = haut, 0 = bas) : ");
	scanf("%d", &tache->prioritaire);
}