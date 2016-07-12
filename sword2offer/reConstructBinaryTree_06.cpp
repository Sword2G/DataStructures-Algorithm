struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
{
	
	if(pre.size() == 0 || in.size() == 0)
		return NULL;
	if(pre.size()  != in.size())
		return NULL;

	int length = pre.size();

	vector<int> left_pre, left_in, right_pre, right_in;

	struct TreeNode * root;

	root = new TreeNode(pre[0]);
	
	int rootIn = 0;
	
	for(int i = 0; i < length; i++)
	{
		if(in[i] == pre[0])
		{	
			rootIn = i;
			break;
		}
	}

	for(int i = 0; i < rootIn; i++)
	{
		left_in.push_back(in[i]);
		left_pre.push_back(pre[i+1]);
	}

	for(int i = rootIn + 1; i < length; i++)
	{
		right_in.push_back(in[i]);
		right_pre.push_back(pre[i]);
	}

	if(left_in.size() > 0)
		root->left = reConstructBinaryTree(left_pre, left_in);
	if(right_in.size() > 0)
		root->right = reConstructBinaryTree(right_pre, right_in);
	
	return root;

}

struct TreeNode* reConstructBinaryTree(int *pre, int *in, int length)
{
	if(pre == NULL || in == NULL || legth <=0)
		return NULL;

	return reConstruct(pre, pre + length - 1, in, in + length - 1);
}

struct TreeNode* reConstruct(int *startPre, int *endPre, int *startIn, int *endIn)
{
	if(startPre == NULL || endPre == NULL || startIn == NULL || endIn == NULL)
		return NULL;
	
    struct ListNode * root = (struct List *)malloc(sizeof(struct ListNode));
	rootVal = startPre[0];
	root->val = rootVal;
	root->left = root->rigth = NULL;
	
	if(startPre == endPre)
		return root;
	
	int *rootIn = startIn;
	
	while(*rootIn != rootVal && rootIn <= endIn)
		rootIn++;

	int length = rootIn - startPre;
	int *newEndPre = startPre + length;

	if(length > 0)
		root->left = reConstructBinaryTree(startPre + 1, newEndPre, startIn, rootIn - 1);
	if(endIn - rootIn + 1 > 0)
		root->right = reConstructBinaryTree(newEndPre + 1, EndPre, rootIn + 1, endIn);

	return root;
}