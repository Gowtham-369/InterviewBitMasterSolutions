#define MOD 1000000007
/*
int Solution::chordCnt(int n)
{
    long long int dp[n+1];
 
    dp[0] = dp[1] = 1;
 
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
 
        for(int j=0;j<i;j++)
            dp[i] = (dp[i] + (dp[j]*dp[i-j-1])%MOD)%MOD;
    }
    return dp[n];
}
*/
int Solution::chordCnt( int A){
 
    // n = no of points required
    int n = 2 * A;
     
    // dp array containing the sum
    long long int dpArray[n + 1]={ 0 };
    dpArray[0] = 1;
    dpArray[2] = 1;
    for (int i=4;i<=n;i+=2){
        for (int j=0;j<i-1;j+=2){
             
            dpArray[i] =(dpArray[i]+(dpArray[j]*dpArray[i-2-j])%MOD)%MOD;
        }
    }
 
    // returning the required number
    return dpArray[n];
}