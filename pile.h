#ifndef __PILE__H__
#define __PILE__H__
#define TailleMax 20

    //définition de la structure chainée pile d'entier
    typedef struct PileEntier{
        int entier;
        struct PileEntier *next;
    }*Pile;

    static int taillepile = 0;

    static Pile stack; //déclaration de la pile d'entier

    //Signatures des differentes fonctions 
    int EstVide(); //Vérifier si la pile est vide

    int EstPleine(); //Vérifier si la pile est pleine

    void Empiler(int newElement); //insérer un nouvel entier dans la pile

    int Depiler(); //retirer le sommet de la pile

    void Afficher(); //afficher l'ensemble des éléments de la pile

    void Menu(); //Interface utilisateur dans la console
#endif