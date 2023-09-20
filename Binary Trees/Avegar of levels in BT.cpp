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
	vector<double> averageOfLevels(TreeNode *root)
	{
		vector<double> ans;
		if (!root)
		{
			return ans;
		}

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			int div = n;
			double avg = 0.0;
			while (n--)
			{
				TreeNode *curr = q.front();
				q.pop();
				avg += double(curr->val);
				if (curr->left)
				{
					q.push(curr->left);
				}
				if (curr->right)
				{
					q.push(curr->right);
				}
			}
			ans.push_back(avg / div * 1.0);
		}

		return ans;
	}
};