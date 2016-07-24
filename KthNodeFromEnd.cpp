//�����е�����K���ڵ�
//����һ����������������е�����k���ڵ㣬

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