#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[50],email[70],account[15],password[20];
}Holder;
   Holder acc1;
typedef struct
    {
        char names[50],accNo[15],date[12],chequeNo[10];
        char status[10];
        float amt;
    }cheque;
    cheque payee;
int n;
char filename[75];
void createAcc();
void login();
void writeCheque(char password[], char email[]);
void viewStatement(char email[]);


void createAcc(){

   Holder acc1;
   char filename[80];
printf("Enter the following details to create your account:\n");
printf("Name: ");
scanf(" %[^\n]",acc1.name);
printf("Email address: ");
scanf(" %[^\n]",acc1.email);
printf("Account number: ");
scanf(" %[^\n]",acc1.account);
printf("Create new password: ");
scanf(" %[^\n]",acc1.password);

sprintf(filename,"%s.txt",acc1.email);

FILE* fptr;

fptr= fopen(filename,"w");
if (fptr==NULL){
    printf("Account NOT created!!! Try again later");
    return;
}
fprintf(fptr,"%s\n",acc1.name);
fprintf(fptr,"%s\n",acc1.email);
fprintf(fptr,"%s\n",acc1.account);
fprintf(fptr,"%s\n",acc1.password);

fclose(fptr);

printf("Account successfully created. WELCOME");
}

void login(){

   Holder acc1;
   char filename[80],pass1[80];
   int option;
   printf("Enter email address: ");
   scanf(" %[^\n]",acc1.email);
   sprintf(filename,"%s.txt",acc1.email);
   FILE* fptr;
   fptr=fopen(filename,"r");
   if(fptr==NULL){
    printf("Account does not exist");
    return;
   }
    fscanf(fptr, " %[^\n]", acc1.name);
    fscanf(fptr, " %[^\n]", acc1.email);
    fscanf(fptr, " %[^\n]", acc1.account);
    fscanf(fptr, " %[^\n]", acc1.password);

   fclose(fptr);

   printf("Password: ");
   scanf(" %[^\n]",pass1);

  if(strcmp(acc1.password,pass1)==0)
   {
       printf("\nWELCOME %s\n",acc1.name);
       do{
       printf("\nPick one option:\n1. Write a new cheque.\n2. View E-Cheque statement.\n3. Sign out\n");
       scanf("%d",&option);
       switch(option){
       case 1:
        writeCheque(acc1.password,acc1.email);
        break;
       case 2:
        viewStatement(acc1.email);
        break;
       case 3:
        printf("\nSigned Out of your account.");

        break;

       default:
        printf("Invalid input!!!");}
       }while(option!=3);
   }
   else{
    printf("\nPassword incorrect!!!\n");
    return;
   }


   int
void writeCheque(char password[],char email[])
{




    printf("Enter the name of the payee: ");
    scanf(" %[^\n]",payee.names);
    printf("Account number: ");
    scanf(" %[^\n]",payee.accNo);
    printf("Date (DD/MM/YYYY): ");
    scanf(" %[^\n]",payee.date);
    printf("Cheque No.: ");
    scanf(" %[^\n]",payee.chequeNo);
    printf("Amount: ");
    scanf("%f",&payee.amt);



           printf("\n\n\t\tCONFIRMATION\n\n");

   printf("Name: %s\nAccount number: %s\nDate: %s\nCheque No.: %s\nAmount: Ksh. %.2f",
          payee.names,payee.accNo,payee.date,payee.chequeNo,payee.amt);
          printf("\n-------------------------------------\n");


    char pass2[12];

    printf("\nEnter password to confirm and generate cheque: ");
    scanf(" %[^\n]",pass2);

    sprintf(filename,"%s_sent.txt",email);

    if(strcmp(password,pass2)==0){
        FILE* fptr1;
            sprintf(filename,"%s_sent.txt",email);
    fptr1=fopen(filename,"a");


        fprintf(fptr1,"%s\n",payee.names);
        fprintf(fptr1,"%s\n",payee.accNo);
        fprintf(fptr1,"%s\n",payee.date);
        fprintf(fptr1,"%s\n",payee.chequeNo);
        fprintf(fptr1,"%f\n",payee.amt);
        strcpy(payee.status, "SENT");
        fprintf(fptr1,"%s\n",payee.status);


        fclose(fptr1);
        printf("\n\n");

        printf("\n--------------------------------------------------\n");
        printf("\t\tEQUITY BANK\n");
        printf("Cheque No. %-10s\tDate: %10s",payee.chequeNo,payee.date);
        printf("\n--------------------------------------------------\n");
        printf("Pay to: %s\tAmount(Ksh):%10.2f\n",payee.names,payee.amt);
        printf("\n%10s","Signature_____________");
        printf("\n--------------------------------------------------\n");



        printf("\nCheque successfully generated and sent to %s\n",payee.names);
        }



    else{
        printf("Incorrect Password. Cheque not sent");
        FILE* fptr2;
        sprintf(filename,"%s_pending.txt",email);
        fptr2=fopen(filename,"a");


        fprintf(fptr2,"%s\n",payee.names);
        fprintf(fptr2,"%s\n",payee.accNo);
        fprintf(fptr2,"%s\n",payee.date);
        fprintf(fptr2,"%s\n",payee.chequeNo);
        fprintf(fptr2,"%f\n",payee.amt);
        strcpy(payee.status, "PENDING");
        fprintf(fptr2,"%s\n",payee.status);


        fclose(fptr2);
    }

}

void viewStatement(char email[])
{
    int choice;

    printf("Pick statement to view:\n1. Sent Cheques\n2. Pending cheques\n");
    scanf("%d",&choice);

    FILE* fptr;
    if(choice == 1){
        printf("\n\n\t\tSENT STATEMENT\n\n------------------------------------------------------------\n");
        sprintf(filename,"%s_sent.txt",email);}
    else{
        printf("\n\n\t\tPENDING STATEMENT\n\n------------------------------------------------------------\n");
        sprintf(filename,"%s_pending.txt",email);}

    fptr = fopen(filename,"r");
    if(fptr == NULL){
        printf("No transactions found\n");
        return;
    }

    printf("%-10s %-35s %-10s %-12s %-8s\n","Cheque No.","Name","Amount","Date","Status");


    while (1) {
    if (fscanf(fptr, " %[^\n]", payee.names) != 1) break;
    if (fscanf(fptr, " %[^\n]", payee.accNo) != 1) break;
    if (fscanf(fptr, " %[^\n]", payee.date) != 1) break;
    if (fscanf(fptr, " %[^\n]", payee.chequeNo) != 1) break;
    if (fscanf(fptr, " %f", &payee.amt) != 1) break;
    if (fscanf(fptr, " %[^\n]", payee.status) != 1) break;

    printf("%-10s %-35s %-10.2f %-12s %-8s\n",
           payee.chequeNo, payee.names, payee.amt, payee.date, payee.status);
}

    fclose(fptr);
}




int main()
{
    int choice;
    do{
    printf("\n\t\tLOGIN PAGE");
    printf("\n1. Login to an existing account\n2. Create a new account\n3. Exit this page\n\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        login();

        break;
    case 2:
        createAcc();
        break;
    case 3:
        printf("Thank you for visiting E-Cheque");
        break;
    default:
        printf("Incorrect input. Please enter 1,2 or 3.\n\n");
    }
    }while(choice!=3);
return 0;
}
