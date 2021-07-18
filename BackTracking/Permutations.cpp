void solve(vector<int> A,vector<vector<int>> &ans,int l,int n){
    if(l == n){
        ans.push_back(A);
        return;
    }
    for(int i=l; i<n ;i++){
        swap(A[l],A[i]);
        solve(A,ans,l+1,n);
        swap(A[l],A[i]);
    }
}
void solve2(vector<int> &v,set<int> &s,vector<vector<int>> &ans){
    if((int)s.size() == 0){
        ans.push_back(v);
        return;
    }
    for(auto it=s.begin();it != s.end(); it++){
        int cur = *it;
        v.push_back(cur);
        s.erase(cur);
        solve2(v,s,ans);
        s.insert(cur);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    int n = A.size();
    // solve(A,ans,0,n);
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }
    vector<int> v;
    solve2(v,s,ans);
    return ans;
}
