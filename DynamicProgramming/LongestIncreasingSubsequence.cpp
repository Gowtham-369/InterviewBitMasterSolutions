int Solution::lis(const vector<int> &A) {
    int n = A.size();
    if(n == 0){
        return n;
    }
    unordered_map<int,int> mp;
    int ans = 1;
    for(int i=0; i<n; i++){
        mp[i] = 1;//every element is len of 1
        for(int j=i-1; j>=0; j--){
            if(A[j] < A[i]){
                mp[i] = max(mp[i],mp[j]+1);
            }
        }
        ans = max(ans,mp[i]);//max ans ending at this index
    }
    return ans;
}
