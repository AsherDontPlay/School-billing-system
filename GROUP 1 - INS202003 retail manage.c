#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
////////////////////////////WELCOME TO OUR PROGRAM////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

typedef struct customer
{
    int id;
    char name[50];
    char me[20];
    int amount;
    int fee;
    int debt;
    char date[10];
    char method[10];
    int price;
}customer;


//    FUNCTION TO INSERT RECORDS TO THE FILE
void append() {

    customer* s;
    int j, i, n;
    system("cls");
    printf("Enter the number of customers: ");
    scanf("%d", &n);
    printf("\n\n**Please don't add space to the name!** \n\n");
    s = (customer*)calloc(n, sizeof(customer));
    FILE* fp;
    fp = fopen("Cpharma.txt", "a");

    for (i = 0; i < n; i++) {
        printf("\nOrder ID [%d]: ", i);
        scanf("%d", &s[i].id);
        printf("\nCustomer [%d] name: ", i);
        scanf("%s", s[i].name);

        printf("                  Add order details\n");
        printf("---------------------------------------------------------------\n");
        printf(" DRUG ID\t\tDRUG NAME\t\tDRUG PRICE(VND)\n");
        printf("---------------------------------------------------------------\n");
        printf("   01\t\t\tParacetamol\t\t   24000\n");
        printf("   02\t\t\tSalonpas\t\t   28000\n");
        printf("   03\t\t\tPanadol\t\t\t   15000\n");
        printf("   04\t\t\tBerberin\t\t   45000\n");
        printf("   05\t\t\tVitamin B1\t\t   60000\n");
        printf("   06\t\t\tMedrol\t\t\t   120000\n");
        printf("   07\t\t\tOpeclari\t\t   45000\n");
        printf("   08\t\t\tAmmuson\t\t\t   30000\n");
        printf("   09\t\t\tFloxaval\t\t   15000\n");
        printf("   10\t\t\tDrenoxol\t\t   60000\n");
        printf("---------------------------------------------------------------\n");

        int flag = 1;
        while (flag == 1) {

            printf("\nCustomer [%d] medicine type: ", i);
            scanf("%s", s[i].me);

            if (strcmp(s[i].me, "1") == 0 || strcmp(s[i].me, "01") == 0) {
                flag = 0;
                s[i].price = 12000;
                printf("--> Paracetamol ~ 12000/pack\n");
                strcpy(s[i].me, "Paracetamol");
            }
            else if (strcmp(s[i].me, "2") == 0 || strcmp(s[i].me, "02") == 0) {
                flag = 0;
                s[i].price = 28000;
                printf("--> Salonpas ~ 28000/patch\n");
                strcpy(s[i].me, "Salonpas");
            }
            else if (strcmp(s[i].me, "3") == 0 || strcmp(s[i].me, "03") == 0) {
                flag = 0;
                s[i].price = 15000;
                printf("--> Panadol ~ 15000/pack\n");
                strcpy(s[i].me, "Panadol");

            }
            else if (strcmp(s[i].me, "4") == 0 || strcmp(s[i].me, "04") == 0) {
                flag = 0;
                s[i].price = 45000;
                printf("--> Berberin ~ 45000/pillbox\n");
                strcpy(s[i].me, "Berberin");
            }
            else if (strcmp(s[i].me, "5") == 0 || strcmp(s[i].me, "05") == 0) {
                flag = 0;
                s[i].price = 60000;
                printf("--> Vitamin B1 ~ 60000/tube\n");
                strcpy(s[i].me, "Vitamin B1");
            }
            else if (strcmp(s[i].me, "6") == 0 || strcmp(s[i].me, "06") == 0) {
                flag = 0;
                s[i].price = 120000;
                printf("--> Medrol ~ 120000/pillbox\n");
                strcpy(s[i].me, "Medrol");
            }
            else if (strcmp(s[i].me, "7") == 0 || strcmp(s[i].me, "07") == 0) {
                flag = 0;
                s[i].price = 45000;
                printf("--> Opeclari ~ 45000/pillbox\n");
                strcpy(s[i].me, "Opeclari");
            }
            else if (strcmp(s[i].me, "8") == 0 || strcmp(s[i].me, "08") == 0) {
                flag = 0;
                s[i].price = 30000;
                printf("--> Ammuson ~ 30000/pack\n");
                strcpy(s[i].me, "Ammuson");
            }
            else if (strcmp(s[i].me, "9") == 0 || strcmp(s[i].me, "09") == 0) {
                flag = 0;
                s[i].price = 15000;
                printf("--> Floxaval ~ 15000/pillbox\n");
                strcpy(s[i].me, "Floxaval");
            }
            else if (strcmp(s[i].me, "10") == 0) {
                flag = 0;
                s[i].price = 60000;
                printf("--> Drenoxol ~ 60000/patch\n");
                strcpy(s[i].me, "Drenoxol");
            }
            else {
                printf("\n-> Invalid Medicine type! Please try again <-\n");
            }

        }
        printf("\nCustomer [%d] amount of quantity: ", i);
        scanf("%d", &s[i].amount);

        s[i].fee = s[i].price * s[i].amount;
        s[i].debt = s[i].fee;

        flag = 1;
        while (flag == 1) {

            printf("\nOrder date xx/yy [%d]: ", i);
            scanf("%s", s[i].date);
            printf("\nPayment method for order [%d]: \n", i);
            printf("1. Cash\n2. Debit Card\n3. E-banking\n Choose a payment method: ");
            scanf("%s", s[i].method);

            if (strcmp(s[i].method, "1") == 0) {
                flag = 0;
                printf("\n==>Payment in cash\n");
                strcpy(s[i].method, "Cash");
            }
            else if (strcmp(s[i].method, "2") == 0) {
                flag = 0;
                printf("\n==>Payment by debit card\n");
                strcpy(s[i].method, "Debit card");
            }
            else if (strcmp(s[i].method, "3") == 0) {
                flag = 0;
                printf("\n==>Payment via e-banking\n");
                strcpy(s[i].method, "E-banking");
            }
            else {
                printf("\n->Invalid Payment method! Please try again <-\n");
            }
        }
        fwrite(&s[i], sizeof(customer), 1, fp);
    }
    fclose(fp);
    printf("Successfuly append! Press any key to continue.");
    getch();

}

void disp()
{
    customer s;
    system("cls");
    FILE* fp;
    fp = fopen("Cpharma.txt", "r");
    printf("\n%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n","Order No","Name","Medicine","Price", "Amount","TotalFee","Payment method","Date");
    printf("====================================================================================================================================\n");
    while (fread(&s, sizeof(customer), 1, fp)) {
        printf("%-8d\t%-10s\t%-10s\t\t%-15d\t%-10d\t%-15d\t%-10s\t\t%-10s\n", s.id, s.name, s.me, s.price, s.amount, s.fee, s.method, s.date);
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();

}
// SORT BY TOTAL COST
void sort() {
    customer* s, s1;
    FILE* fp;
    int i, j;
    system("cls");
    fp = fopen("Cpharma.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(customer);
    s = (customer*)calloc(n, sizeof(customer));

    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(customer), 1, fp);
    }
    for (i = 0; i < n - 1; i++)
    {

        for (j = i + 1; j < n; j++)
        {
            if (s[i].fee < s[j].fee) {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }

    }
    printf("\n%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n","Order No","Name","Medicine","Price", "Amount","TotalFee","Payment method","Date");
    printf("====================================================================================================================================\n");
    for (i = 0; i < n; i++) {
        if (s[i].fee > 0) {
            printf("%-8d\t%-10s\t%-10s\t\t%-15d\t%-10d\t%-15d\t%-10s\t\t%-10s\n", s[i].id, s[i].name, s[i].me, s[i].price, s[i].amount, s[i].fee, s[i].method, s[i].date);
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();

}

//SEARCH RECORD ID ORDER
void search() {

    customer s;
    int i;
    int id;
    int found = 0;
    system("cls");
    FILE* fp;
    fp = fopen("Cpharma.txt", "r");

    printf("Enter the ID Order you want to search: ");
    scanf("%d", &id);
    printf("\n%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s\n","Order No","Name","Medicine","Price", "Amount","TotalFee","Payment method","Date");
    printf("====================================================================================================================================\n");
    while (fread(&s, sizeof(customer), 1, fp)) {
        if (s.id == id) {
            found = 1;
            printf("%-8d\t%-10s\t%-10s\t\t%-15d\t%-10d\t%-15d\t%-10s\t\t%-10s\n", s.id, s.name, s.me, s.price, s.amount, s.fee, s.method, s.date);
        }
    }
    if (found == 0) {
        printf("\nRecord not available!\n");
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
}

//DELETE RECORD
void del()
{
    customer s;
    int id, pay;
    int found = 0;
    system("cls");
    FILE* fp, * fp1;
    fp = fopen("Cpharma.txt", "r+");
    fp1 = fopen("Temp.txt", "w");
    printf("Enter the Order Id that you want to delete record: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(customer), 1, fp))
    {
        if (s.id == id)
        {
            found = 1;
            printf("Successfully delete record [%d] !", id);
        }
        else
        {
            fwrite(&s, sizeof(customer), 1, fp1);
        }
    }
    if (found == 0)
    {
        printf("\nRecord not found!\n");
    }
    fclose(fp);
    fclose(fp1);

    fp1 = fopen("Temp.txt", "r");
    fp = fopen("Cpharma.txt", "wb+");

    while (fread(&s, sizeof(customer), 1, fp1))
    {
        fwrite(&s, sizeof(customer), 1, fp);
    }

    fclose(fp);
    fclose(fp1);
    printf("Press any key to continue.");
    getch();

}

// UPDATE RECORD
int avlrollno(int rno)
{
    customer s;
    FILE* fp;
    int c = 0;
    fp = fopen("Cpharma.txt", "r");
    while (!feof(fp))
    {
        fread(&s, sizeof(customer), 1, fp);

        if (rno == s.id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();

    return 0;
}

void update(){
    customer s;
    system("cls");
    int x, r,ch,t, avl;
    FILE *fp;
    FILE *fp1;
    printf("Enter the Order Id that you want to edit record: ");
    scanf("%d", &r);
    avl = avlrollno(r);
    if (avl == 0){
        printf("\nID number %d is not Available in the file",r);
    }
    else
    {
    fp = fopen("Cpharma.txt", "r");
    fp1= fopen("Temp.txt", "w");
    while (fread(&s, sizeof(customer), 1, fp)){
        x = s.id;
        if(x != r)
            fwrite(&s, sizeof(customer), 1, fp1);
        else{
            printf("\n\t1. Update name of ID '%d'", r);
            printf("\n\t2. Update medicine of ID '%d'", r);
            printf("\n\t3. Update amount of ID '%d'", r);
            printf("\n\t4. Update payment method of ID '%d'", r);
            printf("\n\t5. Update date of ID '%d'", r);
            printf("\nEnter your choice:");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                printf("Enter new Name:");
                scanf("%s", &s.name);
                break;
            case 2:
                printf("                  Add order details\n");
    		printf("---------------------------------------------------------------\n");
    		printf(" DRUG ID\t\tDRUG NAME\t\tDRUG PRICE(VND)\n");
    		printf("---------------------------------------------------------------\n");
    		printf("   01\t\t\tParacetamol\t\t   24000\n");
    		printf("   02\t\t\tSalonpas\t\t   28000\n");
    		printf("   03\t\t\tPanadol\t\t\t   15000\n");
    		printf("   04\t\t\tBerberin\t\t   45000\n");
    		printf("   05\t\t\tVitamin B1\t\t   60000\n");
    		printf("   06\t\t\tMedrol\t\t\t   120000\n");
    		printf("   07\t\t\tOpeclari\t\t   45000\n");
    		printf("   08\t\t\tAmmuson\t\t\t   30000\n");
    		printf("   09\t\t\tFloxaval\t\t   15000\n");
    		printf("   10\t\t\tDrenoxol\t\t   60000\n");
    		printf("---------------------------------------------------------------\n");
                printf("Enter new Medicine: ");
                scanf("%s", s.me);

                int flag = 1;
                while(flag==1){
                if (strcmp(s.me,"1")==0 || strcmp(s.me,"01")==0){
                flag = 0;
                s.price = 12000;
                printf("--> Paracetamol ~ 12000/pack\n");
                strcpy(s.me, "Paracetamol" );
                }
                else if(strcmp(s.me,"2")==0 || strcmp(s.me,"02")==0){
                flag = 0;
                s.price = 28000;
                printf("--> Salonpas ~ 28000/patch\n");
                strcpy(s.me, "Salonpas" );
                }
                else if(strcmp(s.me,"3")==0 || strcmp(s.me,"03")==0){
                flag = 0;
                s.price = 15000;
                printf("--> Panadol ~ 15000/pack\n");
                strcpy(s.me, "Panadol" );
                }
                else if(strcmp(s.me,"4")==0 || strcmp(s.me,"04")==0){
                flag = 0;
                s.price = 45000;
                printf("--> Berberin ~ 45000/pillbox\n");
                strcpy(s.me, "Berberin" );
                }
                else if(strcmp(s.me,"5")==0 || strcmp(s.me,"05")==0){
                flag = 0;
                s.price = 60000;
                printf("--> Vitamin B1 ~ 60000/tube\n");
                strcpy(s.me, "Vitamin B1" );
                }
                else if(strcmp(s.me,"6")==0 || strcmp(s.me,"06")==0){
                flag = 0;
                s.price = 120000;
                printf("--> Medrol ~ 120000/pillbox\n");
                strcpy(s.me, "Medrol" );
                }
                else if(strcmp(s.me,"7")==0 || strcmp(s.me,"07")==0){
                flag = 0;
                s.price = 45000;
                printf("--> Opeclari ~ 45000/pillbox\n");
                strcpy(s.me, "Opeclari" );
                }
                else if(strcmp(s.me,"8")==0 || strcmp(s.me,"08")==0){
                flag = 0;
                s.price = 30000;
                printf("--> Ammuson ~ 30000/pack\n");
                strcpy(s.me, "Ammuson" );
                }
                else if(strcmp(s.me,"9")==0 || strcmp(s.me,"09")==0){
                flag = 0;
                s.price = 15000;
                printf("--> Floxaval ~ 15000/pillbox\n");
                strcpy(s.me, "Floxaval" );
                }
                else if(strcmp(s.me,"10")==0){
                flag = 0;
                s.price = 60000;
                printf("--> Drenoxol ~ 60000/patch\n");
                strcpy(s.me, "Drenoxol" );
                }
                else {
                printf("\n-> Invalid Medicine type! Please try again <-\n");
                }
                }
                s.fee = s.price * s.amount;
                s.debt = s.fee;

                break;
            case 3:
                printf("Enter new Amount: ");
                scanf("%d", &s.amount);

                s.fee = s.price * s.amount;

                break;
            case 4:
		    printf("1. Cash\n2. Debit Card\n3. E-banking\n");
                printf("Enter new Payment Method: ");
                scanf("%s", s.method);

                flag = 1;
                while(flag==1){

                if (strcmp(s.method,"1")==0){
                flag = 0;
                printf("\n==>Payment in cash\n");
                strcpy(s.method, "Cash" );

                }
                else if(strcmp(s.method,"2")==0){
                flag = 0;
                printf("\n==>Payment by debit card\n");
                strcpy(s.method, "Debit card" );

                }
                else if(strcmp(s.method,"3")==0){
                flag = 0;
                printf("\n==>Payment via e-banking\n");
                strcpy(s.method, "E-banking" );
                }
                else {
                printf("\n->Invalid Payment method! Please try again <-\n");
                }
                }
                break;
            case 5:
                printf("Enter new Date: ");
                scanf("%s", &s.date);
                break;
            default:
                printf("Invalid Selection");
                break;
            }
            fwrite(&s, sizeof(customer), 1, fp1);
        }
    }
        fclose(fp);
        fclose(fp1);
        fp = fopen("Cpharma.txt", "w");
        fp1= fopen("Temp.txt", "r");
        while (fread(&s, sizeof(customer), 1, fp1))
        {
            fwrite(&s, sizeof(customer), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
        printf("\n-> RECORD UPDATED <-\n");
        printf("Press any key to continue.");
        getch();
        }
    }

void menu() {
    int c;
    system("cls");
    do
    {
        printf("\n\n\t\t\t\t\t**********************************************\n");
        printf("\t\t\t\t\t\t\tWELCOME TO C-PHARMACITY\n");
        printf("\t\t\t\t\t**********************************************\n");
        printf("\t\t\t\t\t\t  By: Group 1 - INS202003\n\n\n");

        printf("\n\t\t\t\t\t\t========== MAIN MENU ==========\n");
        printf("\n\t\t\t\t\t\t1. APPEND AND CALCULATE FEE\n\t\t\t\t\t\t2. DISPLAY\n\t\t\t\t\t\t3. SORT BY TOTAL COST");
        printf("\n\t\t\t\t\t\t4. SEARCH\n\t\t\t\t\t\t5. DELETE \n\t\t\t\t\t\t6. UPDATE ");
        printf("\n\t\t\t\t\t\t7. EXIT");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            append();
            menu();
            break;
        case 2:
            disp();
            menu();
            break;
        case 3:
            sort();
            menu();
            break;
        case 4:
            search();
            menu();
            break;
        case 5:
            del();
            menu();
            break;
        case 6:
            update();
            menu();
            break;
        case 7:
            printf("\n\t\t\tThank you for using our program.");
            exit(0);
        default:
            printf("\nYour choice is wrong\nPlease try again...\n");
            break;
        }
    } while (c != 7);
}

void main() {
    char name[30];
    char password[30];
    int i = 0;
    char ch;

    system("color 0E");
    printf("\n\tEnter username: ");
    scanf("%s", name);
    printf("\n\tEnter password: ");
    while ((ch = _getch()) != 13) {
        password[i] = ch;
        i++;
        printf("*");
    }
    if (strcmp(name, "admin") == 0 && strcmp(password, "richman") == 0)
    {
        printf("\n\t\t\t\t\t\t>> Access granted <<\n");
        printf("\n\t\t\t\t\t\tPress Enter to proceed!");
        getch();
        menu();
    }
    else {
        printf("\n\t\t\t\tAccess denied, please retry\n");
        main();
    }
}
////////////////////////////THE END OF PROGRAM////////////////////////////
