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
	bool solve(TreeNode *root, int currSum, int targetSum)
	{
		if (!root)
		{
			return false;
		}
		currSum += root->val;
		if (!root->left && !root->right)
		{
			if (currSum == targetSum)
			{
				return true;
			}
		}

		return solve(root->left, currSum, targetSum) || solve(root->right, currSum, targetSum);
	}

	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (!root)
		{
			return false;
		}
		return solve(root, 0, targetSum);
	}
};