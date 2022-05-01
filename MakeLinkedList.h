#pragma once
#include"ReadFile.h"
#include"CustomarValide.h"

customar* makeLinkedList(FILE* fDebt, customar* head, char buffer[]);
void releaseLinkedList(customar* head);
int searchByFirstName(char* value, customar* head);
char* fixRow(char* Buffer);

// מחולל רשימה מקושרת מהקובץ
customar* makeLinkedList(FILE* fDebt, customar* head, char buffer[])
{
	char* fixBuffer=(char*)malloc(sizeof(char)*200);
	while (!feof(fDebt)) {
		fgets(buffer, 200, fDebt);
		/*תיקון תוכנית : תיקון קובץ הקריאה*/
		if (buffer != NULL)
		 fixBuffer=fixRow(buffer);
		head = addNewCostomar(head, fixBuffer);
	}
	free(fixBuffer);
	return head;
}

int searchByFirstName(char* value, customar* head)
{
	int flag = 0;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (strcmp(head->firstName, value)==0) {
			printCustomar(*head);
			flag= 1;
		}
		head = head->next;
	}

	return flag;
}

int searchByLastName(char* value, customar* head)
{
	int flag = 0;
	customar* curr = head;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->lastName, value)) {
			printCustomar(*head);
			flag= 1;
		}
		head = head->next;
	}

	return flag;
}

int searchByID(char* value, customar* head)
{
	customar* curr = head;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->ID, value)) {
			printCustomar(*head);
			return 1;
		}
		head = head->next;
	}

	return 0;
}

int searchByPhone(char* value, customar* head)
{
	int flag = 0;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->phone, value)) {
			printCustomar(*head);
			flag= 1;
		}
		head = head->next;
	}

	return flag;
}

#pragma region Debt Search

int searchLessThan(int value, customar* head)
{
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (head->debt < value) {
			printCustomar(*head);
			return 1;
		}
		head = head->next;
	}
	return 0;
}

int searchEqual(int value, customar* head)
{
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (head->debt == value) {
			printCustomar(*head);
			return 1;
		}
		head = head->next;
	}
	return 0;
}
#pragma endregion

//שיחרור זיכרון
void releaseLinkedList(customar* head)
{
	customar* preve, * tmp;
	preve = tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(preve);
		preve = tmp;
	}
}

char* fixRow(char* Buffer)
{
	char*result= (char*)calloc(200,sizeof(char));
	char* token, * fileRowArr[6], * setRowArr[6];
	for (int i = 0; i < 6; i++)
		setRowArr[i] = (char*)malloc(sizeof(char) * 50);
	strcpy((setRowArr[0]) , "first name=");
	strcpy((setRowArr[1]), ",last name=");
	strcpy((setRowArr[2]), ",ID=");
	strcpy((setRowArr[3]), ",phone=");
	strcpy((setRowArr[4]), ",debt=");
	strcpy((setRowArr[5]), ",date=");

	fileRowArr[0] = strtok(Buffer, ",");
	strcat((setRowArr[0]),(fileRowArr[0]) );
	/* חלוקת החוצץ למערך סטרינגים והוספת ערך זהה  לSET*/
	for (int i = 1; i < 6; i++) {
		fileRowArr[i] = strtok(NULL, ",");
		strcat((setRowArr[i]), (fileRowArr[i]));
	}	
	for (int i = 0; i < 6; i++)
		strcat(result,( setRowArr[i]));
	
	for (int i = 0; i < 6; i++)
		free(setRowArr[i]);

	return result;
}