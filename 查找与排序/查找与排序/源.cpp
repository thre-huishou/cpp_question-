#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

////把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
////输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如{3,4,5,1,2}为{1,2,3,4,5}的一个旋转
////该数组的最小值为1.
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

//顺序表查找
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

//有序表查找
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

//插值查找
//改变折半查找的mid值mid=low+key-a[low]/a[high]-a[low]*(high-low)
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