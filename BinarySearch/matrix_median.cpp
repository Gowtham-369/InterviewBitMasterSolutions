void merge(vector<int>& v,vector<int> B,int m){
    int n = v.size();
    vector<int> arr(n+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(v[i] <= B[j]){
            arr[k++] = v[i++];
        }    
        else{
            arr[k++] = B[j++];
        }
    }
    while(i<n){
        arr[k++] = v[i++];
    }
    while(j<m){
        arr[k++] = B[j++];
    }
    v.resize(n+m);
    for(int i=0; i<n+m; i++){
        v[i] = arr[i];
    }
}
int Solution::findMedian(vector<vector<int> > &A) {
    
    int r = A.size();
    int c = A[0].size();
    // vector<int> v(A[0].begin(),A[0].end());
    // for(int i=1; i<r; i++){
    //     merge(v,A[i],c);
    // }
    // return v[r*c/2];
    int mn = INT_MAX,mx= INT_MIN;
    for(int i=0; i<r; i++){
        mn = min(mn,A[i][0]);
        mx = max(mx,A[i][c-1]);
    }
    int cnt = (r*c+1)/2;//1 indexing
    int ans = mn;
    while(mn<mx){
        int mid = mn+(mx-mn)/2;
        int num = 0;
        for(int i=0; i<r; i++){
            //less than or equal to that
            num += upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(num<cnt){
            // ans = mid;
            mn = mid+1;
        }
        else{
            mx = mid;
        }
    }
    return mn;
    
}
