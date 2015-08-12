


// __________________________ 1000 A + B Problem  __________________________
/*
题目来源:

http://acm.hdu.edu.cn/showproblem.php?pid=1000cters/

*/  


/*
Problem Description
Calculate A + B.
 

Input
Each line will contain two integers A and B. Process to end of file.
 

Output
For each case, output A + B in one line.
 

Sample Input
1 1
 

Sample Output
2
 
*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(n),空间复杂度O(1)

#include<stdio.h>

int main()
{
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
  	printf ("%d\n", a + b);
  }
  
  return 0;
}


/*

scanf("%d %d",&a,&b)返回输入的数据和格式字符串中匹配次数。

当dos或windows中输入ctrl+z（模拟文件结束符EOF）时，scanf返回EOF,

所以当输入终止符ctrl+z时，退出while循环

scanf()函数接收输入数据时，遇以下情况结束一个数据的输入：（不是结束该scanf函数，scanf函数仅在每一个数据域均有数据，并按回车后结束）。
        ① 遇空格、“回车”、“跳格”键。
        ② 遇宽度结束。
        ③ 遇非法输入。

*/