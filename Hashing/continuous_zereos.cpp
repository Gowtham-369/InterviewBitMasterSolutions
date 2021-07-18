typedef long long ll;
vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    ll sum = 0;
    map<ll,ll> mp;
    vector<int> res;
    ll start,len = 0;
    mp.insert({0,-1});
    //sum == 0 at some times
    for(int i=0; i<n; i++){
        sum += A[i];
        if(mp.find(sum) != mp.end()){
            // [i+1,j] is 
            int j = mp[sum];
            if(len < i-j){
                start = j+1;
                len = i-j;
            }
        }
        else{
            mp[sum] = i;
        }
        
    }
    if(len>0){
        res.assign(A.begin()+start,A.begin()+start+len);
    }
    return res;
}
