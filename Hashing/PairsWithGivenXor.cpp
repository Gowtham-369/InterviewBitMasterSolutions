int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    for(int i=0; i<n; i++){
        mp[A[i]] += 1;
    }
    int cnt = 0;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        int to_find = it->first^B;
        auto it2 = mp.find(to_find);
        if(it2 != mp.end()){
            cnt += 1;
        }
    }
    cnt /= 2;
    return cnt;
}