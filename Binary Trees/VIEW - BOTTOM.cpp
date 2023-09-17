
class Solution
{
public:
	vector<int> bottomView(Node *root)
	{
		// Your Code Here
		if (!root)
		{
			return {};
		}

		map<int, int> mp;
		vector<int> ans;
		queue<pair<Node *, int>> q;
		q.push({root, 0});

		while (!q.empty())
		{
			int n = q.size();
			while (n--)
			{
				Node *curr = q.front().first;
				int vLevel = q.front().second;
				q.pop();

				mp[vLevel] = curr->data;

				if (curr->left)
				{
					q.push({curr->left, vLevel - 1});
				}
				if (curr->right)
				{
					q.push({curr->right, vLevel + 1});
				}
			}
		}

		for (auto i : mp)
		{
			ans.push_back(i.second);
		}

		return ans;
	}
};