int solve(int A,int B){
    // if(A == 0){
    //     return B;
    // }
    // if(B == 0){
    //     return A;
    // }
    // return solve(A-1,B)+solve(A,B-1);
    /*
    vector<vector<int>> t(A+1,vector<int>(B+1));
    for(int i=1; i<=A; i++){
        for(int j=1; j<=B; j++){
            if( i ==1){
                t[i][j] = 1; 
            }
            if(j == 1){
                t[i][j] = 1;
            }
            else{
                t[i][j] = t[i-1][j]+t[i][j-1];
            }
        }
    }
    return t[A][B];
    */
    int n = A;
    int m = B;
    // int ans = fact(n+m-2)/fact(n-1)*fact(m-1);
    // We have to calculate m+n-2 C n-1 here
    // which will be (m+n-2)! / (n-1)! (m-1)!
    int ans = 1;
    for (int i = n; i <= (m + n - 2); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return ans;
}
int Solution::uniquePaths(int A, int B) {
    return solve(A,B);
}
