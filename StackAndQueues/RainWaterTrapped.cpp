int Solution::trap(const vector<int> &A) {
    //postmax and premax
    int n = A.size();
    vector<int> postmax(n+1);
    postmax[n] = INT_MIN;
    for(int i=n-1; i>=0; i--){
        postmax[i] = max(A[i],postmax[i+1]);
    }
    int pre_max = INT_MIN;
    int ans = 0;
    for(int i=0; i<n; i++){
        pre_min = max(pre_max,A[i]);
        int min_height = min(pre_max,postmax[i]);
        int water_trapped_at_this_tower = (min_height-A[i]);
        // cout<<water_trapped_at_this_tower<<"\n";
        ans = ans+water_trapped_at_this_tower;
    }
    return ans;
}
