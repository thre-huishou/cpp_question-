#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//����ĳ��������ǰ�����������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж�����
//�ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
//���ؽ���ͼ2.6��ʾ�Ķ��������������ͷ�ڵ㣬�������ڵ�Ķ������£�

class BinaryTreeNode
{
public:
	int m_value;
	BinaryTreeNode* m_pleft;
	BinaryTreeNode* m_pright;
};
BinaryTreeNode* constructcore(int * startpreorder, int* endpreorder, int* startinorder, int* endinorder)
{
	int rootvalue = startpreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_value = rootvalue;
	root->m_pleft = root->m_pright = NULL;
	if (startpreorder == endpreorder)
	{
		if (startinorder == endinorder && *startpreorder == *startinorder)
		{
			return root;
		}
		else
		{
			throw std::exception("invalid input");
		}
	}
	int* rootinorder = startinorder;
	while (rootinorder <= endinorder && *rootinorder != rootvalue)
		++rootinorder;

	if (rootinorder == endinorder && *rootinorder != rootvalue)
	{
		throw std::exception("invalid input");
	}
	int leftlength = rootinorder - startinorder;
	int* leftpreorderend = startpreorder + leftlength;
	if (leftlength > 0)
	{
		root->m_pleft = constructcore(startpreorder + 1, 
			leftpreorderend, startinorder, rootinorder - 1);
	}
	if (leftlength < endpreorder - startpreorder)
	{
		root->m_pright = constructcore(leftpreorderend + 1, endpreorder, rootinorder + 1, endinorder);
	}
	return root;
}

BinaryTreeNode* construct(int * preorder, int * inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}
	return constructcore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int main()
{
	int a[] = { 1,2,4,7,3,5,6,8 };
	int b[] = { 4,7,2,1,5,3,8,6 };
	construct(a, b, 8);
	return 0;
}