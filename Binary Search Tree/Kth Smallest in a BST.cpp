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
	int kthSmallest(TreeNode *root, int k)
	{
		if (!root)
		{
			return -1;
		}

		stack<TreeNode *> st;

		while (root || !st.empty())
		{
			while (root)
			{
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();

			if (k == 1)
			{
				return root->val;
			}
			k--;

			root = root->right;
		}

		return -1;
	}
};