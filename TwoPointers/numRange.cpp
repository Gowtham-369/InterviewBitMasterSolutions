int Solution::numRange(vector<int> &A, int B, int C) {
    //still O(n**2)
    int n = A.size();
    int cnt = 0;
    /*
    for(int i=0; i<n; i++){
        int sum = A[i];
        if(sum>=B && sum<=C){
            cnt += 1;
        }
        for(int j = i+1; j < n; j++){
            sum += A[j];
            if(sum>=B && sum<=C){
                cnt += 1;
            }
        }
    }
    */
    int j=0,k=0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum > C){
            while(sum>C && k<n){
                sum -= A[k];
                k += 1;
            }
        }
        // [k,i] is <=C
        j = k;
        int temp = sum;
        while(temp>=B && j<n){
            temp -= A[j];
            j += 1;
        }
        
        cnt = cnt+(j-k);
    }
    return cnt;
}
