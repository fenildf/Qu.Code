// 0Level.cpp : �������̨Ӧ�ó������ڵ㡣
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
	
	getchar();		// ��ֹ ��������

	return 0;
}

