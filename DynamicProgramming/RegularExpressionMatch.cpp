/*
vector<vector<int>> t;
int isMatchUtil(string A,string B,int n,int m){
    if(n==0 and m == 0){
        return t[n][m]=1;
    }
    if(n==0){
        if(B[m-1] == '*'){
            //empty space
            if(t[n][m-1] == -1){
                t[n][m-1] = isMatchUtil(A,B,n,m-1);
            }
            return t[n][m] = t[n][m-1];
        }
        else{
            return t[n][m] = 0;
        }
    }
    if(m == 0){
        return t[n][m]=0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(A[n-1] == B[m-1] || B[m-1]=='?'){
        if(t[n-1][m-1] != -1){
            return t[n][m]=t[n-1][m-1];
        }
        t[n-1][m-1] = isMatchUtil(A,B,n-1,m-1);
        return t[n][m] = t[n-1][m-1];
    }
    else{
        if(B[m-1] == '*'){
            //*->empty
            //*->mulitple chars
            //*->any single char
            // return (isMatchUtil(A,B,n-1,m-1)||isMatchUtil(A,B,n-1,m))||isMatchUtil(A,B,n,m-1);
            if(t[n-1][m-1] == -1){
                t[n-1][m-1] = isMatchUtil(A,B,n-1,m-1);
            }
            if(t[n-1][m] == -1){
                t[n-1][m] = isMatchUtil(A,B,n-1,m);
            }
            if(t[n][m-1] == -1){
                t[n][m-1] = isMatchUtil(A,B,n,m-1);
            }
            return t[n][m]=(t[n-1][m-1]||t[n][m-1]||t[n-1][m]);
        }
        else{
            return t[n][m]=0;
        }
    }
}
int Solution::isMatch(const string A, const string B) {
    int n = A.size(),m = B.size();
    t.erase(t.begin(),t.end());
    t.resize(n+1,vector<int>(m+1,-1));
    return t[n][m]=isMatchUtil(A,B,n,m);
}
*/
int Solution::isMatch(const string a, const string b)
{
    int n = a.length(), m = b.length();
    vector<vector<bool>> v(n + 1, vector<bool>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        v[i][0] = false;
    }
    v[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        v[0][i] = true;
        for (int j = 1; j <= i; j++)
        {
            if (b[j - 1] != '*')
            {
                v[0][i] = false;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1] || b[j - 1] == '?')
            {
                v[i][j] = v[i - 1][j - 1];
            }
            else if (b[j - 1] == '*')
            {
                v[i][j] = v[i - 1][j] || v[i][j - 1];
            }
            else
            {
                v[i][j] = false;
            }
        }
    }
    return v[n][m];
}