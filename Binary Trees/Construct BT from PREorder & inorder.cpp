/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	unordered_map<int, int> inorderMap;

	TreeNode *solve(vector<int> &preorder, int &prePos, vector<int> &inorder, int l, int r)
	{
		if (l < 0 or r > inorder.size() or l > r)
		{
			return NULL;
		}
		TreeNode *newNode = new TreeNode(preorder[prePos]);
		int inorderPos = inorderMap[preorder[prePos]];
		prePos++;

		newNode->left = solve(preorder, prePos, inorder, l, inorderPos - 1);
		newNode->right = solve(preorder, prePos, inorder, inorderPos + 1, r);

		return newNode;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		for (int i = 0; i < inorder.size(); i++)
		{
			inorderMap[inorder[i]] = i;
		}
		int prePos = 0;
		return solve(preorder, prePos, inorder, 0, inorder.size() - 1);
	}
};