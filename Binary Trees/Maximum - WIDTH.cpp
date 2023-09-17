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
	int widthOfBinaryTree(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}

		int ans = 0;
		queue<pair<TreeNode *, long>> q;
		q.push({root, 0});

		while (!q.empty())
		{
			int start = q.front().second;
			int end = q.back().second;
			ans = max(ans, end - start + 1);
			int n = q.size();

			while (n--)
			{
				TreeNode *currNode = q.front().first;
				long currInd = q.front().second - start;
				q.pop();

				if (currNode->left)
				{
					q.push({currNode->left, currInd * 2 + 1});
				}
				if (currNode->right)
				{
					q.push({currNode->right, currInd * 2 + 2});
				}
			}
		}

		return ans;
	}
};