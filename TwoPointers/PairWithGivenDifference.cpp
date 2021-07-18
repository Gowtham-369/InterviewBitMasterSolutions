/*
int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    for(int i=0; i<n; i++){
        mp[A[i]] += 1;
    }
    for(int i=0; i<n; i++){
        int target = A[i]-B;
        if(mp.find(target) != mp.end()){
            if(target == A[i]){
                if(mp[A[i]] > 1){
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    int i=0,j=1;
    if(B > 0){
        while(j<n){
            if(i == j){
                j += 1;
                continue;
            }
            if(A[j]-A[i] == B){
                return 1;
            }
            else{
                if(A[j]-A[i] > B){
                    i += 1;
                }
                else{
                    j += 1;
                }
            }
        }
    }
    else{
        i = n-1;
        j = n-2;
        while(j>=0){
            if(i == j){
                j -= 1;
                continue;
            }
            if(A[j]-A[i] == B){
                return 1;
            }
            else{
                if(A[j]-A[i] > B){
                    j -= 1;
                }
                else{
                    i -= 1;
                }
            }
        }
    }
    return 0;
}