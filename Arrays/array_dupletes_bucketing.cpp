void swap(int& a,int& b){
    int temp = b;
    b = a;
    a = temp;
}
int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> v(A.begin(),A.end());
    
    int i=0;
    int n=v.size();//n+1 elements
    int dup;
    while(i<=n){
        if(v[i] != i+1){
            //check the element we want to swap with
            if(v[v[i]] == v[i]){
                //duplicate found
                dup = v[i];
                break;
            }
            swap(v[i],v[v[i]]);
        }
        else{
            i += 1;
        }
    }
    return dup;
}
