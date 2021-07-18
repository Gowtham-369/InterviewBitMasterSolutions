int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int nf = A.size();
    int nd = B.size();
    if(nf == 0){
        return 0;
    }
    int maxCapacity = A[0];
    for(int i=1; i<nf; i++){
        maxCapacity = max(maxCapacity,A[i]);
    }
    long long int t[nd+1][maxCapacity+1];
    memset(t,0,sizeof(t));
    for(int i=0; i<=maxCapacity; i++){
        t[0][i] = INT_MAX;
    }
    for(int i=1; i<=nd; i++){
        for(int j=1; j<=maxCapacity; j++){
            if(B[i-1]<=j){
                t[i][j] = min(t[i-1][j],C[i-1]+t[i][j-B[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i=0; i<nf; i++){
        ans += (t[nd][A[i]]);
    }
    return ans;
}
