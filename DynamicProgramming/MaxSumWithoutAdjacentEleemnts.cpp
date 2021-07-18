/*
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int sum1 = 0,sum2 = 0;
    for(int i=0; i<n; i+=2){
        sum1 += max(A[0][i],A[1][i]);
    }
    for(int i=1; i<n; i+=2){
        sum2 += max(A[0][i],A[1][i]);
    }
    return max(sum1,sum2);
}
*/
int Solution::adjacent(vector<vector<int>> &A)
{

    int N = A[0].size();

    if (N == 0)
        return 0;
    if (N == 1)
        return max(A[1][0], A[0][0]);
    int t[N];
    memset(t, 0, sizeof t);
    /*

t[N-1] = max( A[0][N-1] , A[1][N-1] ) ; 

for( int i = N-2 ; i >= 0 ; i-- )
{
    if( i + 2 >= N )
    t[i] = max(  t[i+1] , max( A[1][i] , A[0][i])  );
    
    else 
    t[i] = max( t[i+1] , max( A[1][i] , A[0][i] ) + t[i+2] );
}
 return t[0] ;

}
*/
    t[0] = max(A[1][0], A[0][0]);
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
        {
            t[i] = max(max(A[0][i], A[1][i]), t[i - 1]);
        }
        else
        {
            t[i] = max(max(A[0][i], A[1][i]) + t[i - 2], t[i - 1]);
        }
    }
    return t[N - 1];
}
