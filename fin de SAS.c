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

void afficher_tache(struct tache tache)
{
	printf("----------- Tache -----------\n");
	printf("Titre: %s\n", tache.titre);
	printf("Description: %s\n", tache.description);
	printf("Date: %02d/%02d/%04d\n", tache.date_sep.jour, tache.date_sep.mois, tache.date_sep.annee);
	printf("Priorite: %d\n", tache.prioritaire);
}

void modifier_tache(struct tache *tache)
{
	int choix;
	printf("\n1. Modifier le titre\n");
	printf("2. Modifier la description\n");
	printf("3. Modifier la date\n");
	printf("4. Modifier la priorite\n");
	printf("Choisissez une option : ");
	scanf("%d", &choix);

	switch (choix)
	{
	case 1:
		printf("Nouveau titre : ");
		scanf(" %[^\n]%*c", tache->titre);
		break;
	case 2:
		printf("Nouvelle description : ");
		scanf(" %[^\n]%*c", tache->description);
		break;
	case 3:
		printf("Nouvelle date (jour mois annee) : ");
		scanf("%d %d %d", &tache->date_sep.jour, &tache->date_sep.mois, &tache->date_sep.annee);
		break;
	case 4:
		printf("Nouvelle priorite (1 = haut, 0 = bas) : ");
		scanf("%d", &tache->prioritaire);
		break;
	default:
		printf("Choix invalide.\n");
	}
}

void supprimer_tache(struct tache taches[], int *nbr_tache, int index)
{
	int i = index;
	while (i < *nbr_tache - 1)
	{
		taches[i] = taches[i + 1];
		i++;
	}
	(*nbr_tache)--;
}