int Solution::maxArr(vector<int> &A) {
    int ans;
    int n = A.size();
    int minn1 = INT_MAX,maxx1 = INT_MIN;
    int minn2 = INT_MAX,maxx2 = INT_MIN;
    for(int i=0; i<n; i++){
        minn1 = min(minn1,A[i]+i);
        maxx1 = max(maxx1,A[i]+i);
        minn2 = min(minn2,A[i]-i);
        maxx2 = max(maxx2,A[i]-i);
    }
    int ans1 = maxx2-minn2;
    int ans2 = maxx1-minn1;
    ans = max(ans1,ans2);
    return ans;
}
