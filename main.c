#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
     char CIN[10];
     char Nom[10];
     char Prenom[10];
     float Montant;
}add;

void menu(char *msg);
void addAccount();
void addAccount(int backToMenu);
void Retrait();
void Depot();
void Operations();
void fidelity();

int main()
{
    menu(0);

}



menu(int msg){

    system("cls||clear");
    int choice;
    printf("\t\t\t\t\t +Welcome To CodeBank Manager+  \n\n\n");
    if(msg == 1){
        printf(" \n Invalid Option! \n");
    }
    printf("      1 : Add New Account\n");
    printf("      2 : Add multiply Account\n");
    printf("      3 : Operations\n");
    printf("      4 : Informations\n");
    printf("      5 : fidelity\n\n");
    printf("      00 : Exite\n\n\n");

    printf("Select an option from the Menu: ");
    scanf("%d",&choice);


    switch(choice){
    case 1 :
         addAccount(1);

       break;
    case 2 :
        addMultiplyAccount();
        break;
    case 3 :
        Operations();
        break;
    case 4 :
        Informations();
        break;
    case 5 :
        fidelity();
        break;
    case 0 :
        return;
        break;
    default :
        system("cls||clear");

        menu(1);
         break;
    }

}


addAccount(int backToMenu){

    system("cls||clear");
    FILE *pWrite;
    pWrite = fopen("Accounts.txt", "a");
         printf("\tEnter CIN code:\n");
         scanf("%s",&add.CIN);

         printf("\tEnter your name\n");
         scanf("%s",&add.Prenom);

         printf("\tEnter you last name\n");
         scanf("%s",&add.Nom);

         printf("\tenter the montant\n");

         scanf("%f",&add.Montant);
    fprintf(pWrite, "%s\t%s\t%s\t%.2f\n", add.CIN, add.Prenom, add.Nom, add.Montant);
         if(backToMenu == 1){
            menu(0);
         }

}

addMultiplyAccount(){
    printf("n\n\add multiply account \n\n\n");

        char choice = 'y';
        while(choice == 'y' || choice == 'Y' ){
        addAccount(0);

        printf(" \n Add an other Account: (y/n)  ");
        scanf("%s",&choice);

            }
        menu(0);




}



Operations(){
    system("cls||clear");
    int choice;
         printf("operation: \n\n");
         printf("\t1 : Retrait \n");
         printf("\t2 : Depot \n\n");
         printf("\t0 : Back To Menu \n\n");
         printf("Select an operation: ");

         scanf("%d",&choice);

    switch(choice){
    case 1 :
        Retrait();
        break;
    case 2 :
        Depot();
        break;
    case 0 :
        menu(0);
        break;
    default :
        printf("invalid option");
        Operations();
    }
}



Retrait(){
    printf("retrait");
}
Depot(){
    printf("depot");

}


Informations(){

        system("cls||clear");

        printf(" *Infos\n");

        printf("\t 1: Par Ordre Ascendant\n");

        printf("\t 2: Par Ordre Descendant\n");

        printf("\t 3: Par Ordre Ascendant (montant) \n");

        printf("\t 4: Par Ordre Descendant (montant) \n");

        printf("\t 5: CIN \n");

        printf("\t 00 : Back \n\n");

        printf("Choose an option :");
        scanf("\t%i",&Informations);


        }

fidelity(){

        printf("fidelity\n");
          scanf("%d",&fidelity);
        }

