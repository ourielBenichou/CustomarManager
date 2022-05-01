#pragma once
#include"PrintFile.h"
#include"customarValide.h"
enum ComparOperator
{
	bigger= 6200,
	equal= 6100,
	smaller= 6000,
	biggerEqual= 6810,
	smallerEqual = 6611,
	different= 3910
};

void dateComparOperator(customar* head, char* operat, Date value);
void debtComparOperator(customar* head, char* operat, int value);

void dateComparOperator(customar* head, char* operat, Date value)
{
	int i = operat[0] * 100;
	i += operat[1] * 10;

	switch (i)
	{
	case bigger:  //operator: >
		while (head != NULL)
		{
			if (comparDate(head->date, value) > 0)
				printCustomar(*head);
			head = head->next;
		}

		break;
	case smaller: //operator: <
		while (head != NULL)
		{
			if (comparDate(head->date, value) < 0)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case equal: //operator: =
		while (head != NULL)
		{
			if (comparDate(head->date, value) == 0)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case biggerEqual:       //operator: >=
		while (head != NULL)
		{
			if (comparDate(head->date, value) >= 0 || comparDate(head->date, value) == 0)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case smallerEqual:   //operator: <=
		while (head != NULL)
		{
			if (comparDate(head->date, value) < 0 || comparDate(head->date, value) == 0)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case different:  //operator: !=
		while (head != NULL)
		{
			if (comparDate(head->date, value) < 0 || comparDate(head->date, value) > 0)
				printCustomar(*head);
			head = head->next;
		}
		break;
	default:
		printf("\nError Command!!!");
		break;

	}
}

void debtComparOperator(customar* head, char* operat, int debt)
{
	int i = operat[0] * 100;
	i += operat[1] * 10;

	switch (i)
	{
	case bigger:  //operator: >
		while (head != NULL)
		{
			if (head->debt > debt)
				printCustomar(*head);
			head = head->next;
		}

		break;
	case smaller: //operator: <
		while (head != NULL)
		{
			if (head->debt < debt)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case equal: //operatour: =
		while (head != NULL)
		{
			if (head->debt == debt)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case biggerEqual:       //operator: >=
		while (head != NULL)
		{
			if (head->debt >= debt)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case smallerEqual:   //operator: "<="
		while (head != NULL)
		{
			if (head->debt <= debt)
				printCustomar(*head);
			head = head->next;
		}
		break;
	case different:  //operator: !=
		while (head != NULL)
		{
			if (head->debt != debt)
				printCustomar(*head);
			head = head->next;
		}
		break;
	default:
		printf("\nError Command!!!");
		break;

	}

}


