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

 // RECURSIVE 
class Solution {
public:
    vector<int> ans; 

    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;    
    }
};

// ITERATIVE

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            
            TreeNode* temp = st.top(); st.pop();
            ans.push_back(temp->val);

            curr = temp->right;
        }

        return ans;
    }
};