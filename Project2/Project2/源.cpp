#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<stack>
#include<cassert>

//输入一个链表的头节点，从头到尾，反过来打印出每个节点的值
class LinkNode
{
public:
	int value;
	LinkNode* next;
};

void init(LinkNode& linkhead)
{
	linkhead.value = 0;
	linkhead.next = NULL;
}

void addnode(LinkNode& l, int value)
{
	LinkNode* newnode = new LinkNode;
	assert(newnode != NULL&&(&l)!=NULL);
	newnode->next = NULL;
	newnode->value = value;
	if (l.next == NULL)
	{
		l.next = newnode;
	}
	else
	{
		LinkNode* tail = &l;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	l.value++;
}

void myprint(LinkNode& l)
{
	LinkNode* tail = &l;
	cout << l.value << ":";
	while (tail->next != NULL)
	{
		tail = tail->next;
		cout << tail->value << "->";
	}
	cout << endl;
}

//不改变原数据结构的基础上，利用栈进行逆序打印
void reprint(LinkNode& l)
{
	//LinkNode* tail = &l;
	//stack<int> s;
	//cout << l.value << ":";
	//while (tail->next != NULL)
	//{
	//	tail = tail->next;
	//	s.push(tail->value);
	//}
	//for (int i = 0; i < l.value; i++)
	//{
	//	cout << s.top() << "<-";
	//	s.pop();
	//}
	//cout << endl;

	//也可以利用递归进行逆序打印
	if (&l != NULL)
	{
		if (l.next != NULL)
		{
			reprint(*l.next);
		}
		cout << l.value << "<-";
	}
}

int main()
{
	LinkNode Linkhead;
	init(Linkhead);
	addnode(Linkhead, 1);
	addnode(Linkhead, 2);
	addnode(Linkhead, 3);
	addnode(Linkhead, 4);
	addnode(Linkhead, 5);
	myprint(Linkhead);
	reprint(Linkhead);
	return 0;
}