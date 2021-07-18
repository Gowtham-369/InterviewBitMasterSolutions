vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    int n = A.size();
    for(int i=0; i<n; i++){
        auto it = std::find(res.begin(),res.end(),A[i]);
        if(it != res.end()){
            int ind = it-res.begin();
            res[ind] = A[i]+1;
        }
        res.push_back(A[i]);
    }
    return res;
}
/*
vector<int> Solution::solve(vector<int> &A) {
    map<int,int> mp;
    int n = A.size();
    for(int i=0; i<n; i++){
        if(mp[A[i]] != 0){
            int x = A[i];
            mp[x] -= 1;//reduce its occurence
            x += 1;
            mp[x] += 1;//inc others occurence
        }
        mp[A[i]] += 1;
    }
    vector<int> res;
    for(auto it:mp){
        int cnt = it.second;
        int ele = it.first;
        while(cnt>0){
            res.push_back(ele);
            cnt -= 1;
        }
    }
    return res;
}
*/
