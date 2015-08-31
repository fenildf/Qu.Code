#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



#ifndef __1137_Question_H__
#define __1137_Question_H__

using namespace std;

/*    1137 矩阵乘法
给出2个N * N的矩阵M1和M2，输出2个矩阵相乘后的结果。
Input
第1行：1个数N，表示矩阵的大小(2 <= N <= 100)
第2 - N + 1行，每行N个数，对应M1的1行(0 <= M1[i] <= 1000)
第N + 2 - 2N + 1行，每行N个数，对应M2的1行(0 <= M2[i] <= 1000)
Output
输出共N行，每行N个数，对应M1 * M2的结果的一行。

题目网址：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1137
*/

typedef long long ll;



// 矩阵初始化-给矩阵赋值-通过 cin 
void initMatrixDataByCin(vector<vector<ll>> & matrix, int N) {
	for (int i = 0; i < N; ++i) {
		vector<ll> temp;
		for (int j = 0; j < N; ++j) {
			int element;
			cin >> element;
			temp.push_back(element);
		}
		matrix.push_back(temp);
	}
}

// 矩阵初始化-给矩阵赋值-通过 函数传参
void initMatrixDataByImport(vector<vector<ll>> & matrix, int N, int num) {
	for (int i = 0; i < N; ++i) {
		vector<ll> temp;
		for (int j = 0; j < N; ++j) {
			temp.push_back(num);
		}
		matrix.push_back(temp);
	}
}

// 二阶矩阵元素-相乘
ll mulby2Marix(vector<vector<ll>> & a, vector<vector<ll>> & b, int i, int j) {
	ll temp;
	int N = a.size();
	for (int k = 0; k < N; ++k)
	{
		temp += a[i][k] * b[k][j];
	}
	return temp;
}

// N*N 矩阵乘法。
void mulMar(vector<vector<ll>> & s1, vector<vector<ll>> & a, vector<vector<ll>> & b, int N) {

	//int N =  s1.size();	// 读取出矩阵的 尺寸
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ll temp;
			for (int k = 0; k < N; ++k) {
				temp += a[i][k] * b[k][j];
			}
			s1[i][j] = temp;
		}
	}
}

int main_1137_AC() {		// 通过AC测试的 main() 函数
	vector<vector<ll>> a;
	vector<vector<ll>> b;
	vector<vector<ll>> s;

	int N;
	cin>>N;	//决定是多大的 N*N矩阵
	initMatrixDataByCin(a, N);
	initMatrixDataByCin(b, N);
	initMatrixDataByImport(s, N, 0);

	mulMar(s, a, b, int N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << s[i][j] << " ";
		}
		cout << endl;	// cout<<endl;或者cout<<"\n"; 实现换行效果
	}

	return 0;
}

int main_1137_Test() {

	long long n;
	long long sum;

#if 0
	n = 5024295251;
	long long i = n;
	while (i <= n)
	{
		sum = fibonacci(i);
		sum %= remainder;  
		cout << sum << "%n";
		++i;
	}
#else

#endif
	return 0;
}

#endif // __1137_Question_H__