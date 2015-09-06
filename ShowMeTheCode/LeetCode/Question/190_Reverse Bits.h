#include<cstdio>
#include<stdlib.h>
#include<cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

题目网址： https://leetcode.com/problems/reverse-bits/

*/
typedef unsigned int uint32_t;
uint32_t bitmapOne[32];     //      1,     10,      100,     1000,  ...
uint32_t bitmapZero[32];    // 111110，111101， 1111011， 1110111， ...
bool m_isInit = false;
void initbit() {
	if (m_isInit == false) {
		m_isInit = true;

		for(int j = 0; j < 32; ++j) {
			bitmapOne[j]    = (1 << j);
			bitmapZero[j]   = ~bitmapOne[j];
		}
	}
}

uint32_t reverseBits(uint32_t n) {
	initbit();

	uint32_t bit1;
	uint32_t bit2;
	for (int i = 0; i < 16; ++i) {
		bit1 = (n&bitmapOne[i]);       // 取得右边的一位
		bit2 = (n&bitmapOne[31-i]);    // 取得左边对称的那一位

		n &= bitmapZero[i];         // 把待换位置0
		n &= bitmapZero[31-i];      // 把待换位置0

		n |= (bit2 >> (31-i*2));	  // 左边赋值到右边
		n |= (bit1 << (31-i*2));      // 右边赋值到左边
	}

	return n;
}