


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
  while (scanf("%d%d", &a, &b) != EOF)
  printf ("%d\n", a + b);
  return 0;
}