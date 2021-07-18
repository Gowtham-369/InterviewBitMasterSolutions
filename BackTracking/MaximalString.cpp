string ans = "";
void FindMaxLex(int l,int n,int B,string A){
    if(l == n){
        int comp = A.compare(ans);
        // cout<<"string is "<<A<<"\n";
        if(comp > 0){
            ans = A;
        }
        
        return;
    }
    if(B == 0){
        int comp = A.compare(ans);
        // cout<<"string is "<<A<<"\n";
        if(comp > 0){
            ans = A;
        }
        return;
    }
    char maxx = '0';
    for(int j=l+1; j<n; j++){
        maxx = max(maxx,A[j]);
    }
    //saving swaps
    if(maxx > A[l]){
        for(int i=l+1; i<n; i++){
            swap(A[l],A[i]);
            FindMaxLex(l+1,n,B-1,A);
            swap(A[l],A[i]);
        }
    }
    else{
        FindMaxLex(l+1,n,B,A);
    }
}
string Solution::solve(string A, int B) {
    int n = A.size();
    ans = "";
    ans = A;
    FindMaxLex(0,n,B,A);
    return ans;
}
// "7599"
//9975//9957
