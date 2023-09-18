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
	map<int, int> inorderMap;

	TreeNode *solve(vector<int> &postorder, int &postPos, vector<int> &inorder, int start, int end)
	{
		if (postPos < 0 || start > end || start < 0 || end > inorder.size())
		{
			return NULL;
		}
		TreeNode *newNode = new TreeNode(postorder[postPos]);
		postPos--;
		int inorderPos = inorderMap[newNode->val];

		newNode->right = solve(postorder, postPos, inorder, inorderPos + 1, end);
		newNode->left = solve(postorder, postPos, inorder, start, inorderPos - 1);

		return newNode;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		int n = inorder.size();
		if (n == 0)
		{
			return NULL;
		}
		for (int i = 0; i < n; i++)
		{
			inorderMap[inorder[i]] = i;
		}
		int postPos = n - 1;
		return solve(postorder, postPos, inorder, 0, n - 1);
	}
};