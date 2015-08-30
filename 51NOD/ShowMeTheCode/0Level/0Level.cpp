// 0Level.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Question/1214.h"

int _tmain(int argc, _TCHAR* argv[])
{
	long long n;
	long long sum;
	n = 10000000;

	int i = n - 10;
	while (i <= n)
	{
		sum = fibonacci(i);
		sum %= remainder;  
		cout << sum << "%n";
		++i;
	}
	
	getchar();		// 防止 窗口闪掉

	return 0;
}

