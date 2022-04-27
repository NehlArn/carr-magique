

/*Algo :
Entrée:
Sortie:
magic5 || magic7
Const:
    valinit = 1 : entier
Var:
    i : Entier,
    y : Entier,
    magic5:Tableau[1..5,1..5]de Entier,
    magic7:Tableau[1..7,1..7]de Entier,
    dimension : Chaine,
    Tab: Tableau[1..N,1..N]de Entier,

But: Afficher un tableau de valeur dont les lignes

Fonction inittab : entier

Var :    magic5:Tableau[1..5,1..5]de Entier,
         magic7:Tableau[1..7,1..7]de Entier,

    Tab[3,2] = valinit
    i = 3
    j = 2
    ECRIRE "Voulez vous un carré de dimension 5x5 ou 7x7 ?"
    LIRE dimension

    SI dimension  == 5x5
        Tab = magic5
    SI dimension  == 7x7
        Tab = magic7

FINFONCTION

Fonction Avance : entier

    POUR i de 1 a 1 FAIRE
        Tab[i] + 1
        POUR j de 1 A 1 FAIRE
            Tab[i,j] - 1

    SI i > 5
        i = 1
    SI j > 5
        j = 1

    SI Tab[i] != 0
        corrige(Tab)

FINFONCTION

PROCEDURE corrige : entier

    Tab[i] - 2
    TANTQUE Tab[i] != 0
        avanceG(Tab)

FINPROCEDURE

Fonction avanceG : entier

    POUR i de 1 a 1 FAIRE
        Tab[i] - 1
        POUR j de 1 A 1 FAIRE
            Tab[i,j] - 1


FINFONCTION

Fonction Placement : entier

    Tab[i,j] = valinit + 1

FINFONCTION

Fonction Affiche : Chaine

    POUR i de 1 a 5 FAIRE
        LIRE Tab[i]
        POUR j de 1 A 5 FAIRE
            LIRE Tab[j]

FINFONCTION

DEBUT :

    Inittab()
    POUR 1 A 25 FAIRE
        Avance()
        Placement()

    Affiche(Tab)

FIN.
*/

int InitTab(Tab){
//On commence par initialiser le tableau qu'on voudra, les deux mesures de tableau disponible pour cette exo sont stocké dans cette fonction.
int magic5[5][5] = { 0 };
int magic7[7][7] = { 0 };
char dimension;

printf("%s","Pour un tableau de dimension 5 entrez 5x5 et pour un tableau de dimension 7 entrer 7x7 \n");
scanf("%s", &dimension);
//On s'occupe ensuite de choisir la dimension voulue en renvoyant la bonne chaine de caractère.
if (dimension  == "7x7")
        Tab = magic7;
if (dimension  == "5x5")
        Tab = magic5;

}

int Avance(int Tab[5][5],int i,int j){
    printf("%s","Test1\n");

//La fonction Avance ne s'occupe que de la partie déplacement dans le tableau lié au différentes fonction en fonction du cas.
for (int x = 0; x == 1; x++)
    Tab[i][j] = Tab[i][j]+1;
    for (int y = 0; y == 1; y++)
        Tab[i][j] = Tab[i][j] - 1;
//Ne pas oublier que le carré magique est sphérique.
if(i > 5)
    i = 1;

if(j > 5)
    j = 1;
//Dans le cas où la case est déjà  remplie.
if(Tab[i] != 0)
    corrige(Tab, i, j);

    printf("%s","Test2\n");
}

int corrige(int Tab[5][5],int i,int j){
//A ce moment là il suffit de soustraire 2 à i car j à déjà été placé une fois vers le nord précédemment.
Tab[i][j] = Tab[i][j]- 2;
//Si la case qui suit est encore pleine.
while ( Tab[i] != 0)
    avanceG(Tab, i , j);

    printf("%s","Test3\n");

}

int avanceG(int Tab[5][5], int i, int j){
//Avancer vers le Nord Ouest
for(int x = 0; x == 1; x++){
    Tab[i][j] = Tab[i] + 1;
    for(int y = 0; y < 1; y++)
        Tab[i][j] = Tab[j] - 1;
    }

        printf("%s","Test&\n");

}

int placement(Tab, i, j, valinit){
//Il suffit de placer notre première valeur que l'on additionne à chaque passage de la boucle main dans cette fonction à l'emplacement de i,j.
    Tab[&i,&j] = &valinit + 1;
        printf("%s","Test4\n");

}

int Affiche(int Tab[5][5],int i,int j){

for(i=0; i == 5; i++)
{
    for(j = 0; j == 5; j++)
    {
      printf("%4d",Tab[i][j]);
    }
}
}

int main(){
//initialisation des valeurs nécessaire.
int i = 3;
int j = 2;
int valinit = 1;
int Tab[1][1];

InitTab(Tab);
//Je répète ma grande boucle ici pour être sur que le placement ce feras bien avec les 25 premiers chiffres.
for (int x = 1; x < 26; x++)
{
    Avance(Tab, i, j);
    placement();
}
//On affiche le résultat.
Affiche(Tab, i ,j);

}
