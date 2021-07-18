int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0,high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[0]<=A[mid]){
            //left of mid is sorted
            if(A[0]<=B && B<A[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            //right from mid is sorted
            if(A[mid]<B && B<=A[n-1]){
                low = mid+1;
            }  
            else{
                high = mid-1;
            }
        }
    }
    return -1;
    /*
    //O(n)
    int i = 0;
    int ind = -1;
    while(i<n-1 && A[i]<=A[i+1]){
        if(A[i] == B){
            ind = i;
            break;
        }
        i += 1;
    }
    if(ind != -1){
        return ind;
    }
    //else
    //from i+1 to n-1,it is another sorted array
    int l = i+1,r=n-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(A[mid] == B){
            ind = mid;
            break;
        }
        else if(A[mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ind;
    */
}
