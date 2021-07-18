void getLps(vector<int>& lps,string B,int m){
    lps.resize(m);
    lps[0] = 0;
    int len = 0;
    int i=1;
    while(i<m){
        if(B[len]==B[i]){
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i += 1;
            }
        }
    }
    
}
int solveKMP(string A,string B,int n,int m){
    //pattern matching using lps
    vector<int> lps(m);
    getLps(lps,B,m);
    int i=0,j=0;
    int len = 0;
    while(i<n){
        
        if(A[i] == B[j]){
            i += 1;
            j += 1;
        }
        if(j == m){
            //found at i-j
            return (i-j);
            j = lps[j-1];
        }
        else if(i<n && A[i] != B[j]){
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i += 1;
            }
        }
    }
    return -1;
}
int Solution::strStr(const string A, const string B) {
    //check for B in A
    int n = A.size();
    int m = B.size();
    /*
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
    */
    int ans = solveKMP(A,B,n,m);
    return ans;
}
