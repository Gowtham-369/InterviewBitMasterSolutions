typedef long long ll;
bool check(vector<int>& b,int n,int m,ll mid){
    int i = 0;
    ll sum = 0;
    int cnt = 1;
    for(; i<n;){
        
        if(sum+b[i]> mid){
            cnt += 1;
            sum = 0;
            if(cnt>m){
                return false;
            }
        }
        else{
            sum += b[i];
            i += 1;
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    int m = B;
    if(n<m){
        return -1;
    }
    ll low = 0;
    ll high = 0;
    ll ans = LLONG_MAX;
    for(int i =0; i<n; i++){
        high += A[i];
    }
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(check(A,n,m,mid)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    
}
