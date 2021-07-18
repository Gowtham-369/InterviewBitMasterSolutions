/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void LevelOrder(TreeLinkNode *&root){
    if(root == nullptr){
        return;
    }
    queue<TreeLinkNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        TreeLinkNode *prev = q.front();
        q.pop();
        if(prev->left){
            q.push(prev->left);
        }
        if(prev->right){
            q.push(prev->right);
        }
        for(int i=1; i<n;i++){
            TreeLinkNode *curr = q.front();
            q.pop();
            prev->next = curr;
            curr = prev;
            if(prev->left){
                q.push(prev->left);
            }
            if(prev->right){
                q.push(prev->right);
            }
        }
        
    }
}
void Solution::connect(TreeLinkNode* A) {
    LevelOrder(A);
}
