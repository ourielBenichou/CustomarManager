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
	FILE* fDebts = fopen("��debt_file2.txt", "r+t");
	if (fDebts == NULL) {
		printf("\nFile not found");
		exit(1);
	}
	
	head=readFile(fDebts,buffer,head);//������� ������ �� ����� ������ ���� ������ ������
	printFile(head); //����� �� ������
/*------------------------------------------------------�������---------------------------------------------*/
	//������� ������
	do
	{
		printMenu();
 		gets(buffer);
	//����� �������
		getCommand(buffer, fDebts, head);
	} while (strcmp(buffer, "quit"));
	/*------------------------------------------------------����� �������---------------------------------------------*/
	releaseLinkedList(head);//������ ������ �������
	fclose(fDebts);
	printf("\n                                        Good Bye!!!                      \n");

}


