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