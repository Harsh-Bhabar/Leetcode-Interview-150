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
	int ans = 0;

	void solve(TreeNode *root, int currVal)
	{
		if (!root->left && !root->right)
		{
			currVal = currVal * 10 + (root->val);
			ans += currVal;
			return;
		}

		currVal = currVal * 10 + root->val;

		if (root->left)
		{
			solve(root->left, currVal);
		}
		if (root->right)
		{
			solve(root->right, currVal);
		}
	}

	int sumNumbers(TreeNode *root)
	{
		solve(root, 0);
		return ans;
	}
};