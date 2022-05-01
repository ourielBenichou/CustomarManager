#pragma once
#include<stdio.h>
#include"Date.h"

typedef struct customar
{
	char firstName[20];
	char lastName[20];
	char ID[10];
	int debt;
	char phone[11];
	Date date;
	struct customar* next;
}customar;


customar* addNewCostomar(customar* head, char *buffer);
int Validation(customar** tmp, char* buffer);

customar* addNewCostomar(customar* head, char* buffer)
{
	int result;
	customar* tmp = (char*)calloc(1, sizeof(customar)), * prev = head;
	result = Validation(&tmp, buffer);

	if (!result)  //����� ���� ����� 
		//������ �� �"� ����
		if (checkNewCostomar(head, *tmp)) {
			//����� ����� ���� ���� ����� ������
			if (!prev)//��� ����� ��� �����
				head = tmp;
			else
			{
				while (prev->next)
					prev = prev->next;
				prev->next = tmp;
			}
		}

	return head;
}



//����� ��� �"� ��� ����� ���� ��� �����	
int checkNewCostomar(customar* head, customar tmpCust)
{
	customar* curr = head;
	while (curr)
	{
		if (!strcmp(curr->ID, tmpCust.ID)) //����� ������ ��� ���� ���� �����
		{
			if (strcmp(curr->firstName, tmpCust.firstName) || strcmp(curr->lastName, tmpCust.lastName)) {
				printf("\n+=======================================================+");
				printf("\n|The Name of customar ID: %s is:%-8s %-8s|", curr->ID, curr->firstName, curr->lastName);
				printf("\n+=======================================================+");
			}
			curr->debt += tmpCust.debt;//����� ���� ���� ������� ����� ����� �����
			if (comparDate(curr->date, tmpCust.date) > 0)// ������ ������ ����� ����� ����� ����� ���� �����
				curr->date = tmpCust.date;
			return 0;
		}
		curr = curr->next;
	}
	return 1;
}


int Validation(customar** tmp, char* buffer)
{
	char* token = (char*)malloc(sizeof(char));
	char errorMassage[200] = "\nTyping error command on:";//��� ������ ������
	Date tmpDate;

	if ( token == NULL)  //����� ����� ������
	{
		printf("\nMemory not allocated!!!");
		return 1;
	}
	int errorFlag = 0;
	token = strtok(buffer, "=");//���� ����� ������
	//����� ��� ������ first name����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "first name")) {
		token = strtok(NULL, ",");
		if (token != NULL)
			strcpy((*tmp)->firstName, token);
		else
			;

	}
	else
	{
		strcat(errorMassage, " first name=***,");//����� ���� ����� ���� �����
		errorFlag = 1;
	}


	token = strtok(NULL, "=");//���� �� ��������� ���

	// ����� ��� ������lest name  ����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "last name")) {
		token = strtok(NULL, ",");
		strcpy((*tmp)->lastName, token);
	}
	else
	{
		strcat(errorMassage, "last name=***,");
		errorFlag = 1;
	}

	token = strtok(NULL, "=");//���� �� ��������� ���

	//����� ��� ������ ID ����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "ID")) {
		token = strtok(NULL, ",");
		//����� ��� ID ���� �9 �����
		if (strlen(token) == 9)
			strcpy((*tmp)->ID, token);
		else
		{
			printf("\nID must be 9 digits");
			errorFlag = 1;
		}
	}
	else
	{
		strcat(errorMassage, "ID=***,");
		errorFlag = 1;
	}

	token = strtok(NULL, "=");//���� �� ��������� ���

	//����� ��� ������ ����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "phone")) {
		token = strtok(NULL, ",");
		if (strlen(token) == 10 && token[0] == '0')
			strcpy((*tmp)->phone, token);//����� ��� ���� ������ ����
		else
		{
			strcat(errorMassage, " phone number not currect,");
			errorFlag = 1;
		}
	}
	else
	{
		strcat(errorMassage, " phone=***,");
		errorFlag = 1;
	}

	token = strtok(NULL, "=");//���� �� ��������� ���

	//����� ��� ������ DEBT ����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "debt")) {
		token = strtok(NULL, ",");
		(*tmp)->debt = (int)atoi(token);
	}
	else
	{
		strcat(errorMassage, " debt=***,");
		errorFlag = 1;
	}

	token = strtok(NULL, "=");//���� �� ��������� ���

	//����� ��� ������ DATE ����� ���� ���� ���� 
	if (token != NULL && !strcmp(token, "date")) {
		token = strtok(NULL, ",");
		tmpDate = stringToDate(token);//������� ������ ��� ������ ����
		if (tmpDate.day && tmpDate.month && tmpDate.year)
			(*tmp)->date = tmpDate;
		else
			errorFlag = 1;
	}
	else
	{
		strcat(errorMassage, " date=***,");
		errorFlag = 1;
	}

	return errorFlag;
}


