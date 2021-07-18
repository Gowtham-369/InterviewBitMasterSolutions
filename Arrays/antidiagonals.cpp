vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    
    //observe diagonals have i+j value same
    int m = n*2;
    vector<vector<int>> res(m-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[i+j].push_back(A[i][j]);
        }
    }
    return res;
    
    //upper diagonal and diagonal
    /*
    vector<vector<int>> res;
    for(int k=0; k<n; k++){
        int j = k;
        vector<int> v;
        for(int i=0; i<=k && j>=0; i++){
            // cout<<A[i][j];
            v.push_back(A[i][j]);
            j -= 1;
        }
        res.push_back(v);
    }
    //lower diagonal
    for(int k=n-1; k>0; k--){
        int i = n-k;
        vector<int> v;
        for(int j=n-1; j>=(n-k) && i<n; j--){
            v.push_back(A[i][j]);
            i += 1;
        }
        res.push_back(v);
    }
    return res;
    */
}
