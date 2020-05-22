
/*           ######### Programmation ludique #########             */ 
/*			          Projet jeu - Semestre 1                      */			
/*			               Le Puissance 4                          */


            //  By JAROS Quentin & KHAMPHOUSONE Thierry //

// Bibliothèques standard du C
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

//Constantes #define NBLIN NBCOL détermine la taille du plateau de jeu
#define NBLIN 6 
#define NBCOL 7 

// Procedure qui initialise tous les elements du tableau
void initArray(int nbLin, int nbCol, int iArray[nbLin] [nbCol], int value) 
{ 
	// deux boucles itératives for pour pouvoir gerer un tableau multidimensionnels 2D
    for(int a = 0; a < nbLin; a++) 
    { 
        for(int b = 0; b < nbCol; b++) 
        { 
            iArray[a][b] = value; 
        } 
    } 
} 


// ****** Cette procedure nous a servi uniquement durant la création du jeu elle n'est donc pas dans le main final du jeu ******
// Procedure showArray sert a afficher le contenu réel du tableau pendant la programmation de notre jeu
void showArray(int nbLin, int nbCol, int iArray[nbLin] [nbCol]) 
{ 
 
	// deux boucles itératives for pour pouvoir gerer un tableau multidimensionnels 2D
    for(int c = 0; c < nbLin; c++) 
    { 
        for(int d = 0; d < nbCol; d++) 
        { 
        	// "%3d " permet de décaler l'affichage de 3 espaces
            printf("%3d ", iArray[c] [d]); 
        } 
        printf("\n"); 
    } 
} 
// La fonction getColumnForPawn permet de recuperer les coordonnées et de verifier si l'emplacement choisi par l'utilisateur est valide
int getColumnForPawn(int nbLin, int nbCol, int board[nbLin] [nbCol]) 
{ 
	// Les variables pour la fonction getColumnForPawn
    int column; 
    int allnothing=0; 

    // Boucle do while pour attendre que l'utlisateur entre la coordonnée
    do 
    { 
    	// On demande via un scanf la coordonnée que souhaite rentrer l'utilisateur
        printf("Enter the coordinate of the column you want to put your pawn on: "); 
        
        // L'utilisateur choisi sa colone
        // Si le scanf ne recois pas un nombre, le programme se stop
        if(scanf("%d", &column) != 1) 
        { 
            exit (-1); 
        } 
        if(column >=0 && column<nbCol) 
        { 
            allnothing=1; 
        }
        // Si la colonne choisi est en dehors du tableau on fait recommence la boucle jusqu'a avoir une coordonnée correcte
        else { 
            printf("Wrong number of column (outside of the board), please re-try.\n"); 
            allnothing=0; 
        } 

        // Si la colonne est pleine alors on fait également recommence la boucle jusqu'a avoir une coordonnée correcte
        if(allnothing==1) 
        { 	
            if(board[0][column]!=0) 
            { 	
                printf("\nThis column is full so you can't add any more pawn, please re-try.\n"); 
                allnothing=0; 
            } 
        } 
    }while(allnothing==0); 

    // On retourne la coordonnée validée
    return column; 
} 


// La fonction placePawn recherche le premier emplacement libre de la colonne en partant du bas et y place un pion 
int placePawn(int nbLin, int nbCol, int board[nbLin][nbCol], int pawnCol, int pawn) 
{ 
	// variable pour la fonction placePawn
    int spotline;

    // systeme de balayage pour trouver le premier emplacment libre de la colonne
    for(spotline = nbLin-1; board[spotline][pawnCol] != 0; spotline--); 
    board[spotline][pawnCol] = pawn; 

	// On retourne le numero de la ligne correspondant au placement du pion
    return spotline; 
} 

// La fonction checkFourInLine Comtabilise le nombre de pion selon la verticale, l'horizontale et les 2 diagonales
int checkFourInLine(int nbLin, int nbCol, int board[nbLin] [nbCol], int pawnLin, int pawnCol) 
{ 
	// Les variables pour la fonction checkFourInLine
    int coordo; 
    int nbr; 
    int horizontal; 
    int vertical; 

    coordo = board[pawnLin][pawnCol]; 
    // La verification horizontale

    // La verification a gauche 
    nbr = 1; 
    horizontal=pawnCol-1; 
    while(horizontal>=0 && board[pawnLin][horizontal]==coordo) 
    { 
        nbr++; 
        horizontal--; 
    } 
    // La verification a droite 
    horizontal=pawnCol+1; 
    while(horizontal<nbCol && board[pawnLin][horizontal]==coordo) 
    { 
        nbr++; 
        horizontal++; 
    } 
    if(nbr>=4) 
    { 	
    	// comme nbr >= 4 on retourne 1 
        return 1; 
    } 

    nbr=1; // reinitialisation du compteur 

    // La verification verticale 

    // La verification vers le haut 
    vertical=pawnLin-1; 
    while(vertical>=0 && board[vertical][pawnCol]==coordo) 
    { 
        nbr++; 
        vertical--; 
    } 
    // La verification vers le bas 
    vertical=pawnLin+1; 
    while(vertical<nbLin && board[vertical][pawnCol]==coordo) 
    { 
        nbr++; 
        vertical++; 
    } 
    if(nbr>=4) 
    { 

        return 1; 
    } 
    
    nbr=1; // reinitialisation du compteur 

    //La verification 1ere diagonale 
    horizontal=pawnCol-1; 
    vertical=pawnLin-1; 
    while(vertical>=0 && horizontal>=0 && board[vertical][horizontal]==coordo) 
    { 
        nbr++; 
        vertical--; 
        horizontal--; 
    } 
    horizontal=pawnCol+1; 
    vertical=pawnLin+1; 
    while(vertical<nbLin && horizontal<nbCol && board[vertical][horizontal]==coordo) 
    { 
        nbr++; 
        vertical++; 
        horizontal++; 
    } 
    if(nbr>=4) 
    { 
        return 1; 
    } 

    nbr=1; // reinitialisation du compteur
    
    //verification 2eme diagonale 
    horizontal=pawnCol-1; 
    vertical=pawnLin+1; 
    while(vertical<nbLin && horizontal>=0 && board[vertical][horizontal]==coordo) 
    { 
        nbr++; 
        vertical++; 
        horizontal--; 
    } 
    horizontal=pawnCol+1; 
    vertical=pawnLin-1; 
    while(vertical>=0 && horizontal<nbCol && board[vertical][horizontal]==coordo) 
    { 
        nbr++; 
        vertical--; 
        horizontal++; 
    } 
    if(nbr>=4) return 1; 
    return 0; 
} 

// La fonction runAStep permet de recuperer l'indice de la colonne placer un pion et recuperer l'indice de la ligne et verifiez que 4 pions sont alignés
int runAStep(int nbLin, int nbCol, int board[nbLin] [nbCol], int numPlayer) 
{ 
	// Les variables pour la fonction runAStep
    int TrueFalse=0; 
    int column=1; 
    int line=1; 
    int NoFour=1; 
    
    column--; 
    line--; 
    NoFour--;

    // On affiche le message pour savoir quelle numero de joueur doit jouer
    printf("\n#### Player %d, your turn ####\n", numPlayer); 

    // On recupere l'indice de la colonne
    column=getColumnForPawn(nbLin,nbCol,board); 

    // On place le pion
    line=placePawn(nbLin,nbCol,board,column,numPlayer); 

    // On verifie si il y a 4 pions alignés sur la grille 
    NoFour=checkFourInLine(nbLin,nbCol,board,line,column); 
    if(NoFour==1) 
    { 
        TrueFalse = 1; 
    } 
    return TrueFalse; 

} 

// Cette procedure donnee par le TP permet d'effacer l'ecran du terminal et de replacer le curseur en haut ce qui donne également un effet d'animation a notre affichage
void clearScreen() 
{ 

    printf("%c[2J", 0x1B); 

    printf("%c[%d;%dDH", 0x1B, 1, 1); 

} 

// Cette procedure gère l'affichage graphique de notre jeu 
void showBoard(int nbLin, int nbCol, int board[nbLin][nbCol]) 
{ 
    int l; 
    int c; 
    int numCol = 0; 

    //clearScreen(); 

    for(l=0;l<nbLin;l++) 
    { 
        for(c=0;c<nbCol;c++) 
        { 
            printf(" |"); 

            if(board[l][c] == 0) 
            { 
                printf(" "); 
                printf(" "); 
            } 
            if(board[l][c] == 1) 
            { 
            	// On a remplacé le 1 par un rond rouge donné par le TP
                //printf("1"); 
                printf("\033[31;01m o\033[00m"); 
            } 
            if(board[l][c] == 2) 
            { 
            	// On a remplacé le 2 par un rond cyan donné par le TP
                //printf("2"); 
                printf("\033[36;01m o\033[00m"); 
            } 


        }

        // Affichage de la bordure du plateau et des indices des colonnes 
        printf(" |\n"); 
    } 
        printf(" "); 

        for(c=0;c<nbCol;c++) 
        { 
            printf(" ---"); 
        } 
        printf("\n"); 

        for(c=0;c<nbCol;c++) 
        { 
            printf(" %3d",numCol); 
            numCol++; 
        } 

        printf("\n"); 

} 

// La fonction runGame contients les différentes phases de jeu
int runGame(int nbLin, int nbCol, int board[nbLin] [nbCol]) 
{ 
	// Declaration des variables pour la fonction runGame
    int allnothing= 0; 
    int numPlayer = 0; 
    int winner; 
    int step=0; 
    int maxstep=(nbLin * nbCol); 

    //showArray a ete mis en commentaire car elle ne nous ert plus une fois le code termine
    //showArray(NBLIN, NBCOL, board); 


    winner = 0; 

    showBoard(nbLin, nbCol, board); 
    do 
    { 

         // Rappel c'est le joueur 1 qui commence la partie
        if(step%2 == 0) 
        { 

            numPlayer = 1; 

            winner=runAStep(nbLin,nbCol,board,numPlayer); 

        // Le joueur 2 prend le tour suivant
        }else 
        { 
            numPlayer = 2; 

            winner=runAStep(nbLin,nbCol,board,numPlayer); 

        } 
        showBoard(nbLin, nbCol, board); 
        step++; 

        if(winner != 0) 
        { 
        	// On retourne le numero du gagnant 
            return numPlayer; 
        } 

        if(step>=maxstep) 
        { 
            allnothing = 1; 
        } 
    }while(allnothing ==  0); 

    return 0; 
} 

// La procedure endOfGame prend en parametre le nom du gagnant
void endOfGame(int numWinner) 
{ 
	// Affiche la fin de la partie
    printf("\n\n#### THE GAME IS OVER ####\n"); 
    if(numWinner==0) 
    { 
    	// Affiche cela en cas d'egalitée
        printf("\nIt's a draw!\n"); 
    }else 
    { 
    	// Affiche le numero du joueur gagnant soit 1 ou 2
        printf("\nAnd the winner is Player %d!\n", numWinner); 
    } 
} 

// Le main du Programme
int main() 
{ 
	// Declaration des variables pour le main
    int nbLin; 
    int nbCol; 
    int mobile=0;


    printf("\n\n#### PUISSANCE 4 BY JAROS QUENTIN 1 KHAMPHOUSONE THIERRY ####\n"); 
    
    // Constantes (déclarées avec le #define) NBLIN NBCOL affectées a deux variables
    nbLin = NBLIN;
	nbCol = NBCOL; 

	// Declaration d'un tableau 2D d'entiers
    int board[nbLin] [nbCol]; 

    // Appel de la fonction initArray qui initialise les elements du tableau
    initArray(nbLin, nbCol, board, 0); 

    mobile=runGame(nbLin, nbCol, board); 

    endOfGame(mobile); 



    return 0; 

} 

/*           ######### Fin du Programme #########             */

/*	      ESIEA Informatique 1ère année - Semestre 1          */
         
        //  By JAROS Quentin & KHAMPHOUSONE Thierry //



// Professeur informatique : M.FRANCOIS & Mme.RAQUEL MARTINS
// 13 Janvier 2018


