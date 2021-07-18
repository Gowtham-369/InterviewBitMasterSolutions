const int mod = 1e9+7;
int Solution::solve(int A) {
    int ans = 0;
    int mul = 2;
    int num = A;
    int m = (num-0)+1;
    while(mul<2*m){
        int q = m/mul;
        int r = m%mul;
        int ones_in_segment = mul/2;//zeros_in_segment == ones_in_segemnt
        int ones = (ones_in_segment*q%mod);
        //q zeros and q ones
        ans = (ans+ones)%mod;
        if(r != 0 && r>ones_in_segment){
            ans = (ans+(r-ones_in_segment))%mod;
        }
        mul *= 2;
    }
    return ans;
}
//1