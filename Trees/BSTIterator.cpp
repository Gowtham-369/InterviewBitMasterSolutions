/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
stack<TreeNode*> st;
void PushLeft(TreeNode *root){
    while(root != NULL){
        st.push(root);
        root = root->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) {
    PushLeft(root);
}


bool BSTIterator::hasNext() {
    return !st.empty();
}

int BSTIterator::next() {
    TreeNode *temp = st.top();
    st.pop();
    PushLeft(temp->right);
    return temp->val;
}
*/
/*
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 
 
 
int cnt;
vector<int> v;
void Traversal(TreeNode *root){
    if(root == NULL){
        return;
    }
    Traversal(root->left);
    v.push_back(root->val);
    Traversal(root->right);
}
BSTIterator::BSTIterator(TreeNode *root) {
    v.erase(v.begin(),v.end());
    cnt = 0;
    Traversal(root);
}


bool BSTIterator::hasNext() {
    cnt += 1;
    if(cnt>(int)v.size()){
        return false;
    }
    else{
        return true;
    }
}


int BSTIterator::next() {
    // cnt += 1;
    if(cnt<=(int)v.size()){
        return v[cnt-1];
    }
    else{
        return 0;
    }
}

