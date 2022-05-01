#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"CustomarValide.h"


typedef struct Date
{
	int day, month, year;
}Date;

Date stringToDate(char* buff);
int comparDate(Date a, Date b);


Date stringToDate(char* buff)
{
	Date sDate;
	int day, month, year;
	buff = strtok(buff, "=");
	buff = strtok(buff, "/");
	day = atoi(buff);
	if (day > 0 && day <= 31)
		sDate.day = day;
	else {
		sDate.day = NULL;
		printf("\nday not exist,");
	}
	buff = strtok(NULL, "/");

	month = atoi(buff);
	if (month > 0 && month <= 12)
		sDate.month = month;
	else
	{
		sDate.month = NULL;
		printf(" \nmonth not exist!!!");
	}
	buff = strtok(NULL, "/");

	year = atoi(buff);
	if (year > 1900)
		sDate.year = year;
	else
	{
		sDate.year = NULL;
		printf("Error on the year date");
	}

	return sDate;
}

int comparDate(Date a, Date b)
{
	if (a.year != b.year)
		return a.year - b.year;
	if (a.month != b.month)
		return a.month - b.month;
	if (a.day != b.day)
		return a.day - b.day;
	return 0;
}


