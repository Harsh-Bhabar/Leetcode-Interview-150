struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   
   if(!root){
       return {};
   }
   
   vector<int> ans;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();
       bool firstNode = true;
       while(n--){
           Node* curr = q.front();  q.pop();
           if(firstNode){
               ans.push_back(curr->data);
               firstNode = false;
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