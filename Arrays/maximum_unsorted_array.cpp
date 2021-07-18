vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> v(A.begin(),A.end());
    sort(v.begin(),v.end());
    int n = A.size();
    int l=0,r=0;
    for(l=0; l<n; l++){
        if(v[l]!=A[l]){
            break;
        }
    }
    for(r=n-1; r>=0; r--){
        if(v[r] != A[r]){
            break;
        }
    }
    
    if(l>r){
        return {-1};
    }
    else{
        return {l,r};
    }
}
