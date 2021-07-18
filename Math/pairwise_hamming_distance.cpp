typedef long long ll;
ll MOD = 1e9+7;
int Solution::hammingDistance(const vector<int> &A) {
    /*
    vector<int> v(A.begin(),A.end());
    ll dist = 0;
    int n = v.size();
    
    for(int loop=1; loop<31;loop++){
        int n_zeros = 0,n_ones =0;
        for(int i=n-1; i>=0 ;i--){
            int last = v[i]%2;
            if(last == 0){
                dist = (dist+n_ones%MOD)%MOD;
                n_zeros += 1;
            }        
            else{
                dist = (dist+n_zeros%MOD)%MOD;
                n_ones += 1;
            }
            v[i] /= 2;
        }
    }
    dist = dist*2%MOD;
    return (int)dist;
    */
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
        int cntBitOne = 0, cntBitZero = 0;
        for(int i = 0; i < inputSize; i++) {
            if (A[i] & (1 << bitPosition)) cntBitOne++;
            else cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod) sum = sum - mod;
    }
    return sum;
}
