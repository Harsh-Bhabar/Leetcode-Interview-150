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
	int getMinimumDifference(TreeNode *root)
	{
		stack<TreeNode *> st;

		int ans = INT_MAX;
		int prev = -1;

		while (root || !st.empty())
		{
			while (root)
			{
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();

			if (prev != -1)
			{
				ans = min(ans, abs(root->val - prev));
			}

			prev = root->val;
			root = root->right;
		}

		return ans;
	}
};