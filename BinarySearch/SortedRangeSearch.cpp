vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0,high = n-1;
    int mid;
    int upper_bound = -1,lower_bound;
    while(low<=high){
        mid = low+(high-low)/2;
        if(A[mid]<=B){
            low = mid+1;
        }
        else{
            upper_bound = mid;
            high = mid-1;
        }
    }
    if(upper_bound == 0){
        return {-1,-1};
    }
    if(upper_bound == -1){
        upper_bound = n;
    }
    upper_bound -= 1;
    if(A[upper_bound] != B){
        return {-1,-1};
    }
    else{
        //find lower_bound
        lower_bound = 0;
        low = 0,high = n-1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(A[mid]<B){
                lower_bound = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            } 
        }
        return {lower_bound,upper_bound};
    }
    
}
