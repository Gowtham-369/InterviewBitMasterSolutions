void solve(int i,int n,vector<int> v,vector<int> A,vector<vector<int>> &ans){
    if(i == n){
        ans.push_back(v);
        return;
    }
    int cur = A[i];
    solve(i+1,n,v,A,ans);
    v.push_back(cur);
    solve(i+1,n,v,A,ans);
    v.pop_back();
    return;
}
void solve2(int ind,int n,vector<int> v,vector<int> A,vector<vector<int>> &ans){
    ans.push_back(v);
    for(int i=ind; i<n; i++){
        v.push_back(A[i]);
        solve2(i+1,n,v,A,ans);
        v.pop_back();
    }
    return;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> v = {};
    int n = A.size();
    // solve(0,n,v,A,ans);
    // sort(ans.begin(),ans.end());//lexicogrpahical order
    solve2(0,n,v,A,ans);
    return ans;
}
