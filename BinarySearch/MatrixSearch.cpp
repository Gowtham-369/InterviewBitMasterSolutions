int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    //lower_bound in first coloumn
    int l =0,r = n-1;
    int mid;
    int row = -1;
    while(l<=r){
        mid = l+(r-l)/2;
        if(A[mid][0]<=B){
            l = mid+1;
        }
        else{
            row = mid;
            r = mid-1;
        }
    }
    if(row == 0){
        //first row itself is greater
        return 0;
    }
    if(row == -1){
        row = n;
    }
    //found upper_bound
    row -= 1;
    // check in row
    l = 0;
    r = A[row].size();
    while(l<=r){
        mid = l+(r-l)/2;
        if(A[row][mid] == B){
            return 1;
        }
        else if(A[row][mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return 0;
}
