int Solution::diffPossible(vector<int> &A, int B) {
    //hashing
    //binsearch
    //two pointers
    int n = A.size();
    int i=0,j=1;
    while(j<n){
        
        if(A[j]-A[i] < B){
            j += 1;
        }
        else if(A[j]-A[i] > B){
            i += 1;
        }
        else{
            return 1;
        }
        if(i==j){
            j += 1;
        }
    }
    return 0;
}
