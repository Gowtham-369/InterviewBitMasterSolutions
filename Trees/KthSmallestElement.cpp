void Inorder(TreeNode *node,vector<int> &v){
    if(node == NULL){
        return;
    }
    Inorder(node->left,v);
    v.push_back(node->val);
    Inorder(node->right,v);
}
void Preorder(TreeNode *node,priority_queue<int> &pq,int k){
    if(node == NULL){
        return;
    }
    // cout<<node->val;
    pq.push(node->val);
    if(pq.size()>k){
        pq.pop();
    }
    Preorder(node->left,pq,k);
    Preorder(node->right,pq,k);
}
int Solution::kthsmallest(TreeNode* A, int k) {
    // vector<int> v;
    // Inorder(A,v);
    // sort(v.begin(),v.end());
    // return v[k-1];
    priority_queue<int> pq;
    Preorder(A,pq,k);
    return pq.top();
}