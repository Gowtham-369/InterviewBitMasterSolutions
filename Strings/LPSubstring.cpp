string solve(string A,int n){
    
    vector<vector<int>>t(n,vector<int>(n,0));
    int max_len = 1,start=0;
    for(int i=0; i<n; i++){
        t[i][i] = 1;
    }
    for(int i=0; i<n-1; i++){
        if(A[i] == A[i+1]){
            t[i][i+1] = 1;
            start = i;
            max_len = 2;
        }
    }
    for(int i=3; i<n; i++){
        for(int j=0; j<n-i+1; j++){
            int k =  j+i-1;
            if(t[j+1][k-1] == 1 && A[j] == A[k]){
                t[j][k] = 1;
                if(i > max_len){
                    max_len = i;
                    start = j;
                }
                // max_len = max(max_len,t[i][j]);
            }
        }
    }
    string ans = A.substr(start,max_len);
    return ans;
}
string solve2(string A,int n){
    int max_len = 1;
    int start = 0;
    for(int i=0; i<n; i++){
        //at some center point i
        
        int low = i-1;
        int high = i;
        //even len palindromes
        while(low>=0 and high<n and A[low]==A[high]){
            if(max_len < (high-low+1)){
                max_len = high-low+1;
                start = low;
            }
            low -= 1;
            high += 1;
        }
        //odd length palindromes
        low = i-1;
        high = i+1;
        while(low>=0 && high<n && A[low]==A[high]){
            if(max_len < (high-low+1)){
                max_len = high-low+1;
                start = low;
            }
            low -= 1;
            high += 1;
        }
    }
    string ans = A.substr(start,max_len);
    return ans;
}
string Solution::longestPalindrome(string A) {
    //my idea is get longest common substring in A and rev(A)
    // string B(A.begin(),A.end());
    // reverse(B.begin(),B.end());
    int n = A.size();
    // string ans = LCS(A,B,n);
    // string ans = solve(A,n);//O(n**2) space and time
    string ans = solve2(A,n);//O(n**2) time only
    return ans;
}
