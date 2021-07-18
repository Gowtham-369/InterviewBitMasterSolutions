vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    vector<int> res(n);
    
    for(int i=1; i<n; i+=2){
        //i == n-1 in even case
        res[i-1]= A[i];
    }
    for(int i=0; i<n; i+=2){
        if(i == n-1){
            //n odd case
            res[i] = A[i];
        }
        else{
            res[i+1] = A[i];
        }
    }
    return res;
}
