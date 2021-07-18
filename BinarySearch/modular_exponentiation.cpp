int Solution::pow(int x, int n, int mod) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //efficient approach with trivial cases
    
    if(x == 0){
        return 0;
    }
    if(n == 0){
        return 1%mod;
    }
    //using long long saving us from overflow
    long long int res = 1,base = x;
    while(n>0){
        
        if(n&1){
            res = res*base%mod;
        }
        n /= 2;
        base = base*base%mod;
        // cout<<" res "<<res<<"\n";
    }
    if(res < 0){
        res = (res+mod)%mod;
    }
    return res;
}
