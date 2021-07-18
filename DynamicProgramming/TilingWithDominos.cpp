const int mod = 1e9+7;
int Solution::solve(int n) {
    if(n == 0){
        return 0;
    }
    if(n%2 != 0){
        return 0;
    }
    int A[n + 1], B[n + 1];
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = (A[i - 2] + 2 * B[i - 1]%mod)%mod;
        B[i] = (A[i - 1] + B[i - 2])%mod;
    }
    return A[n];
}