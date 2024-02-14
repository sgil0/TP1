# include "biblio.h"


void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
return 0;
	
}

int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}
		return 1;
		}
}

int rechercheLivreTitre(const T_Bibliotheque *ptrB, T_Titre *ptrT)
{
	int i,j=0;

	for (i=0;i<=ptrB->nbLivres;i++){
		if (strcmp(&(ptrB->etagere[i]).titre, &ptrT)==0) j++;	
	}

	if (j>0) return j;
	return -1;
}

void afficheLivreAuteur(const T_Bibliotheque *ptrB, T_Aut *ptrA)
{
	int i;
	for(i=0;i<=ptrB->nbLivres;i++)
		if(strcmp(&(ptrB->etagere[i]).auteur, &ptrA)==0) afficherLivre(&(ptrB->etagere[i]).titre);
	return 0;
}

int supprimerLivre(T_Bibliotheque *ptrB, T_Titre *ptrT)
{
	int i,j=0;

	for (i=0;i<=ptrB->nbLivres;i++){
		if (strcmp(&(ptrB->etagere[i]).titre, &ptrT)==0){
			
			if (i==ptrB->nbLivres-1){
				ptrB->nbLivres= (ptrB->nbLivres)-1;
			}
			else{
				strcpy(&(ptrB->etagere[i]).titre, &(ptrB->etagere[ptrB->nbLivres-1]).titre);
				strcpy(&(ptrB->etagere[i]).auteur, &(ptrB->etagere[ptrB->nbLivres-1]).auteur);
				ptrB->nbLivres= (ptrB->nbLivres) -1;
			}
			j++;
		}
	}	
	if (j>0) return 1;
	return 0;
}