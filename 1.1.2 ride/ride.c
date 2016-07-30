#include <stdio.h>

int main(){
	FILE *fin = fopen("ride.in","r");
	FILE *fout = fopen("ride.out","w");

	char names[7] = {'\0'};
	char groups[7] = {'\0'};
	int i=0;

	fscanf(fin,"%s",names);
	fscanf(fin,"%s",groups);

	int one=1, two=1;
	for(i=0;names[i] != '\0';i++){
		one *= (names[i]-'A'+1);
	}
	for(i=0; groups[i] != '\0'; i++){
		two *= (groups[i]-'A'+1);
	}
	
	if(two%47 == one%47){
		fprintf(fout, "GO\n");
	}else{
		fprintf(fout, "STAY\n");
	}
	return 0;
}

