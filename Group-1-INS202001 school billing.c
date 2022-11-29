#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
 int id;
 char name[50];
 char de[10];
 int cre;
 int fee;
 int debt;
}student;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
    student *s;
    int j, i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n) ;
    printf("\n\n**Please don't add space to the name!* \n\n");
    s = (student*)calloc(n, sizeof(student)); // What led you to this ?
    FILE *fp;
    fp = fopen("Record.txt", "w");

    for(i=0; i<n; i++){
    printf("Student [%d] id :", i);
    scanf("%d", &s[i].id);
    printf("Student [%d] name :", i);
    scanf("%s", s[i].name);
    printf("Student [%d] credits registered: ", i);
    scanf("%d", &s[i].cre);

    int flag = 1;
    while(flag==1){

    printf("Student [%d] training program :", i);
    scanf("%s", s[i].de);

    for(j=0;j<=strlen(s[i].de);j++){
      if(s[i].de[j]>=97&&s[i].de[j]<=122)
         s[i].de[j]=s[i].de[j]-32;
    }

    if (strcmp(s[i].de,"MIS")==0 || strcmp(s[i].de,"ICE")==0 || strcmp(s[i].de,"AC")==0){
        flag = 0;
        s[i].fee = s[i].cre * 1300000;
    }
    else if(strcmp(s[i].de,"IB")==0 || strcmp(s[i].de,"BDA")==0){
        flag = 0;
        s[i].fee = s[i].cre * 1500000;
    }
    else if(strcmp(s[i].de,"KEUKA")==0 || strcmp(s[i].de,"TROY")==0 || strcmp(s[i].de,"UEL")==0){
        flag = 0;
        s[i].fee = s[i].cre * 2000000;
    }
    else {
        printf("\n-> Invalid training program! Please try again <-\n");
    }

    }
    s[i].debt = s[i].fee;

    fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
//DISPLAY THE ENTERED RECORDS
void disp()
{
    student s;
    FILE *fp;
    fp = fopen("Record.txt", "r");
    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n","ID","Name","Program", "Credits","TotalFee","TotalDebt");
    printf("-------------------------------------------------------------------------------------------------\n");
    while (fread(&s, sizeof(student), 1, fp)){
        printf("%-8d\t%-10s\t%-10s\t%-10d\t%-15d\t%-8d\n", s.id, s.name, s.de, s.cre, s.fee, s.debt);
    }
    fclose(fp);
}
//INSERT MORE RECORD
void append(){

    student *s;
    int j, i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n) ;
    printf("\n\n**Please don't add space to the name!** \n\n");
    s = (student*)calloc(n, sizeof(student));
    FILE *fp;
    fp = fopen("Record.txt", "a");

    for(i=0; i<n; i++){
    printf("Student [%d] id :", i);
    scanf("%d", &s[i].id);
    printf("Student [%d] name :", i);
    scanf("%s", s[i].name);
    printf("Student [%d] credits registered: ", i);
    scanf("%d", &s[i].cre);

    int flag = 1;
    while(flag==1){

    printf("Student [%d] training program :", i);
    scanf("%s", s[i].de);

    for(j=0;j<=strlen(s[i].de);j++){
      if(s[i].de[j]>=97&&s[i].de[j]<=122)
         s[i].de[j]=s[i].de[j]-32;
    }

    if (strcmp(s[i].de,"MIS")==0 || strcmp(s[i].de,"ICE")==0 || strcmp(s[i].de,"AC")==0){
        flag = 0;
        s[i].fee = s[i].cre * 1300000;
    }
    else if(strcmp(s[i].de,"IB")==0 || strcmp(s[i].de,"BDA")==0){
        flag = 0;
        s[i].fee = s[i].cre * 1500000;
    }
    else if(strcmp(s[i].de,"KEUKA")==0 || strcmp(s[i].de,"TROY")==0 || strcmp(s[i].de,"UEL")==0){
        flag = 0;
        s[i].fee = s[i].cre * 2000000;
    }
    else {
        printf("\n-> Invalid training program! Please try again <-\n");
    }

    }
    s[i].debt = s[i].fee;

    fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
//DELETE RECORD
void del(){
    student s;
    int id, pay;
    int found = 0;
    FILE *fp, *fp1;
    fp = fopen("Record.txt", "r");
    fp1 = fopen("Temp.txt","w");
    printf("Enter the student Id that you want to delete record: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(student), 1, fp)){
        if(s.id == id){
            found = 1;
            printf("Successfully delete student [%d] !", id);
        }
        else {
            fwrite(&s, sizeof(student),1,fp1);
        }
    }
    if(found == 0){
        printf("\nRecord not found!\n");
    }
    fclose(fp);
    fclose(fp1);

    fp1 = fopen("Temp.txt","r");
    fp = fopen("Record.txt", "w");

    while (fread(&s, sizeof(student), 1, fp1)){
        fwrite(&s, sizeof(student),1,fp);
    }

    fclose(fp);
    fclose(fp1);
}
//DISPLAY NUMBER OF RECORDS
void nor(){
    student s;
    FILE *fp;
    fp = fopen("Record.txt", "r");
    fseek(fp,0,SEEK_END);
    int n= ftell(fp)/sizeof(student);
    printf("\n\n Current number of records is: %d\n\n", n);
    fclose(fp);
}
//SEARCH RECORD BY STUDENT ID
void search(){
    student s;
    int id;
    int found = 0;
    FILE *fp;
    fp = fopen("Record.txt", "r");
    printf("Enter the student Id you want to search: ");
    scanf("%d", &id);
    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n","ID","Name","Program", "Credits","TotalFee","TotalDebt");
    printf("-------------------------------------------------------------------------------------------------\n");
    while (fread(&s, sizeof(student), 1, fp)){
        if(s.id == id){
            found = 1;
            printf("%-8d\t%-10s\t%-10s\t%-10d\t%-15d\t%-8d\n", s.id, s.name, s.de, s.cre, s.fee, s.debt);
        }
    }
    if(found == 0){
        printf("\nRecord not found!\n");
    }
    fclose(fp);
}
//ENTER THE PAYMENT
void payment(){
    student s;
    int id, pay;
    int found = 0;
    FILE *fp, *fp1;
    fp = fopen("Record.txt", "r");
    fp1 = fopen("Temp.txt","w");
    printf("Enter the student Id that makes the payment: ");
    scanf("%d", &id);
    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n","ID","Name","Program", "Credits","TotalFee","TotalDebt");
    printf("-------------------------------------------------------------------------------------------------\n");
    while (fread(&s, sizeof(student), 1, fp)){
        if(s.id == id){
            found = 1;
            printf("%-8d\t%-10s\t%-10s\t%-10d\t%-15d\t%-8d\n", s.id, s.name, s.de, s.cre, s.fee, s.debt);
            printf("\n\nEnter the amount paid: ");
            scanf("%d", &pay);
            if(pay<=s.debt){
                s.debt = s.debt - pay;
                printf("New debt: %d", s.debt);
            }
            else{
                printf("The amount paid have to be smaller of equal to the student's debt!\n");
            }
        }
        fwrite(&s, sizeof(student),1,fp1);
    }
    if(found == 0){
        printf("\nRecord not found!\n");
    }
    fclose(fp);
    fclose(fp1);

    fp1 = fopen("Temp.txt","r");
    fp = fopen("Record.txt", "w");

    while (fread(&s, sizeof(student), 1, fp1)){
        fwrite(&s, sizeof(student),1,fp);
    }

    fclose(fp);
    fclose(fp1);
}
//SORT STUDENT IN DESCENDING ORDER BASE ON THEIR DEPT (ONLY PRINT OUT THOSE WHO HAVEN'T FINISHED PAYING THE FEE)
void nopay(){
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("Record.txt", "r");
    fseek(fp,0, SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));
    rewind(fp);
    for(i=0; i<n; i++)
    {
        fread(&s[i], sizeof(student), 1, fp);
    }

    for (i=0; i<n-1; i++)
    {

            for(j=i+1; j<n; j++)
            {
                if(s[i].debt < s[j].debt){
                    s1 = s[i];
                    s[i] = s[j];
                    s[j]=s1;
                }
            }

    }


    printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n","ID","Name","Program", "Credits","TotalFee","TotalDebt");
    printf("-------------------------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++){
        if(s[i].debt > 0){
            printf("%-8d\t%-10s\t%-10s\t%-10d\t%-15d\t%-8d\n", s[i].id, s[i].name, s[i].de, s[i].cre, s[i].fee, s[i].debt);
        }
    }
    fclose(fp);
}
//MENU FUNCTION
void menu(){
 int c;
    do
 {
  printf("\n\t\t\t\t\t\t---MAIN MENU---\n");
  printf("\n\t\t\t\t\t\t1. INSERT AND CALCULATE FEE\n\t\t\t\t\t\t2. DISPLAY\n\t\t\t\t\t\t3. SEARCH");
  printf("\n\t\t\t\t\t\t4. DELETE\n\t\t\t\t\t\t5. APPEND\n\t\t\t\t\t\t6. NO OF RECORDS");
  printf("\n\t\t\t\t\t\t7. ENTER PAYMENT\n\t\t\t\t\t\t8. DISPLAY STUDENTS WHO HAVEN'T PAID THEIR FEE");
  printf("\n\t\t\t\t\t\t9. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   menu();
   break;
  case 2:
    disp();
    menu();
   break;
  case 4:
    del();
    menu();
   break;
  case 3:
    search();
    menu();
   break;
  case 5:
    append();
    menu();
   break;
  case 6:
    nor();
    menu();
   break;
  case 7:
    payment();
    menu();
   break;
  case 8:
    nopay();
    menu();
   break;
  case 9:
  	printf("\n\t\t\tThank you for using our program.");
  	exit(0);
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 9);

}
void main()
{
    printf("\t\t\t\t*********************************************\n");
	printf("\t\t\t\tWELCOME TO SCHOOL BILLING MANAGEMENT SYSTEM\n");
	printf("\t\t\t\t*********************************************\n");
	printf("\t\t\t\t\tBy: Group 1 - INS202003\n\n\n");

    menu();
}

