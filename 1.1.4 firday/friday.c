/*
ID:violin01
LANG:C
TASK:friday
*/

#include <stdio.h>

//const enum Week { Sun, Mon, Tue, Wed, Thr, Fri, Sat };
const int Days[12] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 }; // Days[0] = Dec, Days[1] = Jan
int satisfaction[7];  //satisfaction[0] = Sun, satisfaction[1] = Mon

void initArray(int a[], int len){
	int i=0;
	for(i=0; i<len; i++){
		a[i] = 0;
	}
}

int isLeapYear(int year){
	if((year%4==0 && year%100!=0) || year%400==0){
		return 1;
	}else{
		return 0;
	}
}

int nextMonth(int month){
	month = (month+1)%12;
	return month ? month : 12;
}

int main(){
	FILE *fin = fopen("friday.in","r");
	FILE *fout = fopen("friday.out","w");

	int thirteen = 6; //1900-1-13 is Saturday
	int N;
	fscanf(fin, "%d", &N);
	int initYear = 1900, untilYear = 1900+N-1;
	int year = initYear;
	int month;
	int nextThir;
	for(initArray(satisfaction, 7), month=1; year <= untilYear;month = (month+1)%12 ){
		printf("%d ",year);
		satisfaction[thirteen]++;
		if(Days[month] == 28){
			thirteen = (thirteen + Days[month] + isLeapYear(year) )%7;
		}else{
			thirteen = (thirteen + Days[month] )%7;
		}
		if(!month){
			year++;
		}
	}
	for(N=6;N!=5;N=(N+1)%7){
		fprintf(fout, "%d ", satisfaction[N]);
	}
	fprintf(fout, "%d\n",satisfaction[5]);

	return 0;
}
