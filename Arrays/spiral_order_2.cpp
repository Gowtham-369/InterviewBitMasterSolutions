vector<vector<int> > Solution::generateMatrix(int A) {
    int n = A;
    vector<vector<int>> res(n,vector<int>(n));
    int cnt = 1;
    int i,j;
    for(int k=0; k<n/2; k++){
        i = k;
        for(j=k;j<n-k-1; j++){
            res[i][j] = cnt++;
        }
        
        for(i=k;i<n-k-1; i++){
            res[i][j] = cnt++;
        }
        for(j=n-k-1; j>k; j--){
            res[i][j] = cnt++;
        }
        for(i=n-k-1; i>k; i--){
            res[i][j] = cnt++;
        }
    }
    if(n&1 != 0){
        res[n/2][n/2] = cnt;
    }
    return res;
}
