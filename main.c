#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma once
#include"customarValide.h"
#include"Date.h"
#include"ReadFile.h"
#include"GetCommand.h"



void main()
{
	char buffer[MAX_LINE];
	customar* head = NULL;
	FILE* fDebts = fopen("‏‏debt_file2.txt", "r+t");
	if (fDebts == NULL) {
		printf("\nFile not found");
		exit(1);
	}
	
	head=readFile(fDebts,buffer,head);//פונקציה שקוראת את הקובץ והופכת אותו לרשימה מקושרת
	printFile(head); //מדפיס את הרשימה
/*------------------------------------------------------שאילתות---------------------------------------------*/
	//שאילתות למשתמש
	do
	{
		printMenu();
 		gets(buffer);
	//ניתוח השאילתה
		getCommand(buffer, fDebts, head);
	} while (strcmp(buffer, "quit"));
	/*------------------------------------------------------סגירת התוכנית---------------------------------------------*/
	releaseLinkedList(head);//שיחרור הרשימה המקושרת
	fclose(fDebts);
	printf("\n                                        Good Bye!!!                      \n");

}


