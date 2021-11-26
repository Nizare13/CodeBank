#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//struct OF an Account/
   struct account {
	char CIN[13];
	char Nom[13];
	char Prenom[13];
	float Montant;
};

        struct account Tab_C[666];

         int all_account = 0;

// Cleaner Function

     void cleanCls(){
	system("cls||clear");

}


//fonctions add account


bool add_account(int n){

	int i;

	for (i = 0 ; i < n; i++){

		printf("Enter CIN code : ");
        scanf("%s", Tab_C[all_account].CIN);

		printf("Enter your lastname : ");
		scanf("%s", Tab_C[all_account].Nom);

		printf("Enter your Name : ");
		scanf("%s", Tab_C[all_account].Prenom);

		printf("Enter an amount : ");
		scanf("%f", &Tab_C[all_account].Montant);

            all_account++;
	}

	return true;
}

bool Deposit(char CIN[10]) {

}

// Operation
bool operations(){

	int _choice_, i;
	char CIN[13];
	float Option;

	printf("Enter The CIN code  : ");
	scanf("%s", CIN);

	cleanCls();
	do {
		printf("\n\n\n\n");
		printf("\t  1. Deposit \n \n \n");
		printf("\t  2. Withdraw \n \n \n");
		printf("\t  0. Main Menu \n \n");
		printf("Enter Your Choice : ");
		scanf("%d", &_choice_);

		switch (_choice_) {
			case 1 :
				cleanCls();
					for(i = 0; i < all_account; i++) {
			        	if (strcmp(CIN, Tab_C[i].CIN) == 0) {

							printf("Enter Operation amount to Deposit : ");
							scanf("%f", &Option);
                        Tab_C[i].Montant += Option;

                        printf("Your Amount for now : %g MAD \n", Tab_C[i].Montant);
                                                             }
					                                  }
				break;
			case 2 :
				cleanCls();
				for(i = 0; i < all_account; i++) {
						if (strcmp(CIN, Tab_C[i].CIN) == 0) {

            printf("Select an Operation Amount to Withdraw : ");
            scanf("%f", &Option);
                        if (Tab_C[i].Montant >= Option)
								Tab_C[i].Montant -= Option;
							else
								printf("The Balance is less than %f MAD \n", Option);

							printf("Your Amount is : %f MAD\n \n \n", Tab_C[i].Montant);
						}
					}
				break;
			default : printf("Invalid Select!! \n");
		}
	}while (_choice_ != 0);

	  cleanCls();
}



//display function

 void display() {
	cleanCls();
    struct account temp_account;
    char CIN[13];
	int _choice, __choice, i, j;
	do {
		printf("\t  1. sorting by amount \n ");
		printf("\t  2. sorting by lastname \n ");
		printf("\t  3. Search by CIN code  \n ");
		printf("\t  0. Main Menu \n \n \n");
		printf("Select an Option : \n");
		scanf("%d", &_choice);
// Display Condition
		switch (_choice) {
			case 1 :
				printf("\t \t \t 1. Descending Order  \n \n \n");
				printf("\t \t \t 2. Ascending Order \n \n \n");
				printf("Select an Option : ");
				scanf("%d", &__choice);
                switch (__choice) {
					case 1 :
						printf("You have chosen the sort by >>  amount >> Descending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(Tab_C[j].Montant < Tab_C[j+1].Montant)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}
						printf("CIN code\t lastname \t Name \t Amount\n\n");
						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].CIN, Tab_C[i].Nom, Tab_C[i].Prenom, Tab_C[i].Montant);
						}
						break;

					case 2 :
						printf("You did choose the sort by ----> amount ----> Ascending Order \n");
                        struct account temp_account;
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(Tab_C[j].Montant > Tab_C[j+1].Montant)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}
						printf("CIN \t lastname \t Name \t Amount\n\n");
						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %.2f \n", Tab_C[i].CIN, Tab_C[i].Nom, Tab_C[i].Prenom, Tab_C[i].Montant);
						}
						break;
				}
				break;
				default : printf("Invalid select !! \n");
			case 2 :
                printf("\t \t \t 1. Descending Order \n \n \n");
				printf("\t \t \t 2. Ascending Order \n \n \n");
				printf("choose an Option: ");
				scanf("%d", &__choice);
				switch (__choice) {
					case 1 :
						printf("You have chosen the sort by ----> LastName ----> Descending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(strcmp(Tab_C[j].Nom, Tab_C[j+1].Nom) > 0){
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}
						printf("CIN \t lastname \t Name \t Amount\n\n");


						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].CIN, Tab_C[i].Nom, Tab_C[i].Prenom, Tab_C[i].Montant);
						}
						break;
					case 2 :
						printf("You have chosen the sort by ----> lastname ----> Ascending Order \n");
						for(i = 0 ; i < all_account ; i++)
						{
						    for(j = 0 ; j < all_account-i-1 ; j++)
						    {
						        if(strcmp(Tab_C[j].Nom, Tab_C[j+1].Nom) < 0)
						        {
						        	temp_account = Tab_C[j+1];
						            Tab_C[j+1]=Tab_C[j];
						            Tab_C[j]=temp_account;
						        }
						    }
						}

						printf("CIN \t lastname \t Name \t Amount\n\n");
						for (i = 0 ; i < all_account ; i++) {
							printf("%s \t %s \t %s \t %g \n", Tab_C[i].CIN, Tab_C[i].Nom, Tab_C[i].Prenom, Tab_C[i].Montant);
						}
						break;
				}

				break;

			case 3 :
				cleanCls();
					int i ;
					int p ;
					char CIN[10];
					bool get_it=false;
					printf("Entrer your CIN code : ");
					scanf("%s",CIN);
					for(i = 0; i < all_account; i++) {
						if (strcmp(CIN, Tab_C[i].CIN) == 0) {
							get_it=true;
							p=i;
						}
					}
						if (get_it)
							printf("CIN code found \t\t lastname : %s \t Name : %s \t CIN : %s \t amount : %f", Tab_C[p].Nom, Tab_C[p].Prenom, Tab_C[p].CIN, Tab_C[p].Montant);
						else
							printf("not found !!! \n \n");
				break;
		}
	}while (_choice != 0);
}
//+ 1.3%
bool fedilisation() {
	int i, j;
    struct account temp_account;
	for(i = 0 ; i < all_account ; i++){
	    for(j = 0 ; j < all_account-i-1 ; j++){
	        if(Tab_C[j].Montant < Tab_C[j+1].Montant){
	        	temp_account = Tab_C[j+1];
	            Tab_C[j+1]=Tab_C[j];
	            Tab_C[j]=temp_account;
	        }
	    }
	}
	for (i = 0 ; i < 3 ; i++)
		Tab_C[i].Montant += (Tab_C[i].Montant * 1.3) / 100;

	cleanCls();
	printf("lastname : %s \t Name : %s \t CIN : %s \t amount : %f", Tab_C[i].Nom, Tab_C[i].Prenom, Tab_C[i].CIN, Tab_C[i].Montant);
	printf("1.3 %% of fedilisation uploaded to the three higher accounts ");
}


int main(){
	int choice, allNewaccount, i;
	char data[50], CIN[10];



//Main Menu .

	do {
        printf("\n");
        printf("\t\t\t\t\t+Welcome to CodeBank Managment+\n\n\n\n");

		printf("\t\t\t 1  : Introduce an Account . \n\n");
		printf("\t\t\t 2  : Add Multiply Accounts. \n\n");
		printf("\t\t\t 3  : Operations . \n\n");
		printf("\t\t\t 4  : Infos .\n\n");
		printf("\t\t\t 5  : Fedilisation .\n\n\n");
		printf("\t\t\t 0  : Exit . \n\n");

		printf("\t\n\n\nSelect an Option   : ");
		scanf("%d", &choice);

		switch (choice) {
			case 1 :
				cleanCls();
				if(add_account(1)){
					printf("Your account is created ");
				} else {
					printf("Error404");
				}
				break;
			case 2 :
				cleanCls();
				printf("Enter the number of accounts that you want to create : ");
				scanf("%d", &allNewaccount);
				add_account(allNewaccount);
				break;
			case 3 :
				cleanCls();
				operations();
				break;
			case 4 :
				cleanCls();
				display();
				break;
			case 5 :
				cleanCls();
				fedilisation();
				break;
		}


	}    while(choice != 0);


	return 0;
}
