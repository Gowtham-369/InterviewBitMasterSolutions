typedef long long ll;

bool check(vector<int>& C,int m,int mid,int n,ll max_e){
    // ll max_ele = *max_element(C.begin(),C.end());
    if(mid < max_e){
        return false;
    }
    ll i = 0;
    ll sum = 0;
    ll cnt = 1;
    for(;i<n;){
        if((sum+C[i]) > mid){
            sum = 0;
            cnt += 1;
        }
        else{
            sum += C[i];
            i+=1;
        }
    }
    if(cnt <= m){
        return true;
    }
    else{
        return false;
    }
    
}
int Solution::paint(int A, int B, vector<int> &C) {
    ll mod = 10000003;
    ll low = 0;
    ll high = 0;
    ll n = C.size();
    //using all painters is better than other cases
    ll max_e = LLONG_MIN;
    for(ll i=0; i<n; i++){
        max_e = max(max_e,(ll)C[i]);
        high += C[i];
    }
    //high is max time taken
    ll ans = LLONG_MAX;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(C,A,mid,n,max_e)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans*B%mod;
}
