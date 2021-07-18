int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int minsteps = 0;
    int n = A.size();
    for(int i=0; i<n-1; i++){
        int steps = max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
        minsteps += steps;
    }
    return minsteps;
}
