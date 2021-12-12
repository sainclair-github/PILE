#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

    //Implémentation des differentes fonctions
    //Vérifier si la pile est vide
    int EstVide(){
        int vide = 0; //prend 0 si la pile n'est pas vide
        if(stack == NULL)
            vide++; // prend 1 si la pile est vide 
        return vide;
    }

    //Vérifier si la pile est pleine
    int EstPleine(){
        int pleine = 0; //prend 0 si la pile n'est pas pleine
        //La pile est pleine lorsque sa taille réelle est égale a la taille maximale
        if(taillepile == TailleMax)
            pleine++;  //prend 1 si la pile est pleine
        return pleine;
    }

    //insérer un nouvel entier dans la pile
    void Empiler(int newElement){
        /*
            Pour empiler un nouvel entier, il faut tout
            d'abord s'assurer que la pile ne soit pas pleine
        */
        if(!EstPleine()){
            Pile nouvelle = malloc(sizeof(Pile)); //allocation de memoire à la nouvelle cellule de la pile
            //Vérifier si l'allocation mémoire a reussit
            if(nouvelle == NULL){
                fprintf(stderr,"ERREUR : ECHEC D'ALLOCATION MEMOIRE !!");
                exit(EXIT_FAILURE);
            }
            nouvelle->entier = newElement;
            nouvelle->next = stack;
            stack = nouvelle;
            nouvelle = NULL;
            taillepile++;
        }else 
            printf("Empilage impossible : Pile pleine !! \n");
    }

    //retirer la sommet de la pile
    int Depiler(){
        int giveElement = 0;
        if(!EstVide()){
            Pile save = stack;
            stack = stack->next;
            save->next = NULL;
            giveElement = save->entier;
            free(save);
            taillepile--;
        }else
            printf("Depilage impossible : Pile Vide !! \n");
        return giveElement;
    }

    //afficher l'ensemble des elements de la pile
    void Afficher(){
        if(!EstVide()){
            Pile save = stack;
            while(save!=NULL){
                printf("[%d]\n",save->entier);
                save = save->next;
            }
        }else
            printf("\nAucun élément à afficher car la pile est vide !!\n");
    }

    //Interface utilisateur dans la console
    void Menu(){
        int choix,val;
        do{
            printf("\n-----------------------------MENU_PRINCIPALE--------------------------------\n");
            printf("\t\t1-Empiler\t\t\tTaille reelle[%d]\n",taillepile);
            printf("\t\t2-Depiler\t\t\tTaille Maximale[%d]\n",TailleMax);
            printf("\t\t3-Vérifier si la pile est vide\n");
            printf("\t\t4-Vérifier si la pile est pleine\n");
            printf("\t\t5-Afficher la Pile\n");
            printf("\t\t6-Quitter\n");
            printf("Que voulez-vous faire ? ");
            scanf("%d",&choix);
            switch(choix){
                case 1 :
                    printf("\nEntrez l'entier à empiler : ");
                    scanf("%d",&val);
                    Empiler(val);
                    break;
                case 2 :
                    if(!EstVide())
                        printf("\nElement depiler : [%d]\n",Depiler());
                    else
                        printf("\nDépilage impossible : Pile vide !!");
                    break;
                case 3 :
                    if(EstVide())
                        printf("\nLa Pile est vide !!");
                    else
                        printf("\nLa Pile n'est pas vide !!");
                    break;
                case 4 :
                    if(EstPleine())
                        printf("\nLa pile est pleine !!");
                    else
                        printf("\nLa pile n'est pas pleine !!");
                    break;
                case 5 :
                    Afficher();
                    break;
                case 6 :
                    printf("\nTHANKS !! See you next time");
                    break;
            }
        }while(choix!=6);
    }