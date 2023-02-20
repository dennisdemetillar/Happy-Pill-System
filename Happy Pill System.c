#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void modifystory();
void modifyphnumber();
void login();
void user();
void admin();
void depfinder();
void readstory();
void viewphonenum();
void editquest();
void adminpass();
void deletestory();
void deletephonenum();

struct quest
	{
		char questnum[2];
		char question[1000];
	};
	struct story
	{
		char code[3];
		char title[30];
		char storyy[2500];
	};
	struct phone
	{
		char name[20];
		char number[20];
	};
	struct quest qest;
	struct story stor;
	struct phone pone;
	
	
int main()
{
	
	int r,q,c;
	gotoxy(45,13);
	printf("HAPPY PILL SYSTEM :)");
    gotoxy(50,14);
    printf("loading...");
    gotoxy(45,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); 
        printf("%c",177);
    }
	
	system("cls");
	login();
	
	return 0;
}/*intmain*/
void login()
{
	char choice;
	while(1)
	{
	gotoxy(39,4);
	printf("HAPPY PILL SYSTEM :)");
	gotoxy(30,5);
	printf("====================================");
	gotoxy(42,6);
	printf("--- LOGIN ---");
	gotoxy(35,7);
	printf("1. User");
	gotoxy(35,8);
	printf("2. Admin");
	gotoxy(35,9);
	printf("3. Close Program");
	gotoxy(35,10);
	printf("Enter your choice: ");
	gotoxy(55,10);
	fflush(stdin);
	choice=getche();
	switch(choice)
	{
		case '1':
		system("cls");
		user();
		break;
		
		case '2':
		system("cls");
		adminpass();
		break;
		
		case '3':
		system("cls");
		gotoxy(35,8);
		printf("Thank you for using this system!");
		gotoxy(35,9);
		exit(0);
		break;
		
		default:
		gotoxy(35,12);
		printf("Enter Only 1-3!");
		getch();
		break;
	}
	system("cls");
	}
}
void adminpass()
{
	char choice, choice1;
	char username[6];
	char password[5];
		system("cls");
		usepass:
		gotoxy(35,7);
		printf("USERNAME: ");
		gotoxy(35,8);
		fflush(stdin);
		gets(username);
		gotoxy(35,9);
		printf("PASSWORD: ");
		gotoxy(35,10);
		fflush(stdin);
		gets(password);
		
		if(strcmp(username,"admin")==0)
		{
			if(strcmp(password,"pass")==0)
			{
				system("cls");
				admin();
			}
			else
			{
				gotoxy(35,12);
				printf("Login Unsucessful!");
				gotoxy(35,13);
				printf("Do you want to try again? (Y/N)");
				fflush(stdin);
				choice=toupper(getche());
				if(choice=='Y')
				{
					system("cls");
					goto usepass;
				}
				else
				{
					system("cls");
					login();
				}
			}
		}
		else
		{
			gotoxy(35,12);
			printf("Login Unsucessful!");
			gotoxy(35,13);
			printf("Do you want to try again? (Y/N)");
			fflush(stdin);
			choice=toupper(getche());
			if(choice=='Y')
			{
				system("cls");
				goto usepass;
			}
			else
			{
				system("cls");
				login();
			}
		}
			  
}
void admin()
{
		char choice1;
		while(1)
		{
			admin1:
			system("cls");
			gotoxy(42,5);
			printf("--- ADMIN ---");
			gotoxy(35,7);
			printf("1. EDIT QUESTIONS");
			gotoxy(35,8);
			printf("2. MODIFY INSPIRATIONAL STORIES");
			gotoxy(35,9);
			printf("3. MODIFY PHONE NUMBERS");
			gotoxy(35,10);
			printf("4. LOG OUT");
			gotoxy(35,11);
			printf("SELECT YOUR OPTION: ");
			fflush(stdin);
			choice1 = getche();
			switch(choice1)
			{
				case '1':
				editquest();
				break;
				
				case '2':
				modifystory();
				break;
				
				case '3':
				modifyphnumber();
				break;
				
				case '4':
				system("cls");
				login();
				break;
				
				default:
				printf("Please Select Only 1-3!");
				getch();
				break;
			}
			system("cls");
		}
			  
}
void modifystory()
{
	FILE *fp, *ft;
	
	char scode[3];
	long int recsize;
	char another, choice;
	
	fp=fopen("STORY.DAT","rb+");
	if(fp == NULL)
	{
		fp=fopen("STORY.DAT","wb+");
		if(fp==NULL)
		{
			printf("Cannot open file!");
			exit(1);
		}
	}
	
	recsize = sizeof(stor);
	
	while(1)
	{
		system("cls");
		gotoxy(35,7);
		printf("1. Add New Story");
		gotoxy(35,8);
		printf("2. Edit Story");
		gotoxy(35,9);
		printf("3. Delete Story");
		gotoxy(35,10);
		printf("4. Return Admin Menu");
		gotoxy(35,11);
		printf("Your Choice: ");
		fflush(stdin);
		choice = getche();
		switch(choice)
		{
			case '1':
			system("cls");
			fseek(fp,0,SEEK_END);
			
			another='y';
			
			while(another=='y')
			{
				printf("Enter Story Code: ");
				fflush(stdin);
				gets(stor.code);
				printf("Enter Story Title: ");
				fflush(stdin);
				gets(stor.title);
				printf("Enter the Story: ");
				fflush(stdin);
				gets(stor.storyy);
				
				fwrite(&stor,recsize,1,fp);
				printf("Add another Story?: (y/n)");
				fflush(stdin);
				another=getche();
			}break;
			
			case '2':
			system("cls");
			another='y';
			while(another=='y')
			{
				printf("Enter the Story Code: ");
				fflush(stdin);
				gets(scode);
				rewind(fp);
				while(fread(&stor,recsize,1,fp)==1)
				{
					if(strcmp(stor.code,scode)==0)
					{
						printf("Enter New Story Code: ");
						fflush(stdin);
						gets(stor.code);
						printf("Enter New Story Title: ");
						fflush(stdin);
						gets(stor.title);
						printf("Enter the New Story: ");
						fflush(stdin);
						gets(stor.storyy);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&stor,recsize,1,fp);
						break;
					}
				}
				printf("Edit another Story?: (y/n)");
				fflush(stdin);
				another=getche();
			}break;
			
			case '3':
			deletestory();
			break;
			
			case '4':
			system("cls");
			admin();
			break;
			
		}
	}
}
void modifyphnumber()
{
	FILE *fp, *ft;
	
	char pname[20];
	long int recsize;
	char another, choice;
	
	fp=fopen("NUMBER.DAT","rb+");
	if(fp == NULL)
	{
		fp=fopen("NUMBER.DAT","wb+");
		if(fp==NULL)
		{
			printf("Cannot open file!");
			exit(1);
		}
	}
	
	recsize = sizeof(pone);
	
	while(1)
	{
		system("cls");
		gotoxy(35,7);
		printf("1. Add New Number");
		gotoxy(35,8);
		printf("2. Edit Number");
		gotoxy(35,9);
		printf("3. Delete Number");
		gotoxy(35,10);
		printf("4. Return Admin Menu");
		gotoxy(35,11);
		printf("Your Choice: ");
		fflush(stdin);
		choice = getche();
		switch(choice)
		{
			case '1':
			system("cls");
			fseek(fp,0,SEEK_END);
			
			another='y';
			
			while(another=='y')
			{
				printf("Enter Name: ");
				fflush(stdin);
				gets(pone.name);
				printf("Enter Number: ");
				fflush(stdin);
				gets(pone.number);
				fwrite(&pone,recsize,1,fp);
				printf("Add another Number?: (y/n)");
				fflush(stdin);
				another=getche();
				system("cls");
			}break;
			
			case '2':
			system("cls");
			another='y';
			while(another=='y')
			{
				system("cls");
				printf("Enter the Name: ");
				fflush(stdin);
				gets(pname);
				rewind(fp);
				while(fread(&pone,recsize,1,fp)==1)
				{
					if(strcmp(pone.name,pname)==0)
					{
						printf("Enter New Name: ");
						fflush(stdin);
						gets(pone.name);
						printf("Enter New Number: ");
						fflush(stdin);
						gets(pone.number);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&pone,recsize,1,fp);
						break;
					}
				}
				printf("Edit another Story?: (y/n)");
				fflush(stdin);
				another=getche();
			}break;
			
			case '3':
			deletephonenum();
			break;
			
			case '4':
			system("cls");
			admin();
			break;
			
		}
	}
	   
	
}
void editquest()
{
	FILE *fp, *ft;
	char qnum[2];
	long int recsize;
	char another, choice;
	
	
	fp=fopen("QUESTION.DAT","rb+");
	if(fp == NULL)
	{
		fp=fopen("QUESTION.DAT","wb+");
		if(fp==NULL)
		{
			printf("Cannot open file!");
			exit(1);
		}
	}
	recsize = sizeof(qest);
	system("cls");
	gotoxy(30,7);
	printf("WARNING! Editing the question may affect the Depression Level Finder");
	gotoxy(35,8);
	printf("Do you really want to edit question?");
	gotoxy(35,9);
	printf("1. Yes");
	gotoxy(50,9);
	printf("2. No");
	fflush(stdin);
	choice=getche();
	switch(choice)
	{
		case '1':
		system("cls");
		goto eq;
		break;
		
		case '2':
		system("cls");
		admin();
		break;
		
		default:
		system("cls");
		printf("Enter Only 1-2!");
		getch();
		break;
	}
			
			eq:
			system("cls");
			another='y';
			while(another=='y')
			{
				system("cls");
				gotoxy(35,9);
				printf("Enter Question Number: ");
				fflush(stdin);
				gets(qnum);
				rewind(fp);
				while(fread(&qest,recsize,1,fp)==1)
				{
					if(strcmp(qest.questnum,qnum)==0)
					{
						gotoxy(35,11);
						printf("Enter New Question: ");
						fflush(stdin);
						gets(qest.question);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&qest,recsize,1,fp);
						break;
					}
				}
				gotoxy(30,16);
				printf("Edit another Question?: (y/n)");
				fflush(stdin);
				another=getche();
			} 
			system("cls");
		admin();
}
void deletestory()
{
	FILE *fp, *ft;
	char another;
	char scode[3];
	long int recsize;
	
	fp=fopen("STORY.DAT","rb+");
	if(fp == NULL)
	{
		fp=fopen("STORY.DAT","wb+");
		if(fp==NULL)
		{
			printf("Cannot open file!");
			exit(1);
		}
	}
	
			recsize=sizeof(stor);
			system("cls");
            another = 'y';
            while(another == 'y')
            {
				system("cls");
                printf("\nEnter Story Code: ");
                scanf("%s",scode);
                ft = fopen("Temp.dat","wb");  
                rewind(fp);
                while(fread(&stor,recsize,1,fp) == 1)  
                {
                    if(strcmp(stor.code,scode) != 0)  
                    {
                        fwrite(&stor,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("STORY.DAT"); 
                rename("Temp.dat","STORY.DAT");
                fp = fopen("STORY.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
		system("cls");
		admin()	;     
}
void deletephonenum()
{
	FILE *fp, *ft;
	char another;
	char pname[20];
	long int recsize;
	
	fp=fopen("NUMBER.DAT","rb+");
	if(fp == NULL)
	{
		fp=fopen("NUMBER.DAT","wb+");
		if(fp==NULL)
		{
			printf("Cannot open file!");
			exit(1);
		}
	}
	
			recsize=sizeof(pone);
			system("cls");
            another = 'y';
            while(another == 'y')
            {
				system("cls");
                printf("\nEnter Name: ");
                scanf("%s",pname);
                ft = fopen("Temp.dat","wb");  
                rewind(fp);
                while(fread(&pone,recsize,1,fp) == 1)  
                {
                    if(strcmp(pone.name,pname) != 0)  
                    {
                        fwrite(&pone,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("NUMBER.DAT"); 
                rename("Temp.dat","NUMBER.DAT");
                fp = fopen("NUMBER.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
		system("cls");
		admin()	;     	   
}
void user()
{
	char choice;
	while(1)
		{
			system("cls");
			gotoxy(42,5);
			printf("--- USER ---");
			gotoxy(35,7);
			printf("1. DEPRESSION LEVEL FINDER");
			gotoxy(35,8);
			printf("2. INSPIRATIONAL STORIES");
			gotoxy(35,9);
			printf("3. PHONE NUMBERS TO CALL");
			gotoxy(35,10);
			printf("4. RETURN TO LOGIN");
			gotoxy(35,11);
			printf("SELECT YOUR OPTION: ");
			fflush(stdin);
			choice = getche();
			switch(choice)
			{
				case '1':
				depfinder();
				break;
				
				case '2':
				readstory();
				break;
				
				case '3':
				viewphonenum();
				break;
				
				case '4':
				system("cls");
				login();
				break;
				
				default:
				printf("Please Select Only 1-4!");
				system("cls");
				getch();
				break;
			}
		}
}
void depfinder()
{
	FILE *fp, *ft;
	int total=0;
	char choice1,another1,choice,ans1;
				system("cls");
				disclaimer:
				gotoxy(42,5);
				printf("--- DISCLAIMER ---");
				gotoxy(35,7);
				printf("By choosing CONTINUE below you acknowledge that this is not a diagnostic instrument and is only to be used by you if you are 18 years or older.");
				gotoxy(35,9);
				printf("You agree that this system is for information purposes only and is not intended to replace a consultation with your doctor or a mental health professional.");
				gotoxy(35,10);
				printf("Happy Pill System's developers disclaim any liability, loss, or risk incurred as a consequence, directly or indirectly from the use and application of this test.");
				gotoxy(35,12);
				printf("1. CONTINUE");
				gotoxy(35,13);
				printf("2. GO BACK");
				gotoxy(35,14);
				printf("Enter your choice: ");
				fflush(stdin);
				choice1=getche();
				{
					if(choice1=='2')
					{
						system("cls");
						user();
					}
					else if(choice1=='1')
					{	
						fp = fopen("QUESTION.DAT","rb");
						if(fp == NULL)
						{
							fp = fopen("QUESTION.DAT","wb+");
							if (fp==NULL)
							{
								puts("Cannot open file");
								exit(0);
							}
						}
						another1='Y';
						while(another1=='Y')
						{
							system("cls");
							rewind(fp);
							while(fread(&qest,sizeof(qest),1,fp)==1)
							{
								system("cls");
								gotoxy(33,8);
								printf("%s",qest.questnum);
								gotoxy(35,8);
								printf("%s",qest.question);
								gotoxy(34,16);
								printf("1. Not at all");
								gotoxy(34,17);
								printf("2. Several days");
								gotoxy(34,18);
								printf("3. More than half the days");
								gotoxy(34,19);
								printf("4. Nearly every day");
								gotoxy(34,20);
								printf("NOTICE!!! If you answer other than numbers 1-4 the answer will not be counted.");
								gotoxy(34,21);
								scanf("%s",&ans1);
								if(ans1=='1')
								{
									total=total+0;	  
								}
								else if(ans1=='2')
								{
									total=total+1;
								}
								else if(ans1=='3')
								{
									total=total+2;
								}
								else if(ans1=='4')
								{
									total=total+3;
								}
								else
								{
									total=total+0;
								}
							}
							system("cls");
							if(total<=4)
							{
								gotoxy(35,7);
								printf("THE RESULT IS");
								gotoxy(35,9);
								printf("Minimal Depression");
								gotoxy(35,10);
								printf("This quiz is not meant to replace a professional diagnosis.");
								gotoxy(35,11);
								printf("You should follow up with a doctor or a mental health worker for an assessment.");
								system("pause");
							}
							else if(total>=5 && total<=9)
							{
								gotoxy(35,7);
								printf("THE RESULT IS");
								gotoxy(35,9);
								printf("Mild Depression");
								gotoxy(35,10);
								printf("This quiz is not meant to replace a professional diagnosis.");
								gotoxy(35,11);
								printf("You should follow up with a doctor or a mental health worker for an assessment.");
								system("pause");
							}
							else if(total>=10 && total<=14)
							{
								gotoxy(35,7);
								printf("THE RESULT IS");
								gotoxy(35,9);
								printf("Moderate Depression");
								gotoxy(35,10);
								printf("This quiz is not meant to replace a professional diagnosis.");
								gotoxy(35,11);
								printf("You should follow up with a doctor or a mental health worker for an assessment.");
								system("pause");
							}
							else if(total>=15 && total<=19)
							{
								gotoxy(35,7);
								printf("THE RESULT IS");
								gotoxy(35,9);
								printf("Moderately Severe Depression");
								gotoxy(35,10);
								printf("This quiz is not meant to replace a professional diagnosis.");
								gotoxy(35,11);
								printf("You should follow up with a doctor or a mental health worker for an assessment.");
								system("pause");
							}
							else
							{
								gotoxy(35,7);
								printf("THE RESULT IS");
								gotoxy(35,9);
								printf("Severe Depression");
								gotoxy(35,10);
								printf("This quiz is not meant to replace a professional diagnosis.");
								gotoxy(35,11);
								printf("You should follow up with a doctor or a mental health worker for an assessment.");
								gotoxy(35,12);
								system("pause");
							}
							system("cls");
							gotoxy(35,8);
							printf("Do you want to read what may cause depression and some helpful tips to overcome it? ");
							gotoxy(35,9);
							printf("1. Yes");
							gotoxy(35,10);
							printf("2. No");
							gotoxy(35,11);
							fflush(stdin);
							choice1=toupper(getche());
							switch(choice1)
							{
								char ch;
								case '1':
								while(another1=='Y')
								{
									system("cls");
									tips:
									printf("1. Mild Depression");
									printf("2. Moderate Depression");
									printf("3. Severe Depression");
									printf("4. Return to User Menu");
									choice=toupper(getche());
									if(choice=='1')
									{
										fp=fopen("milddepression.txt","r");
										if(fp == NULL)
										{
											printf("Cannot open file\n");
											system("pause");
										}
										ch=fgetc(fp);
										while(ch!=EOF)
										{
											printf("%c",ch);
											ch=fgetc(fp);
										}
										fclose(fp);
										printf("\n\n");
										system("pause");
										
									}	
									else if(choice=='2')
									{
										fp=fopen("moderatedepression.txt","r");
										if(fp == NULL)
										{
											printf("Cannot open file\n");
											system("pause");
										}
										ch=fgetc(fp);
										while(ch!=EOF)
										{
											printf("%c",ch);
											ch=fgetc(fp);
										}
										fclose(fp);
										printf("\n\n");
										system("pause");
									}
									else if(choice=='3')
									{
										fp=fopen("severedepression.txt","r");
										if(fp == NULL)
										{
											printf("Cannot open file\n");
											system("pause");
										}
										ch=fgetc(fp);
										while(ch!=EOF)
										{
											printf("%c",ch);
											ch=fgetc(fp);
										}
										fclose(fp);
										printf("\n\n");
										system("pause");
									}
									else if(choice=='4')
									{
										system("cls");
										user();
									}
									else
									{
										printf("Please choose Only 1-4");
										system("pause");
										goto tips;
										system("cls");
									}
								}break;
								case '2':
								system("cls");
								break;
								default:
								gotoxy(35,12);
								printf("Please Enter 1 or 2 Only");
								gotoxy(35,13);
								system("pause");
								system("cls");
								goto tips;
								break;
							}
				
						gotoxy(35,8);
						printf("Do you want to take the test again? (Y/N): ");
						fflush(stdin);
						gotoxy(35,9);
						another1=toupper(getche());
					}
					}
					else
					{
						gotoxy(35,16);
						printf("Please Enter 1 or 2 Only!");
						system("pause");
						system("cls");
						goto disclaimer;
					}
				}
				user();
}
void readstory()
{

	FILE *fp, *ft;
	char another1, scode[3];
	int j=7;
	fp = fopen("STORY.DAT","rb");
						if(fp == NULL)
						{
							fp = fopen("STORY.DAT","wb+");
							if (fp==NULL)
							{
								puts("Cannot open file");
								exit(0);
							}
						}
						
						another1='Y';
						while(another1=='Y')
						{
							system("cls");
							rewind(fp);
							gotoxy(20,4);
							printf("Code");
							gotoxy(35,4);
							printf("Title");
							while(fread(&stor,sizeof(stor),1,fp)==1)
							{
								gotoxy(20,j);
								printf("%s", stor.code);
								gotoxy(35,j);
								printf("%s",stor.title);
								j++;
							}
							printf("\n");
							system("pause");
							rewind(fp);
							intitle:
							printf("\n");
							printf("Story title of you want to read: ");
							fflush(stdin);
							gets(scode);
							while(fread(&stor,sizeof(stor),1,fp)==1)
							{
								if(stricmp(stor.code,scode)==0)
								{
									system("cls");
									gotoxy(20,5);
									printf("%s",stor.code);
									gotoxy(40,6);
									printf("%s",stor.title);
									gotoxy(30,8);
									printf("%s",stor.storyy);
									gotoxy(40,25);
									system("pause");
									break;
								}
							}
								if(stricmp(stor.code,scode)!=0)
							{
								system("cls");
								gotoxy(35,6);
								printf("ERROR! Wrong Code!");
								gotoxy(35,7);
								system("pause");
								break;
							}
							system("cls");
							gotoxy(35,8);
							printf("Do you want to read another Story? (Y/N) ");
							fflush(stdin);
							gotoxy(35,9);
							another1 = toupper(getche());
					}
					system("cls");
					user();
}
void viewphonenum()
{
					
			FILE *fp, *ft;
			int j;
			char ch;		
						fp = fopen("NUMBER.DAT","rb");
						if(fp == NULL)
						{
							fp = fopen("NUMBER.DAT","wb+");
							if (fp==NULL)
							{
								puts("Cannot open file");
								exit(0);
							}
						}
						
						j=6;
							system("cls");
							rewind(fp);
							gotoxy(20,4);
							printf("Name");
							gotoxy(45,4);
							printf("Phone Number");
							while(fread(&pone,sizeof(pone),1,fp)==1)
							{
								gotoxy(20,j);
								printf("%s", pone.name);
								gotoxy(45,j);
								printf("%s",pone.number);
								j++;
							}
							printf("\n\n");
							system("pause");
							fclose(fp);
							
							fp=fopen("Globalhotlines.txt","r");
										if(fp == NULL)
										{
											printf("Cannot open file\n");
											system("pause");
										}
										ch=fgetc(fp);
										while(ch!=EOF)
										{
											printf("%c",ch);
											ch=fgetc(fp);
										}
										fclose(fp);
										printf("\n");
										system("pause");
						
						
					system("cls");
					user();
}

