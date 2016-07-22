//#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
//#include "ListNode.h"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
void PrintListNode(ListNode* pNode)
{
	if (pNode == NULL)
	{
		printf("The node is NULL\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\nPrintList ends.\n");
}

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode;
	pNode->m_nValue = value;
	pNode->m_pNext = NULL;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == NULL)
	{
		printf("Error to connect two nodes \n");
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}
ListNode * ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
		{
			pReverseHead = pNode;
		}
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

// +++++++++++testcode++++++++++
ListNode* Test(ListNode* pHead)
{
	printf("the original list is : \n");
	PrintList(pHead);

	ListNode* pReverseHead = ReverseList(pHead);

	printf("the reverse list is: \n");
	PrintList(pReverseHead);
	return pReverseHead;
}

void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	ListNode* pReversedHead = Test(pNode1);

	DestroyList(pReversedHead);
}

int main(int argc, _TCHAR* argv[])
{
	Test1();
	return 0;
}
