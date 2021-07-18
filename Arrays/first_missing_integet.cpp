void swap(int& a,int& b){
    int temp = b;
    b = a;
    a = temp;
}
int Solution::firstMissingPositive(vector<int> &A) {
    // //MEX
    int n = A.size();
    // unordered_set<int> s;
    // for(auto x:A){
    //     s.insert(x);
    // }
    // for(int i=0; i<n; i++){
    //     if(s.count(i+1) == 0){
    //         return i+1;
    //     }
    // }
    // return n+1;
    
    int i = 1;
    while(i<n){
        if((A[i-1] > 0 && A[i-1]<=n) && A[i-1] != i){
            if(A[i-1] == A[A[i-1]-1]){
                i += 1;//dup found
                continue;
            }
            swap(A[i-1],A[A[i-1]-1]);
        }
        else{
            i += 1;
        }
    }
    for(i=0; i<n; i++){
        if(A[i] != i+1){
            return i+1;
        }
    }
    return n+1;
}
