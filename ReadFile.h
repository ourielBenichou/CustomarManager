#pragma once

// DEBUG

#include<stdio.h>
#include<stdlib.h>
#include"PrintFile.h"
#include"MakeLinkedList.h"
#define MAX_LINE 200

customar* readFile(FILE* fDebt, char buffer[MAX_LINE], customar* head);

customar* readFile(FILE* fDebt, char buffer[MAX_LINE], customar* head)
{
	// ����� �� ������ ������� ���� ���� head
		//����� �������

	head = makeLinkedList(fDebt, head, buffer);
	if (head == NULL)
		printf("\nThe File is Empty!!!");

	return head;
}



