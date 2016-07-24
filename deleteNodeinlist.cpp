//在O(1)时间复杂度内删除链表节点
//给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间复杂度内删除链表节点
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
}

void DeleteListNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
		return;
	//要删除的节点不是尾节点
	if(pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		
		delete pNext;
		pNext = NULL;
	}
	//链表只有一个节点
	else if(*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	//链表中有多个节点，删除尾节点
	else
	{
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

