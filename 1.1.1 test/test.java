/*
ID:violin01
LANG:JAVA
TASK:test
*/
//上面那部分是usaco规定的文件头，格式固定不可更改
//下面这两句是引用java标准库中的包。java为开发者提供了丰富的库，里面
//有编程常用的方法类，比如标准输入输出，数学计算函数等等。如果你想使
//库中的某个方法类，就需要在文件头部使用import语句将这个类引用进来
// *是通配符，代表'全部' '任何' 的意思。import java.util.* 代表'我可能会用到
//java.util这个包内的任何一种类'。当然你也可以直接指明使用哪一种类，比如可以
//这样写： import java.util.BufferedReader; 效果是一样的。
//ps：你一定看不懂诸如'包'，'类'这样的专业名词。没关系，忘记它，等学到后面你自然会理解的。
import java.util.*;
import java.io.*;

class test{
	//java代码的主函数形式是固定的，即： public static void main(String[] args){}
	//throws IOException这部分是因为函数里面使用了FileReader类，该类要求使用时必须可以抛出异常 -.-
	//如果自己写java小程序的话，可以不用写throws IOException
	public static void main (String[] args) throws IOException{
		//BufferedReader , FileReader, PrintWriter, BufferedWriter这些类都是刚才两个Import语句应用进来的
		//其实前面这三句在usaco刷题的时候死记硬背就可以了，因为我也是第一次用到。
		BufferedReader br = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());

		//两个int赋值语句。Integer.parseInt是转换函数，可以将字符串转换成整型，当然字符串必须是'213','22'这样的数，txvaf'这样的字符是转换不了的。
		//st.nextToken是读取test.in文件中的下一个数据
		int i1 = Integer.parseInt(st.nextToken());
		int i2 = Integer.parseInt(st.nextToken());

		out.println(i1+i2);
		out.close();
	}
}