int Solution::sqrt(int A) {
    //r= sqrt(A);
    // int l = 1,r=A;
    int l = 1;
    // int r = 65536;//2**16
    int r = A;
    int mid;
    int ans = 0;
    
    while(l<=r){
        mid = l+(r-l)/2;
        // cout<<"mid "<<mid<<"\n";
        //mid*mid is overflowing here,
        if(mid <= A/mid){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
