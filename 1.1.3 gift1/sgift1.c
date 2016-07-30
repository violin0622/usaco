#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person{
	char name[20];
	int money;
	int *friends;
}Person;

int findPosition(Person persons[], char* name)
{
	int i=0;
	for(i=0; i<sizeof(persons); i++)
	{
		if(strcmp(persons[i].name,name) == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	FILE *fin = fopen("gift1.in","r");
	FILE *fout = fopen("gift1.out","w");

	int Np;
	int temp;
	//fscanf(fin,"%d",&temp);
	scanf("%d",&temp);
	Np = temp;
	int i=0;
	Person *persons = (Person*)malloc(sizeof(Person)*Np);
	for(i=0;i<Np;i++)
	{
		fscanf(fin,"%s", &(persons[i].name));
	}
	printf("Np:%d\n",Np);
	char people[]="";
	char friendName[]="";
	int position;
	int NF;
	printf("Np:%d\n",Np);
	for(i=0; i<Np; i++)
	{
		printf("\n%d,outer\n",Np);
		printf("%d,temp\n",temp);
		//fscanf(fin,"%s",&people);
		//position = findPosition(persons,people);
		//fscanf(fin,"%d",&persons[position].money);
		//fscanf(fin,"%d",&NF);
		//persons->friends = (int*)malloc(sizeof(int)*NF);
		//for(i=0; i<NF; i++)
		//{
		//	printf("inner");
		//	fscanf(fin,"%s",&friendName);
		//	persons->friends[i] = findPosition(persons,friendName);
		//}
	}


	return 0;
}
