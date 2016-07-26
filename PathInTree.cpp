
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	
}
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if(pRoot == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum,std::vector<int>& path,int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	
	//如果是叶子节点，并且路径上节点的和等于输入的值
	//打印出这条路径上的节点
	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if(currentSum == expectedSum && isLeaf)
	{
		printf("A path is found: ");
		std::vector<int >:: iterator iter = path.begin();
		for(; iter != path.end(); ++ iter)
			printf("%d\t",*iter);
	}
	//如果不是叶子节点，则遍历其子节点
	if(pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
	if(pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight,expectedSum,path,currentSum);
	path.pop_back();
}


//another version

class Solution {
public:
    void findpath(TreeNode* root,int leftsum)
    {
        path.push_back(root->val);
        if(leftsum-root->val==0&&!root->left&&!root->right)
        {
            paths.push_back(path);
        }
        if(root->left)
        {
            findpath(root->left,leftsum-root->val);
        }
        if(root->right)
        {
            findpath(root->right,leftsum-root->val);
        }
        path.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        if(root!=NULL)
        {
            findpath(root,expectNumber);
        }
        return paths;
    }
private:
    vector<vector<int> > paths;
    vector<int> path;
};