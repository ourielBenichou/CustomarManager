#pragma once
#include<stdio.h>
#include"MarginSort.h"

void printFile(customar* head);
void printCustomar(customar result);
void printCustToFile(FILE* fDebts, customar* newCust);
void printMenu();



void printFile(customar* head)
{
	MergeSort(&head);//מיון המערך לפני הדפסתו
	while (head != NULL)
	{
		printCustomar(*head);
		head = head->next;
	}
}

void printMenu()
{
	printf("\nExemple to set new record: set first name=***,last name=***,ID=***(9 digits),phone=***(10 digits),date=dd/mm/yyyy,debt=***(+-)\n");
	printf("\nsearch by First Name=***/Last Name=***/ID:*********/Debt (><=)/Date(><=) ");
	printf("\nselect ......");
	printf("\nTo Print writh: \"print\" ");
	printf("\nTo Quit writh: \"quit\" ");
	printf("\nEnter a choice/record:");
}

void printCustomar(customar result)
{
	printf("\n+=======================================================+");
	printf("\n| First Name:%-8s         Last Name:%-16s|", result.firstName, result.lastName);
	printf("\n+-------------------------------------------------------+");
	printf("\n| ID:%10s               Phone Number:%s   |", result.ID, result.phone);
	printf("\n| Debt: $%-10d           Date Of Market:%-0.2d/%-0.2d/%-05d|", result.debt, result.date.day, result.date.month, result.date.year);
	printf("\n+=======================================================+\n\n");

}

void printCustToFile(FILE* fDebts, customar* newCust)
{
	fseek(fDebts, 0, SEEK_END);
	fprintf(fDebts,"\n%s,%s,%s,%s,%d,%d/%d/%d", newCust->firstName, newCust->lastName, newCust->ID, newCust->phone, newCust->debt, newCust->date);
	printf("\n set new date success !!!");
}


