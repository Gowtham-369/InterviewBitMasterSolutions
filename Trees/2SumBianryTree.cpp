/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void Traversal(TreeNode *node,int k,map<int,int> &mp,int &found){
    if(node == NULL || found==1){
        return;
    }
    int x = node->val;
    if(mp.find(k-x) != mp.end()){
        if(k-x != x){
            found = 1;
            return;
        }
        else{
            if(mp[k-x] > 1){
                found = 1;
                return;
            }
        }
    }
    mp[x] += 1;
    Traversal(node->left,k,mp,found);
    Traversal(node->right,k,mp,found);
}
void Inorder(TreeNode *node,vector<int> &v){
    if(node == NULL){
        return;
    }
     
    Inorder(node->left,v);
    v.push_back(node->val);
    Inorder(node->right,v);
}
 
 
int Solution::t2Sum(TreeNode* A, int k) {
    /*
    map<int,int> mp;
    int found = 0;
    Traversal(A,k,mp,found);
    return found;
    */
    vector<int> v;
    Inorder(A,v);
    int n = v.size();
    int l = 0,r=n-1;
    int target = k;
    while(l<r){
        if(v[l]+v[r] < target){
            l += 1;
        }
        else if(v[l]+v[r]>target){
            r -= 1;
        }
        else{
            return 1;
        }
        
    }
    return 0;
}
