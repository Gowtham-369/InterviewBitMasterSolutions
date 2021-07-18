vector<vector<int> > Solution::solve(int n) {
    if(n == 0){
        return {};
    }
    if(n == 1){
        return {{1}};
    }
    if(n == 2){
        return {{1},{1,1}};
    }
    vector<vector<int>> res(n);
    res[0] = {1};
    res[1] = {1,1};
    for(int i=2; i<n; i++){
        int r = i+1;
        vector<int> v(r);
        v[0] = 1;//insert 1 at beginning
        for(int j=1;j<i; j++){
            v[j] = (res[i-1][j]+res[i-1][j-1]);
        }
        v[r-1] = 1;//insert at end also
        res[i] = v;
    }
    return res;
}
