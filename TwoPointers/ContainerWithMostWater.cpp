int Solution::maxArea(vector<int> &A) {
    //not histogram area
    int n = A.size();
    int l = 0,r = n-1;
    int ans = 0;
    while(l < r){
        if(A[l]<=A[r]){
            int area = A[l]*(r-l);
            ans = max(ans,area);
            l += 1;
        }
        else{
            int area = A[r]*(r-l);
            ans = max(ans,area);
            r -= 1;
        }
    }
    return ans;
}
