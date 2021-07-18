/*
typedef long long int ll;
const ll NN = 500000;
const ll mod = 1000003;
ll fact[NN+7];
void init(ll n=NN, ll m=mod)
{
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=i*fact[i-1]%mod;
}
int Solution::findRank(string A) {
    ll n = A.size();
    ll m = 1000003;
    init(n,m);
    vector<char> v(A.begin(),A.end());
    sort(v.begin(),v.end());
    long long rank = 0;
    for(ll i=0; i<n; i++){
        auto it = find(v.begin(),v.end(),A[i]);
        long long ind = it-v.begin();
        rank = (rank+ind*fact[n-i-1])%mod;
        v.erase(it);
    } 
    rank += 1;
    return (rank+mod)%mod;
    
}
*/
typedef long long int ll;
#define MOD 1000003
 
ll fact(ll n)
{
    if(n<=1)
        return 1;
    else
        return (n%MOD * fact(n-1)%MOD)%MOD;
}
 
 
int Solution::findRank(string A)
{
    ll n = A.length();
    // ll mul = fact(n);
 
    ll rank = 0;
 
    for(int i=0;i<n;i++)
    {
        // mul /= (n-i);
 
        ll cnt=0;
 
        for(int j=i+1;j<n;j++)
            if(A[i]>A[j])
                cnt++;
 
        rank +=(cnt*fact(n-i-1))%MOD;
    }
 
    return (rank+1)%MOD;
}
