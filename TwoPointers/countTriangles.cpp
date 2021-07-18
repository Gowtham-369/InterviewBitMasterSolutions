const int mod = 1e9+7;


int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    
    int cnt = 0;
    /*
    //O(n**3)
    int i,j;
    for(int k=0;k<n-2; k++){
        i = k+1;
        j = n-1;
        while(i<j){
            if(A[k]+A[i] > A[j]){
                cnt += 1;
            }
            // if(A[k]+A[i] <= A[j])
            
            // j is fixed
            int l = i+1;
            while(l<j && A[k]+A[l] <= A[j]){
                l += 1;
            }
            if(l < j){
                cnt = (cnt+(j-l)%mod)%mod;
            }
            // i is fixed
            int r = j-1;
            while(i<r && A[k]+A[i] <= A[r]){
                r -= 1;
            }
            if(r>i){
                cnt = (cnt+(r-i)%mod)%mod;
            }
            
            i += 1;
            j -= 1;
        }
    }
    */
    /*
    // O(n**2logn)
    for(int k=0;k<n-2; k++){
        for(int i=k+1; i<n-1; i++){
            int sum = A[k]+A[i];
            int j = lower_bound(A.begin(),A.end(),sum)-A.begin();
            j -= 1;
            if(i<j){
                cnt = (cnt+(j-i)%mod)%mod;
            }
            // [i to j]
        }
    }
    
    return cnt;
    */
    //O(n**2)
    for(int k=n-1; k>=2; k--){
        int l= 0,r = k-1;
        while(l<r){
            if(A[l]+A[r] > A[k]){
                cnt = (cnt+(r-l)%mod)%mod;
                r -= 1;
            }
            else{
                l += 1;
            }
        }
    }
    return cnt;
    
}


