#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//给定一个正整数 n ，你可以做如下操作：
//
//如果 n 是偶数，则用 n / 2替换 n 。
//如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
//n 变为 1 所需的最小替换次数是多少？


//递归算法
//int integerReplacement(int n) {
//	static int num = 0;
//	if (n != 1)
//	{
//		if (n % 2 == 0)
//		{
//			n /= 2;
//			num++;
//			integerReplacement(n);
//		}
//		else
//		{
//			n++;
//			num++;
//			integerReplacement(n);
//		}
//	}
//	return num;
//}

//出错，重点是利用+1或者-1求次数最少
//int integerReplacement(int n) {
//	int num = 0;
//	while (n != 1)
//	{
//		num++;
//		if (n % 2 == 0)
//		{
//			n /= 2;
//		}
//		else
//		{
//			n++;
//		}
//		cout << n <<" "<< num<< endl;
//
//	}
//	return num;
//}


int main()
{
	cout<<integerReplacement(65535)<<endl;

	return 0;
}