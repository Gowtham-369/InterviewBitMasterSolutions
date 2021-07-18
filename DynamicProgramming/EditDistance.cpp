// int solve(string A,string B){
//     int n = A[i].size(),m = B.size();
//     if(A[n-1] == B[m-1]){
//         return solve(n-1,m-1);
//     }
//     else{
//         return min(
//         1+solve(n-1,m-1)//replace
//         1+solve(n,m-1)//insert
//         1+solve(n-1,m)//delete
//         );
//     }
// }
int solve(string A,string B){
    int n = A.size(),m = B.size();
    
    vector<vector<int>> t(n+1,vector<int>(m+1,0));
    
    for(int i=0; i<n+1; i++){
        t[i][0] = i;//delete
    }
    for(int j=0; j<m+1; j++){
        t[0][j] = j;//insert
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(A[i-1] == B[j-1]){
                t[i][j] = t[i-1][j-1];
            }
            else{
                t[i][j] = 1+min(t[i-1][j-1],min(t[i][j-1],t[i-1][j]));
            }
        }
    }
    return t[n][m];
}
int Solution::minDistance(string A, string B) {
    int ans = solve(A,B);
    return ans;
}
