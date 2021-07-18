
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    //here we need unique triplets
    vector<vector<int>> sol;
    sort(A.begin(),A.end());
    int n = A.size();
    int low,high,k;
    //duplicates
    // i k j
    // k i j
    for(k = 0; k<n-2; k++){
        while(k>0 && k<n-2 && A[k] == A[k-1]){
            k += 1;
        }
        if(k>=n-2){
            break;
        }
        low=k+1,high=n-1;
        
        while(low<high){
            //avoid duplicates
            //to avoid same nos,skip them
            
            long long sum = (long long)A[low]+(long long)A[high]+(long long)A[k];//may overflow
            if(sum == 0){
                //found triplet
                vector<int> res = {A[k],A[low],A[high]};
                // sort(res.begin(),res.end());
                sol.push_back(res);
                low += 1;
                while(low<high && A[low]==A[low-1]){
                    low += 1;
                }
                // high -= 1;
                // while(low<high && A[high]==A[high+1]){
                //     high -= 1;
                // }
            }
            else if(sum<0){
                low += 1;
            }
            else{
                high -= 1;
            }
        }
    }
    return sol;
}

