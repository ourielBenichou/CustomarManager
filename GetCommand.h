#pragma once
#include"CustomarValide.h"
#include"SelectQuery.h"

void getCommand(char buffer[], FILE* fDebts,customar* head);

void getCommand(char buffer[], FILE* fDebts, customar* head)
{
	char* token = (char*)malloc(sizeof(char)), *tmpBuffer=buffer,*selectArr[3];
	token = strtok(buffer, " "); 

/*-----------------------------------����� ������� ������ ������ ����� ����----------------------------*/
	if (!strcmp("set", token))
	{
		customar* newCust = (customar*)malloc(sizeof(customar));
		if (!Validation(&newCust, tmpBuffer+=4)) 		//����� ����� �� ����� ���� ����� �������� ������
			printCustToFile(fDebts, newCust);
		else
			printf("\n Error on Set new date!!!");
	}
/*-----------------------------------------������� ������---------------------------------------------------*/
	else
		if (!strcmp("print", buffer))
			printFile(head);
		else
		{
			if (!strcmp("select", buffer)) {
				token = strtok(NULL, " ");//����� ����� SELECT ��BUFFER
				selectArr[0] = token;
				if (strcmp(selectArr[0], "first") && strcmp(selectArr[0], "last")) {
					token = strtok(NULL, " ");
					selectArr[1] = token;
					token = strtok(NULL, " ");
					selectArr[2] = token;
				}
				else   //����� �������� �� ������ ����� � NAME SELECT
				{
					token = strtok(NULL, " ");
					token = strtok(NULL, "=");
					token += 1;
					selectArr[2] = token;
				}
				selectQuery(selectArr, head);//����� ������
			}
		}
}