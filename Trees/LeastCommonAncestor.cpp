/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode *root,int target){
    if(root == NULL){
        return false;
    }
    if(root->val == target){
        return true;
    }
    return (find(root->left,target)||find(root->right,target));
}
TreeNode *LCA(TreeNode *root,int t1,int t2){
    if(root == NULL){
        return NULL;
    }
    if(root->val == t1 || root->val == t2){
        return root;
    }
    TreeNode *L = LCA(root->left,t1,t2);
    TreeNode *R = LCA(root->right,t1,t2);
    if(L && R){
        //both sides
        return root;
    }
    // any one side,whichever found first will be our ancestor
    return (L?L:R);
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool f1 = find(A,B);
    bool f2 = find(A,C);
    if(f1==false || f2 == false){
        return -1;
    }
    TreeNode *ans = LCA(A,B,C);
    return ans->val;
}
 
/*
 
void GetPath(TreeNode *root,int target,vector<TreeNode*> &v,int &found){
    if(found){
        return;
    }
    if(root == NULL){
        return;
    }
    v.push_back(root);
    if(root->val == target){
        found = 1;
        return;
    }
    GetPath(root->left,target,v,found);
    GetPath(root->right,target,v,found);
    if(not found){
        v.pop_back();
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    int found = 0;
    vector<TreeNode*> path1,path2; 
    GetPath(A,B,path1,found);
    if(!found){
        return -1;
    }
    found = 0;
    GetPath(A,C,path2,found);
    if(!found){
        return -1;
    }
    int n = path1.size(),m = path2.size();
    int i=0,j=0;
    TreeNode *LCA = NULL;
    while(i<n && j<m){
        if(path1[i] == path2[j]){
            LCA = path1[i];
            i += 1;
            j += 1;
        }
        else{
            break;
        }
    }
    //LCA wont be NULL;
    // if(LCA == NULL){
    //     return
    // }
    return LCA->val;
}
*/