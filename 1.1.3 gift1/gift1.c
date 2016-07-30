/*
ID:violin01
LANG:C
TASK:gift1
*/
#include <string.h>
#include <stdio.h>

void initArray(int[]);
int findPosition(int, char[], char[][20]);

int main(){
	FILE *fin = fopen("gift1.in","r");
	FILE *fout = fopen("gift1.out","w");

	char names[20][20] = {'\0'};
	int initial_money[10], final_money[10], left[10];
	
	initArray(initial_money);
	initArray(final_money);
	initArray(left);
	
	int NP=0,i=0;
	for(i=0; i<10; i++){
	}
	fscanf(fin, "%d", &NP);
	for(i=0; i<NP; i++){
		fscanf(fin, "%s", names[i]);
	}

	char name[20];
	char fname[20];
	int position, fposition, NF; 
	int gift,temp = NP;
	for(i=0; i<temp; i++){

		fscanf(fin, "%s", name);
		position = findPosition(NP,name,names);
		fscanf(fin, "%d", &initial_money[position]);
		fscanf(fin, "%d", &NF);
		if(NF){
			gift = initial_money[position] / NF;
			left[position] = initial_money[position] % NF;
			printf("left: %d\n", left[position]);
		}else{
			gift = 0;
			left[position] = initial_money[position];
		}

		while(NF>0){
			fscanf(fin, "%s", fname);
			fposition = findPosition(NP,fname,names);
			final_money[fposition] += gift;
			NF--;
		}
	}

	int diff=0;
	for(i=0; i<temp; i++, diff=0){
		//diff = final_money[i] + 2*left - initial_money[i];
		//final_money[i] -= (initial_money[i] - left);
		//final_money[i] = final_money[i] + 2*left -initial_money[i];
		diff = final_money[i] + left[i] - initial_money[i];
		printf("diff: %d\n", diff);
		fprintf(fout, "%s %d\n", names[i],diff);
	}
	return 0;
}

int findPosition(int NP, char name[],char names[10][20]){
	int i=0;
	for(i=0; i<NP; i++){
		if(!strcmp(name,names[i])){
			return i;
		}
	}
	return 0;
}

void initArray(int array[])
{
	int i=0;
	for(i=0; i<10; i++){
		array[i] = 0;
	}
}

