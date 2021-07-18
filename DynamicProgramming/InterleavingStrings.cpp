////////////////// APPROACH?????///////////
///////////do LCS ofr both strings ///////////
///////////////////////////////////////////

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/interleaving-strings/
*/

int Solution::isInterleave(string A, string B, string C)
{
    int na = A.length();
    int nb = B.length();
    int nc = C.length();
    if(na+nb != nc)
        return 0;
 
    int t[na+1][nb+1];
    memset(t,0,sizeof(t));
    for(int i=0; i<=na; i++){
        for(int j=0; j<=nb; j++){
            if(i==0 && j==0){
                t[i][j] = 1;
            }
            else if(i == 0){
                if(C[j-1] == B[j-1]){
                    t[i][j] = t[i][j-1];
                }
                else{
                    t[i][j] = 0;
                }
            }
            else if(j == 0){
                if(C[i-1] == A[i-1]){
                    t[i][j] = t[i-1][j];
                }
                else{
                    t[i][j] = 0;
                }
            }
            else if(A[i-1] != C[i+j-1] && B[j-1]==C[i+j-1]){
                t[i][j] = t[i][j-1];
            }
            else if(A[i-1] == C[i+j-1] && B[j-1]!=C[i+cj-1]){
                t[i][j] = t[i-1][j];
            }
            else if(A[i-1] == C[i+j-1] && B[j-1]==C[i+j-1]){
                t[i][j] = (t[i-1][j]||t[i][j-1]);
            }
        }
    }
    return t[na][nb];
 
}