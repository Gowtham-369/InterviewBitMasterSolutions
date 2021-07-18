int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    int i = 0;
    while(i<n){
        int cur = A[i];
        while(i<n && A[i] == cur){
            i += 1;
        }
        int n_greater = n-i;
        if(cur == n_greater){
            return 1;
        }
    }
    return -1;
}
