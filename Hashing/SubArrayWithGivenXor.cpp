int Solution::solve(vector<int> &A, int B) {
    int x = 0,n=A.size();
    map<int,int> mp;
    int ans = 0;
    mp.insert({0,1});//intially xor is 0 and has one occurance,ind is -1
    for(int i=0; i<n; i++){
        x ^= A[i];
        int to_find = x^B;
        auto it = mp.find(to_find);
        if(it != mp.end()){
            ans = ans+it->second;
        }
        mp[x] += 1;
    }
    return ans;
}
