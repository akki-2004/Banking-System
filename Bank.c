#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
char a[100];
void login(void);
void account(void);
void accountcreated(void);//hi
void display(char*);
void loginsu(void);
void checkbalance(char*);//ha
void transfermoney(void);//ha
void logout(void);
void cheque(void);//hi
void del(void);//hi
void accountdeleted(void);//ha
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
struct pass 
{
	char username[50];
	int date, month, year;
	char pnumber[15];
	char adharnum[20];
	char fname[50];
	char lname[40];
	char fathname[40];
	char mothname[40];
	char address[50];
	char typeaccount[20];
	char pan[20];
};

// Structure to keep track
// of amount transfer
struct money 
{
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass
 {
	char password[50];
};
struct chq 
{
	char fuser[50];
	int id[50];
	char luser[50];
	int pan[50];
	int aad[50];
	int ph[50];
	
};
void intro()
{
	printf("\n\n\n\t  GHAJH");
	printf("\n\n\t  BANKING");
	printf("\n\n\t  SYSTEM");
	printf("\n\n\n\nMADE BY :\n1.Akshay Satya\n2.Himani Garige\n3.Jahnavi\n4.Harina suri\n5.Gautham kedia\n");
	printf("\nUNIVERSITY :\nKeshav Memorial Institute Of Technology");
	
}
int main()
{
	int n;
	intro();
	getch();
	system("cls");//clrscr
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t Welcome to Online Banking System");
	printf("\n\t 1.Create Account");
	printf("\n\t 2.Login");
	printf("\n\t 3.Apply for Cheque book");
	printf("\n\t 4.Delete An Previous Account");
	printf("\n\t 5.Exit\n");
	printf("Enter What You wanna Do:");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			system("cls");
		    printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		    printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		    account();
		    break;
		case 2:
			login();
			break;
	    case 3:
	    	system("cls");
	    	cheque();
	    	break;
	    case 4:
	    	system("cls");
	    	del();
	    	break;
	    case 5:
	    	exit(0);
	    	break;
	}
    
}
void account(void)
{
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;
	struct userpass u2;

	// Opening file to
	// write data of a user
	fp = fopen("username.txt", "ab");
	// Inputs
	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
	
	printf("\n\nFIRST NAME..");
	scanf("%s", &u1.fname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u1.lname);

	printf("\n\nFATHER's NAME..");
	scanf("%s", &u1.fathname);

	printf("\n\nMOTHER's NAME..");
	scanf("%s", &u1.mothname);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u1.typeaccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nADHAR NUMBER");
	scanf("%s", u1.adharnum);
	
	printf("\n\nPAN CARD  NUMBER");
	scanf("%s", u1.pan);

	printf("\n\nPHONE NUMBER");
	scanf("%s", u1.pnumber);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD..");

	// Taking password in the form of
	// stars
	for (i = 0; i < 50; i++) 
	{
		ch = getch();
		if (ch != 13)
		 {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	// Writing to the file
	fwrite(&u1, sizeof(u1),
		1, fp);

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountcreated();
}

// Successful account creation
void accountcreated(void)
{

	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++)
	 {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch(); 
	login();
}
void login(void)
{
	system("cls");
	
	char username[50];
	char password[50];
	
	int i, j, k;
	char ch;
	
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	// Opening file of
	// user data
	fp = fopen("username.txt","rb");

	if (fp == NULL) 
	{
		printf("ERROR IN OPENING FILE");
	}
	
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("*"
		"");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	// Take input
	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	gotoxy(35, 14);
	printf("PASSWORD..");

	// Input the password
	for (i = 0; i < 50; i++)
	 {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	// Checking if username
	// exists in the file or not
	while (fread(&u1, sizeof(u1),1, fp))
	{
		if (strcmp(username,u1.username)== 0)
		{
			loginsu();
			display(username);
		}
	}
	// Closing the file
	fclose(fp);
}

// Redirect after
// successful login
void loginsu(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) 
	{
		i++;
		i--;
	}
	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");
	getch();
}
// Display function to show the
// data of the user on screen
void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	struct pass u1;

	if (fp == NULL) 
	{
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username1,
				u1.username)
			== 0) {
			gotoxy(30, 1);
			printf("WELCOME, %s %s",
				u1.fname, u1.lname);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("*");
			gotoxy(55, 10);
			printf("NAME..%s %s", u1.fname,
				u1.lname);

			gotoxy(55, 12);
			printf("FATHER's NAME..%s %s",
				u1.fathname,
				u1.lname);

			gotoxy(55, 14);
			printf("MOTHER's NAME..%s",
				u1.mothname);

			gotoxy(55, 16);
			printf("AADHAR CARD NUMBER..%s",
				u1.adharnum);

			gotoxy(55, 18);
			printf("MOBILE NUMBER..%s",
				u1.pnumber);

			gotoxy(55, 20);
			printf("DATE OF BIRTH.. %d-%d-%d",
				u1.date, u1.month, u1.year);

			gotoxy(55, 22);
			printf("ADDRESS..%s", u1.address);

			gotoxy(55, 24);
			printf("ACCOUNT TYPE..%s",
				u1.typeaccount);
		}
	}

	fclose(fp);

	gotoxy(0, 6);

	// Menu to perform different
	// actions by user
	printf(" HOME ");
	gotoxy(0, 7);
	printf("");
	gotoxy(0, 9);
	printf(" 1....CHECK BALANCE");
	gotoxy(0, 11);
	printf(" 2....TRANSFER MONEY");
	gotoxy(0, 13);
	printf(" 3....LOG OUT\n\n");
	gotoxy(0, 15);
	printf(" 4....EXIT\n\n");

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkbalance(username1);
		break;

	case 2:
		transfermoney();
		break;

	case 3:
		logout();
		login();
		break;

	case 4:
		exit(0);
		break;
	}
}

// Function to transfer
// money from one user to
// another
void transfermoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	// Opening file in read mode to
	// read user's username
	fp = fopen("username.txt", "rb");

	// Creating a another file
	// to write amount along with
	// username to which amount
	// is going to be transferred
	fm = fopen("mon.txt", "ab");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 11);
	printf("FROM (your username).. ");
	scanf("%s", &usernamet);

	gotoxy(33, 13);
	printf(" TO (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username if it
	// is present in file or not
	while (fread(&u1, sizeof(u1),
				1, fp))

	{
		if (strcmp(usernamep,
				u1.username)
			== 0) {
			strcpy(m1.usernameto,
				u1.username);
			strcpy(m1.userpersonfrom,
				usernamet);
		}
	}
	gotoxy(33, 16);

	// Taking amount input
	printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
	scanf("%d", &m1.money1);

	// Writing to the file
	fwrite(&m1, sizeof(m1),
		1, fm);

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait..");

	gotoxy(10, 27);
	for (i = 0; i < 70; i++) {
		for (j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(33, 40);
	
	printf("\n\n\n\t\t\tAMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	// Close the files
	fclose(fp);
	fclose(fm);

	// Function to return
	// to the home screen
	display(usernamet);
}

// Function to check balance
// in users account
void checkbalance(char username2[])
{
	system("cls");
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;

	// Opening amount file record
	fm = fopen("mon.txt", "rb");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("*");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(m, n);
	printf("TRANSACTION ID");
	gotoxy(u, v);
	printf("AMOUNT");

	// Reading username to
	// fetch the correct record
	while (fread(&m1, sizeof(m1),
				1, fm)) {
		if (strcmp(username2,
				m1.usernameto)
			== 0) {
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%d", m1.money1);
			// Adding and
			// finding total money
			summoney = summoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 12);
	printf("%d", summoney);

	getch();

	// Closing file after
	// reading it
	fclose(fm);
	display(username2);
}

// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}
void cheque(void)
{
	struct chq s;
	char b;
	FILE *fd;
	fd = fopen("chq.txt", "ab");
	printf("Enter your First Name:");
	scanf("%s",&s.fuser);
	printf("Enter your Last Name:");
	scanf("%s",&s.luser);
	printf("Enter Your Id:");
	scanf("%d",&s.id);
	printf("Enter your Pan number:");
	scanf("%s",&s.pan);
	printf("Enter your Aadhar number:");
	scanf("%s",&s.aad);
	printf("Your Details:-");
	printf("\nFirst name- %s\nLAst Name- %s\nID- %d\nPan Number- %s\nAadhar Number- %s\n",s.fuser,s.luser,s.id,s.pan,s.aad);
	printf("Enter Your Phone Number:");
	scanf("%d",&s.ph);
	printf("Press Enter to continue");
	getch( );
	fwrite(&s, sizeof(s),1, fd);
		fclose(fd);
	
	
	
	for (int i = 0; i < 70; i++) {
		for (int j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}
	printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	printf("\n\n\n \t\t\t\t\tYour Cheque book has been Applied\n\n\n\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    printf("\n\n\nAn message will be sent to your registered mobile number when the checkbook is ready to be shipped;)");
}
void del()
{
	char user2[50];
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;

	struct userpass u2;

	// Opening file to
	// write data of a user
	fp = fopen("username.txt", "ab");

	// Inputs
	system("cls");
	printf("Enter the details of the account you want to delete");
	printf("\n\nFIRST NAME..");
	scanf("%s", &u1.fname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u1.lname);

	printf("\n\nFATHER's NAME..");
	scanf("%s", &u1.fathname);

	printf("\n\nMOTHER's NAME..");
	scanf("%s", &u1.mothname);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u1.typeaccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nADHAR NUMBER");
	scanf("%s", u1.adharnum);

	printf("\n\nPHONE NUMBER");
	scanf("%s", u1.pnumber);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD..");

	// Taking password in the form of
	// stars
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}
	// Writing to the file
	fwrite(&u1, sizeof(u1),
		1, fp);

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountdeleted();
}
void accountdeleted(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT DELETED SUCCESSFULLY....");
	gotoxy(0, 20);
}