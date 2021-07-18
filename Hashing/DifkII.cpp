int Solution::diffPossible(const vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    for(int i=0; i<n; i++){
        mp[A[i]] += 1;
    }
    for(int i=0; i<n; i++){
        int target = A[i]+B;
        if(mp.find(target) != mp.end()){
            int len = mp[target];
            if(len > 1){
                return 1;
            }
            else{
                //B == 0
                if(A[i] != target){
                    return 1;
                }
            }
        }
    }
    return 0;
}
