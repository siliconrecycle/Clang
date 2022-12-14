#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	/* for(i = 1; i < month; i++) */
	/* 	day += daytab[leap][i]; */

	char *p = daytab[leap];
	for(i = 1; i <= month; i++)
		day += *p++;

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	/* for(i = 1; yearday > daytab[leap][i]; i++) */
	/* 	yearday -= daytab[leap][i]; */

	char *p = daytab[leap];
	i = 0;
	while(yearday > *p) {
		i++;
		yearday -= *p++;
	}
	*pmonth = i;
	*pday = yearday;
}

int main(void) {

	int year, month, day, of_day;

	year = 2022, month = 12, day = 14;

	of_day = day_of_year(year, month, day);
	printf("%d month %d day is %d year %d day\n", month, day, year, of_day);


	/* //3. finish day_of_month */
	/* int year, of_day, month, day; */

	/* year = 2022, of_day = 347; */

	/* month_day(year, of_day, &month, &day); */

	/* printf("%d year %d day is %d month %d day.\n", year, of_day, month, day); */

}
