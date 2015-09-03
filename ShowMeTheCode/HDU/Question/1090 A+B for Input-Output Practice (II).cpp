


// __________________________ 1090 A+B for Input-Output Practice (II)  __________________________
/*
题目来源:
http://acm.hdu.edu.cn/showproblem.php?pid=1090

*/  


/*
Problem Description
Your task is to Calculate a + b.
 

Input
Input contains an integer N in the first line, and then N lines follow. Each line consists of a pair of integers a and b, separated by a space, one pair of integers per line. 
 

Output
For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input. 
 

Sample Input
2
1 5
10 20
 

Sample Output
6
30
 
*/

// __________________________ Tags __________________________
/*
	 
*/

// __________________________ 实现细节 __________________________ 

// 代码1
// 时间复杂度O(),空间复杂度O()

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}