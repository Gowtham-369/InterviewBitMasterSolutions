int compare(string s1,string s2){
    int n = s1.size(),m = s2.size();
    if(n > m){
        return 1;
    }
    else if(n < m){
        return -1;
    }
    else{
        int len = min(n,m);
        int i;
        for(i=0; i<len; i++){
            if(s1[i] > s2[i]){
                return 1;
            }
            if(s1[i]<s2[i]){
                return -1;
            }
        }
        return 0;
    }
}
int Solution::compareVersion(string A, string B) {
    int n = A.size();
    int m = B.size();
    // int len = min(n,m);
    int i=0,j = 0;
    // while(!(i==n && j==m)){
    while((i<n || j<m)){
        string s1 = "";
        //avoid leading zeros
        while(i<n && (A[i] == '0' || A[i]=='.')){
            i += 1;
        }
        while(i<n && A[i] != '.'){
            s1 += A[i];
            i += 1;
        }
        // i += 1;
        
        string s2 = "";
        //01
        //1
        while(j<m && (B[j] == '0' || B[j]=='.')){
            j += 1;
        }
        while(j<m && B[j] != '.'){
            s2 += B[j];
            j += 1;
        }
        // j += 1;
        
        // int res = s1.compare(s2);
        //lexicographic compare fails
        // A : "4444371174137455"
        // B : "5.168"
        int res = compare(s1,s2);
        if(res == 0){
            continue;
        }
        else if(res>0){
            return 1;
        }
        else{
            return -1;
        }
    }
    return 0;
}
