int Solution::strStr(const string A, const string B) {
    //ccheck for B in A
    int n = A.size();
    int m = B.size();
    if(n == 0 || m == 0){
        return -1;
    }
    int i = 0;
    for(;i<n; i++){
        if(A[i] == B[0]){
            int j = 0;
            while(j<m && i+j<n && A[i+j]==B[j]){
                j += 1;
            }
            if(j == m){
                return i;
            }
        }
    }
    return -1;
    
}
