#include <stdio.h>

int is_leap_year(int year);
void calculate_month_of_day(char *monthes, int of_day, int *month, int *day);

void day_of_month(int year, int of_day, int *month, int *day);
int day_of_year(int year, int month, int day);

int main(void) {

	int year, month, day, of_day;

	year = 2022, month = 12, day = 11;

	of_day = day_of_year(year, month, day);
	printf("%d month %d day is %d year %d day\n", month, day, year, of_day);


	/* //3. finish day_of_month */
	/* int year, of_day, month, day; */

	/* year = 2020, of_day = 60; */

	/* day_of_month(year, of_day, &month, &day); */

	/* printf("%d year %d day is %d month %d day.\n", year, of_day, month, day); */


	// 2. calculate month_of_day
	/* char monthes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, */
	/* 		       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; */

	/* int month, day, year, of_day; */

	/* year = 2020; */
	/* of_day = 59; */
	/* calculate_month_of_day(monthes[0], of_day, &month, &day); */
	
	/* printf("%d year %d day is %d month %d day.\n", year, of_day, month, day); */


	// 1. test 'is_leap_year'.
	/* int year = 2020; */
	/* printf("%d is ", year); */

	/* if(!is_leap_year(year)) { */
	/* 	printf("not "); */
	/* } */

	/* printf("a leap year!\n"); */
}

int day_of_year(int year, int month, int day)
{
	char monthes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int leap, i, day_of_year;

	day_of_year = 0;
	leap = is_leap_year(year);

	for(i = 1; i < month; i++) {
		day_of_year += monthes[leap][i];
	}
	return day_of_year += day;
}

void day_of_month(int year, int of_day, int *month, int *day)
{
	char monthes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int leap;
	leap = is_leap_year(year);

	calculate_month_of_day(monthes[leap], of_day, month, day);
}
	

void calculate_month_of_day(char *monthes, int of_day, int *month, int *day)
{
	int i;

	for(i = 1; of_day > monthes[i]; i++)
		of_day -= monthes[i];
	*month = i;
	*day = of_day;

	/* int i; */
	/* for(i = 1; (i <= 13) && (of_day > 0); i++) { */
	/* 	of_day -= monthes[i]; */
	/* } */
	/* *month = i - 1; */
	/* *day = of_day + monthes[i - 1]; */
}

int is_leap_year(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	return 0;
}
