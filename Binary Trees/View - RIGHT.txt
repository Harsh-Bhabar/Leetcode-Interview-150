struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       if(!root){
           return {};
       }
       
       vector<int> ans;
       queue<Node*> q;
       q.push(root);
       
       while(!q.empty()){
           int n = q.size();
           while(n--){
               Node* curr = q.front();  q.pop();
                if(n == 0){
                    ans.push_back(curr->data);
                }
               if(curr->left){
                   q.push(curr->left);
               }
               if(curr->right){
                   q.push(curr->right);
               }
           }
       }
       
       return ans;
    }
};