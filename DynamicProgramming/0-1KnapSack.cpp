int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size(),m = C;
    vector<vector<int>> t(n+1,vector<int>(m+1));
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
            else{
                if(B[i-1]<=j){
                    t[i][j] = max(A[i-1]+t[i-1][j-B[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
    return t[n][m];
}
