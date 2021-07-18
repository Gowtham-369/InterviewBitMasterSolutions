int Solution::solve(string A) {
    map<char,int> mp;
    int n = A.size(),cnt = 0;
    for(int i=0; i<n; i++){
        mp[A[i]] += 1;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second&1 != 0){
            cnt += 1;
        }
        if(cnt>1){
            return 0;
        }
    }
    return 1;
}
