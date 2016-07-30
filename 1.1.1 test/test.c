/*
ID:violin01
LANG:C
TASK:test
*/

// #开头的语句叫做预处理语句，跟C代码其实是两回事，但它是必须的。
//这句的意义是引入 stdio.h 这个头文件，以使用其中的一些函数
#include <stdio.h>

// main函数的参数多种多样，以下是最标准的一种，其他形式诸如(void)甚至直接()都是可以的
//但是要注意main 函数一定要有返回值且返回值一定要是int。很多教程的main函数都没有返回值或者
//返回值是void，这都是不标准的。
int main(int argc,char* argv[]){
	FILE *fin = fopen("test.in", "r");
	FILE *fout = fopen("test.out", "w");

	int a, b;
	fscanf(fin, "%d %d", &a, &b);
	fprintf(fout, "%d\n", a+b);
	return 0;
}

//C程序看起来比java要清爽得多是不是。所以我推荐你先学C，因为它语法简单一些，可以更多地将精力
//集中于数据类型和循环控制，条件控制等语法要素上。