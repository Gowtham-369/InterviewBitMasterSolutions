double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(),m = B.size();
    if(n == 0){
        if(m&1 == 1){
            return (double)B[m/2];
        }
        else{
            return (double)(B[m/2]+B[m/2-1])/2.0;
        }
    }
    if(m == 0){
        if(n&1 == 1){
            return (double)A[n/2];
        }
        else{
            return (double)(A[n/2]+A[n/2-1])/2.0;
        }
    }
    int len = n+m;
    int cnt = (len)/2+1;
    int mn = min(A[0],B[0]);
    int mx = max(A[n-1],B[m-1]);
    while(mn<mx){
        int mid = mn+(mx-mn)/2;
        int num = 0;
        num += upper_bound(A.begin(),A.end(),mid)-A.begin();
        num += upper_bound(B.begin(),B.end(),mid)-B.begin();
        //similar to lower_bound but actual median present in the arrays is needed
        //say 4,5 can be medains but 5 is there in array,it is considered
        if(num<cnt){
            mn = mid+1;
        }
        else{
            mx = mid;
        }
    }
    if(len%2 != 0)
        return (double)mn;
    else{
        int med1 = mn;
        cnt -= 1;
        mn = min(A[0],B[0]);
        mx = max(A[n-1],B[m-1]);
        while(mn<mx){
            int mid = mn+(mx-mn)/2;
            int num = 0;
            num += upper_bound(A.begin(),A.end(),mid)-A.begin();
            num += upper_bound(B.begin(),B.end(),mid)-B.begin();
            //similar to lower_bound but actual median present in the arrays is needed
            //say 4,5 can be medains but 5 is there in array,it is considered
            if(num<cnt){
                mn = mid+1;
            }
            else{
                mx = mid;
            }
        }
        int med2 = mn;
        return (double)(med1+med2)/2.0;
    }
    /*
    vector<int> v(len);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(A[i] <= B[j]){
            v[k++] = A[i++];
        }
        else{
            v[k++] = B[j++];
        }
    }
    while(i<n){
        v[k++] = A[i++];
    }
    while(j<m){
        v[k++] = B[j++];
    }
    double ans;
    int mid = len/2;
    if(len%2 == 0){
        ans = (double)(v[mid]+v[mid-1])/2.0;
    }
    else{
        ans = (double)v[mid];
    }
    return ans;
    */
}
