#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

////��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת
////����һ����������������һ����ת�������ת�������СԪ�ء�����{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת
////���������СֵΪ1.
//
//int min(int* arr, int len)
//{
//	int* first = arr;
//	int* second = arr + len-1;
//	int mid = len / 2;
//	while (first != second)
//	{
//		if (arr[mid] < *first)
//		{
//			min(arr + mid, len - mid);
//		}
//		else
//		{
//			min(arr, mid);
//		}
//	}
//	return *first;
//}
//
//int main()
//{
//	int arr[] = { 3,4,5,1,2 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	cout << min(arr, len);
//	return 0;
//}

//˳������
int sequential_search(int * a, int n, int key)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			num = i;
			return num;
		}
	}
	return -1;
}

//��������
int Binary_search(int* a, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] < key)
		{
			low = mid + 1;
		}
		else if (a[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//��ֵ����
//�ı��۰���ҵ�midֵmid=low+key-a[low]/a[high]-a[low]*(high-low)
int Binary_search_1(int* a, int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low+((key-a[low])/(a[high]-a[low]))*(high-low);
		if (a[mid] < key)
		{
			low = mid + 1;
		}
		else if (a[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 4;
	/*int ret=sequential_search(arr, 10, key);*/
	int ret = Binary_search_1(arr, 10, key);
	cout << ret << endl;
	return 0;
}