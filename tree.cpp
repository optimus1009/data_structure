//树
//树的基本操作

//+++++插入
//+++++删除
//+++++查找
//+++++前序遍历
//+++++中序遍历
//+++++后序遍历

typedef struct tagSTreeNode
{
	int value;
	tagSTreeNode* pLeft;
	tagSTreeNode* pRight;
	
	tagSTreeNode(int v):value(v),pLeft(NULL),pRight(NULL) {}
	
}STreeNode;

typedef void(*VISIT)(int value);

//二叉树的查找
STreeNode* CBinaryTree::Find(int value) const
{
	if(!m_pRoot)
		return NULL;
	STreeNode* pNode = m_pRoot;
	while(pNode)
	{
		if(value < pNode->value)
			pNode = pNOde -> pLeft;
		else if(value > pNode -> value)
			pNOde = pNOde -> pRight;
		else
			return pNOde;
	}
	return NULL;
}

//二叉树的插入
bool CBinaryTree::Insert(int value)
{
	return _Insert(m_pRoot, value);
}
bool CBinaryTree::_Insert(STreeNode* pRoot, int value)
{
	if(!pRoot)
	{
		pRoot = new STreeNode(value);
		return true;
	}
	if(value < pRoot -> value)
		return _Insert(pRoot -> pLeft, value);
	if(value > pRoot -> value)
		return false;
}

//二叉树插入（非递归版本）
bool CBinaryTree::Insert(int value)
{
	return _Insert2(value);
}
bool CBinaryTree::_Insert2(int value)
{
	if(!m_pRoot)
	{
		m_pRoot = new STreeNode(value);
		return true;
	}
	STreeNode* pNode = m_pRoot;
	STreeNode* pCur = m_pRoot;
	while(pNOde)
	{
		//寻找合适的插入点，并将活动节点用PCur记录下来
		pCur = pNOde;
		if(value < pNOde -> value)
			pNode = pNOde -> pLeft;
		else if(value > pNode -> value)
			pNode = pNOde -> pRight;
		else
			return false;
	}
	//开始插入（一定是插入到叶节点）
	if(value < pCur -> value)
		pCur -> pLeft = new STreeNode(value);
	else if (value > pCur -> value)
		pCur -> pRight = new STreeNode(value);
	return true;
}
//二叉树的删除
//记录待删除的节点为P，分三种情况进行处理
//-------------P为叶子节点
//-------------P为单支节点
//-------------P的左子树和右子树均不为空

//叶子节点
void CBinaryTree::DeleteChildless(STreeNode* pParent, STreeNode* pNode)
{
	if(pNode == m_pRoot)
		m_pRoot = NULL;//只有一个根节点，将根节点置空
	else if(pParent -> pLeft == pNOde)
		pParent -> pLeft = NULL;
	else 
		pParent -> pRight = NULL;
	delete pNOde;
}

//单支节点
void CBinaryTree::DeleteSingleSon(STreeNode* pParent, STreeNode* pNOde)
{
	STreeNode* pGrandSon = pNode -> pLeft ? pNOde->pLeft:pNOde->pRight;
	if(pNOde == m_pRoot)
		m_pRoot = pGrandSon;
	else if(pParent->pLeft == pNOde)
		pParent->pLeft = pGrandSon;
	else
		pParent->pRight = pGrandSon;
	delete pNOde;
}

bool CBinaryTree::Delete(int value)
{
	if(!m_pRoot)
		return false;
	
	//查找待删除的节点
	STreeNode* pNOde = m_pRoot;
	STreeNode* pParent = NULL;
	while(pNOde)
	{
		if(value < pNOde -> value)
		{
			pParent = pNOde;
			pNOde = pNode -> pLeft;
		}
		else if(value > pNode -> value)
		{
			pParent = pNode;
			pNode = pNode -> pRight;
		}
		else//找到待删除值
		{
			break;
		}
	}
	if(!pNode)//没有找到
	{
		return false;
	}
	if(!pNode -> pLeft && !pNode -> pRight)
	{
		DeleteChildless(pParent,pNode);
	}
	else if(!pNode -> pLeft || pNode -> pRight)
	{
		DeleteSingleSon(pParent, pNode);
	}
	else//删除双支节点
	{
		STreeNode* pCur = pNOde;//暂存待删除节点
		pParent = pNode;
		pNode = pNode ->pLeft;
		while(pNode -> pRight)//找到当前结点的左支最右孩子
		{
			pParent = pNode;
			pNode = pNode-> pRight;
		}
		pCur -> value = pNOde -> value;//删除数据
		if(!pNOde ->pLeft)
		{
			DeleteChildless(pParent, pNOde);
		}
		else
			DeleteSingleSon(pParent,pNode);
	}
}

//前序遍历(递归版本)
void CBinaryTree::preOrder(VISIT visit) const
{
	_PreOrder2(visit);
}
void CBinaryTree::_PreOrder(STreeNode* pRoot, VISIT visit) const
{
	if(pRoot)
	{
		visit(pRoot -> value);
		_PreOrder(pRoot->pLeft,visit);
		_PreOrder(pRoot->pRight,visit);
	}
}
//前序遍历(非递归版本)
void CBinaryTree::_PreOrder2(VISIT visit) const
{
	if(!m_pRoot)
		return;
	stack<STreeNode* > s;
	s.push(m_pRoot);
	STreeNode* pCur;
	while(!s.empty())
	{
		pCur = s.top();
		s.pop();
		visit(pCur -> value);
		if(pCur -> pRight)
			s.push(pCur->pRight);
		if(pCur->pLeft)
			s.push(pCur->pLeft)
	}
}

//中序遍历（递归版本）
void CBinaryTree::InOrder(VISIT visit) const
{
	_InOrder(m_pRoot, visit) ;
}
void CBinaryTree::_InOrder(STreeNode* pRoot,VISIT visit) const
{
	if(pRoot)
	{
		_InOrder(pRoot->pLeft,visit);
		visit(pRoot->value);
		_InOrder(pRoot->pRight,visit);
	}
}

//中序遍历（非递归版本）
void CBinaryTree::_InOrder(VISIT visit) const
{
	stack<STreeNode*> s;
	STreeNode* pCur = m_pRoot;
	while(pCur || s.empty())
	{
		while(pCur)//找最左孩子
		{
			s.push(pCur);
			pCur = pCur->pLeft;
		}
		if(!s.empty())
		{
			pCur = s.top();//访问左孩子为空的节点
			s.pop();
			visit(pCur -> value);
			pCur = pCur->pRight;
		}
		
	}
}
