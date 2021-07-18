int Solution::singleNumber(const vector<int> &A) {
    int n_bits = 32;
    vector<int> ones(n_bits,0),zeros(n_bits,0);
    int n = A.size();
    for(int i=0; i<n; i++){
        int m = A[i];
        for(int j=0; j<32; j++){
            if((m>>j)&1 == 1){
                ones[j] += 1;
            }
            else{
                zeros[j] += 1;//0 at this position
            }
        }
    }
    int mul = 1,ans = 0;
    for(int i=0; i<32; i++){
        
        // cout<<ones[i]<<" "<<zeros[i]<<"\n";
        if(ones[i]%3 != 0){
            ans += mul;
        }
        else if(zeros[i]%3 !=0){
            ans += 0;
        }
        mul = mul*2;
    }
    return ans;
}
