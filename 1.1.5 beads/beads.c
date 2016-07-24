/*
ID:violin01
LANG:C
TASK:beads
*/

#include <stdio.h>

int* assign(){
	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	int N;
	fscanf(fin, "%d", &N);
	int *beads = (int*)malloc(sizeof(int)*N);
	int i;
	for(i=0; i<N ; i++){
		fscanf(fin, "%c", &beads[i]);
	}
	return beads;
}

void merge(int beads[]){
}

void dealWhite(int beads[], int whiteBeads[]){
}

int findBreakPositon(int beads[]){
}

int getMaxContinues(int beads[], int whiteBeads[]){
}

int main(){
	int *beads = assign();
	int N = sizeof(beads) / sizeof(int);


	return 0;
}
