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

void filtrer_par_priorite(struct tache taches[], int nbr_tache, int prioritaire)
{
	printf("\n--- Taches avec priorite %s ---\n", prioritaire == 0 ? "basse" : "haute");
	int i = 0;
	while (i < nbr_tache)
	{
		if (taches[i].prioritaire == prioritaire)
		{
			afficher_tache(taches[i]);
		}
		i++;
	}
}

int main()
{
	struct tache taches[100];
	int nbr_taches = 0;
	int choix;

	do
	{
		printf("\n1: Ajouter une tache\n");
		printf("2: Afficher toutes les taches\n");
		printf("3: Modifier une tache\n");
		printf("4: Supprimer une tache\n");
		printf("5: Filtrer les taches par priorite\n");
		printf("6: Quitter\n");
		printf("Choisissez une option : ");
		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
			if (nbr_taches < 100)
			{
				ajoutez_tache(&taches[nbr_taches]);
				nbr_taches++;
			}
			else
			{
				printf("Nombre maximum de taches atteint.\n");
			}
			break;

		case 2:
			if (nbr_taches == 0)
			{
				printf("Aucune tache a afficher.\n");
			}
			else
			{
				int i = 0;
				while (i < nbr_taches)
				{
					afficher_tache(taches[i]);
					i++;
				}
			}
			break;

		case 3:
			if (nbr_taches == 0)
			{
				printf("Aucune tache a modifier.\n");
			}
			else
			{
				int index;
				printf("Entrez le numero de la tache a modifier (1 a %d) : ", nbr_taches);
				scanf("%d", &index);
				if (index > 0 && index <= nbr_taches)
				{
					modifier_tache(&taches[index - 1]);
				}
				else
				{
					printf("Indice invalide.\n");
				}
			}
			break;

		case 4:
			if (nbr_taches == 0)
			{
				printf("Aucune tache a supprimer.\n");
			}
			else
			{
				int index;
				printf("Entrez le numero de la tache a supprimer (1 a %d) : ", nbr_taches);
				scanf("%d", &index);
				if (index > 0 && index <= nbr_taches)
				{
					supprimer_tache(taches, &nbr_taches, index - 1);
				}
				else
				{
					printf("Indice invalide.\n");
				}
			}
			break;

		case 5:
			printf("Entrez la priorite a filtrer (0 pour basse, 1 pour haute) : ");
			int prioritaire;
			scanf("%d", &prioritaire);
			if (prioritaire == 0 || prioritaire == 1)
			{
				filtrer_par_priorite(taches, nbr_taches, prioritaire);
			}
			else
			{
				printf("Priorite invalide.\n");
			}
			break;

		case 6:
			printf("Au revoir !\n");
			break;

		default:
			printf("Choix invalide. Veuillez reessayer.\n");
		}
	} while (choix != 6);

	return 0;
}