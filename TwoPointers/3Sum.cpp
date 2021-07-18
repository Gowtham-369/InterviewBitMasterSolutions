int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int ans;
    int prev_diff = INT_MAX;
    sort(A.begin(),A.end());
    bool found_exact = false;
    for(int k=0; k<n; k++){
        int target = B-A[k];
        int i=0,j=n-1;
        //int i=k+1;
        while(i<j){
            
            if(i == k){
                //avoid duplicates
                i += 1;
            }
            if(j == k){
                //avoid duplicates
                j -= 1;
            }
            if(i>=j){
                //avoid duplicates
                continue;
            }
            long long int sum = A[i]+A[j];
            if(sum == target){
                found_exact = true;
                int diff = 0;
                if(diff < prev_diff){
                    ans = sum+A[k];
                    prev_diff = diff;
                }
                i += 1;//j -= 1;
                break;
            }
            else if(sum < target){
                int diff = abs(sum+A[k]-B);
                if(diff < prev_diff){
                    ans = sum+A[k];
                    prev_diff = diff;
                }
                i += 1;
            }
            else{
                int diff = abs(sum+A[k]-B);
                if(diff < prev_diff){
                    ans = sum+A[k];
                    prev_diff = diff;
                }
                j -= 1;
            }
        }
        if(found_exact){
            return ans;
        }

    }
    return ans;
    
}
