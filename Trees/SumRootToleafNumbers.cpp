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
typedef long long ll;
const ll mod = 1003;

pair<ll,pair<ll,ll>> Traversal(TreeNode *root){
    if(root == NULL){
        return {0,{0,0}};
    }
    ll ans = 0;
    pair<ll,pair<ll,ll>> ans1 = Traversal(root->left);
    pair<ll,pair<ll,ll>> ans2 = Traversal(root->right);
    ans = (ans + ans1.first*(ll)pow(10,ans1.second.first)%mod)%mod;
    ans = (ans + ans1.first*(ll)pow(10,ans1.second.second)%mod)%mod;
    ans = (ans + ans2.first*(ll)pow(10,ans2.second.first)%mod)%mod;
    ans = (ans + ans2.first*(ll)pow(10,ans2.second.second)%mod)%mod;
    return {ans,{ans1.second.second+1,ans2.second.second+1}};
}
void Traversal(TreeNode *root,ll &sum){
    if(root == NULL){
        return;
    }
    Traversal(root->left,sum,mul*10);
    Traversal(root->right,sum,mul*10);
    sum = (sum+root->val*mul%mod)%mod;
}
int Solution::sumNumbers(TreeNode* A) {
    // ll place_value = 1;
    ll sum = 0,mul = 1;
    // pair<ll,pair<ll,ll>> ans = Traversal(A);
    // return ans.first;
    Traversal(A,sum);
    return sum;
}
*/
#define MOD 1003
 
int calc(TreeNode* root, int sum)
{
    if(root==NULL)
        return sum;
 
    sum+=root->val;
 
    if(root->left==NULL && root->right==NULL)
        return sum;
 
    sum = (sum*10)%MOD;
 
    int left_sum = 0;
    if(root->left)
        left_sum = calc(root->left,sum);
    int right_sum = 0;
    if(root->right)
        right_sum = calc(root->right,sum);
 
    return (left_sum + right_sum)%MOD;
}
int Solution::sumNumbers(TreeNode* A) {
    int sum = 0;
    return calc(A,sum);
}
