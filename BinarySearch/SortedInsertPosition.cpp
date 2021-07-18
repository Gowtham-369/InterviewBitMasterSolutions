int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    //STL lower_bound would act as same
    int n = (int)A.size();
    int low = 0,high = n-1;
    int ans = -1;//compulsory for <= bin search to n-1
    while(low <= high){
        int mid = low+(high-low)/2;
        if(A[mid]<B){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    if(ans == -1){
        ans = n;
    }
    return ans;
}
