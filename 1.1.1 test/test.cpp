/*
ID:violin01
LANG:C++
TASK:test
*/

//跟C差不多的预处理语句，不过要注意在C++中引用标准库中的头文件是不带 .h 后缀的
#include <iostream>
#include <string>
#include <fstream>

//这一句死记硬背就好... std是standard的前三个字母
using namespace std;

// C++的 main 函数格式要求与C相同
int main(){
	ofstream fout("test.out");
	ifstream fin("test.in");

	int a, b;

	//赋值语句，将文件中的数据依次赋值给a ,b两个变量
	fin >> a >> b;

	//输出语句，依次将 a+b 的值和 endl 输出到文件中去。 endl是换行符，与C输出函数中的 \n 等同,也就是'回车' 。
	fout << a+b << endl;
	return 0;
}