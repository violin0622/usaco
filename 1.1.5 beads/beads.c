/*
ID:violin01
LANG:C
TASK:beads
*/

#include <stdio.h>

int getSize(int array[]){
	int i=0;
	int length = sizeof(array) / sizeof(int);
	for(i=0; array[i]!='\0'; i++);
	return 1+i;
}

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

//将同种颜色的珠子合并为一个数字。
//当遇到白色珠子时，将白色珠子的数量和位置同时保存在beads和whiteBeads数组内
//以便于后续的操作
//对于没有数据的数组位，采用填补'\0'或0的方式
void merge(int beads[], int whiteBeads[], int N){
	int i=0;
	int flag = 0, preColor=beads[0], count=1;
	for(i=1; i<N; i++){
		if(beads[i] == preColor){
			count++;
			beads[i] = '0';
			whiteBeads[i] = 0;
		}else{
			beads[flag] = count;
			whiteBeads[flag] = preColor;
			flag++;
			count = 1;
			preColor = beads[i];
		}
	}
	//若首段末段颜色相同则将其合并至首段
	if(beads[flag] == beads[0]){
		beads[0] += beads[flag];
		whiteBeads[flag] = '\0';
		beads[flag] = '\0';
	}
	beads[flag+1] = '\0';
	whiteBeads[flag+1] = '\0';
}

void dealWhite(int beads[], int whiteBeads[], int N){
	//寻找白色珠子,若其两端颜色相同则“同化”，若不同则保留
	int i=0;
	int size = getSize(beads);
	if(whiteBeads[0] == 'w' && whiteBeads[1] == whiteBeads[size-1])
		whiteBeads[0] = whiteBeads[1];
	for(i=1; beads[i]!='\0'; i++){
		if(whiteBeads[i] == 'w' && whiteBeads[i-1] == whiteBeads[i+1]){
			whiteBeads[i] = whiteBeads[i-1];
		}
	}
	//将同色的合并，空位补0
	int pre=0;
	for(i=0; beads[i]!='\0'; i++){
		if(whiteBeads[pre] == whiteBeads[i]){
			beads[pre] += beads[i];
			beads[i] = '0';
			whiteBeads[i] = '0';
		}else{
			pre = i;
	}
	//数据左移，填补0位
	int flag=0;
	for(i=0;beads[i]!='\0'; i++){
		if(beads[i] && beads[flag] == '0'){
			beads[flag] = beads[i];
			whiteBeads[flag] = whiteBeads[i];
			beads[i] = '0';
			whiteBeads[i] = '0';
			flag++;
		}else if(!beads[i] && beads[flag]!='0'){
			flag = i;
		}else{
			continue;
		}
	}
	//处理末位
	if(whiteBeads[i] 
}

int findBreakPositon(int beads[]){
}

int getMaxContinues(int beads[], int whiteBeads[]){
}

int main(){
	int *beads = assign();
	int N = sizeof(beads) / sizeof(int);
	int *whiteBeads = (int*)malloc(sizeof(int)*N);

	merge(beads, whiteBeads, N);



	return 0;
}
