int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<A[i].size(); j++){
            if(i && A[i][j]){
                A[i][j] += A[i-1][j];
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        sort(A[i].begin(),A[i].end());
        for(int j=0; j<A[i].size(); j++){
            int temp = A[i][j]*((int)A[i].size()-j);
            ans = max(ans,temp);
        }
    }
    return ans;
}
