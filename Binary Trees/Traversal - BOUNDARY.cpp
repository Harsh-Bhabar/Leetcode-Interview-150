class Solution
{
private:
	vector<int> ans;

	bool isLeafNode(Node *root)
	{
		return !root->left && !root->right;
	}

	void leftNodesWithoutLeaf(Node *root)
	{
		if (!root || isLeafNode(root))
		{
			return;
		}
		ans.push_back(root->data);
		if (root->left)
		{
			leftNodesWithoutLeaf(root->left);
		}
		else
		{
			leftNodesWithoutLeaf(root->right);
		}
	}

	void rightNodesWithoutLeaf(Node *root)
	{
		if (!root || isLeafNode(root))
		{
			return;
		}
		if (root->right)
		{
			rightNodesWithoutLeaf(root->right);
		}
		else
		{
			rightNodesWithoutLeaf(root->left);
		}
		ans.push_back(root->data);
	}

	void leafNodes(Node *root)
	{
		if (!root)
		{
			return;
		}
		if (isLeafNode(root))
		{
			ans.push_back(root->data);
			return;
		}
		leafNodes(root->left);
		leafNodes(root->right);
	}

public:
	vector<int> boundary(Node *root)
	{
		if (!root)
		{
			return {};
		}
		if (isLeafNode(root))
		{
			ans.push_back(root->data);
			return ans;
		}

		ans.push_back(root->data);

		leftNodesWithoutLeaf(root->left);
		leafNodes(root);
		rightNodesWithoutLeaf(root->right);

		return ans;
	}
};