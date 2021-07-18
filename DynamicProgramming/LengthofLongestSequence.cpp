int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    if(n == 0){
        return n;
    }
    // unordered_map<int,int> pre,post;
    vector<int> pre(n);
    vector<int> post = vector<int>(n);
    int ans = 1;
    for(int i=0; i<n; i++){
        pre[i] = 1;//every element is len of 1
        for(int j=i-1; j>=0; j--){
            if(A[j] < A[i]){
                pre[i] = max(pre[i],pre[j]+1);
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        post[i] = 1;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[i]){
                post[i] = max(post[i],post[j]+1);
            }
        }
    }
    for(int i=0; i<n; i++){
        ans = max(ans,pre[i]+post[i]-1);
    }
    return ans;

}
