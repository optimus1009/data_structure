//链表中倒数第K个节点
//输入一个链表，输出该链表中倒数第k个节点，

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
}

ListNode* FindKthToTail(ListNode* pListNode, unsigned int k)
{
	if(pListNode == NULL || k ==0)
		return;
	ListNode* pAhead = pListNode;
	ListNode* pBehind = NULL;
	
	for(unsigned int i =0; i< k-1;++i)
	{
		if(pAhead->m_pNext != NULL)
			pAhead = pAhead->m_pNext;
		else
			return NULL;
	}
	pBehind = pListNode;
	while(pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
}