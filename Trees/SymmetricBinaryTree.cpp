/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode *root1,TreeNode *root2,int &ok){
    if(root1== NULL && root2 == NULL){
        return;
    }
    if(!ok){
        return;
    }
    else if(root1 == NULL){
        ok = 0;
        return;
    }
    else if(root2 == NULL){
        ok = 0;
        return;
    }
    else{
        if(root1->val == root2->val){
            solve(root1->left,root2->right,ok);
            solve(root1->right,root2->left,ok);
        }
        else{
            ok = 0;
            return;
        }
    }
}
int Solution::isSymmetric(TreeNode* A) {
    int ok = 1;
    solve(A->left,A->right,ok);
    return ok;
}
