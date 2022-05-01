#pragma once
#include"GetCommand.h"
#include"ComparOperator.h"

void selectQuery(char* selectArr[], customar* head);

void selectQuery(char* selectArr[], customar* head)
{
	int result,debt;
	char* token,operator;
	Date dateBuffer;

	if (!strcmp("first", selectArr[0])) {
		result = searchByFirstName(selectArr[2], head);
		if (result == 0) {
			printf("\n Custumer: %s NOT Find\n", selectArr[2]);
		}
	}
	else
		if (!strcmp("last", selectArr[0])){
			result = searchByLastName(selectArr[2], head);
			if (result == 0) {
				printf("\n Custumer: %s NOT Find\n", selectArr[2]);
			}
		}
			
		else {
			if (!strcmp("ID", selectArr[0])) {
				result = searchByID(selectArr[2], head);
				if (result == 0) {
					printf("\n Custumer ID: %s NOT Find\n", selectArr[2]);
				}
			}
			else
				if (!strcmp("phone", selectArr[0])) {
					result = searchByPhone(selectArr[2], head);
					if (result == 0) {
						printf("\n The Number Phone: %s NOT Find\n", selectArr[2]);
					}
				}
				else {
					if (!strcmp("debt", selectArr[0])) {
						debt = (int)atoi(selectArr[2]);
						debtComparOperator(head, selectArr[1],debt);
					}
					else
						if (!strcmp("date", selectArr[0])) {
							dateBuffer = stringToDate(selectArr[2]);
							dateComparOperator(head, selectArr[1],dateBuffer);
						}
				}
		}
					
}

