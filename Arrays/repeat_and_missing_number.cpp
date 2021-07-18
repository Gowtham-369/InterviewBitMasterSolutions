void swap(int& a,int& b){
    int temp = b;
    b = a;
    a = temp;
}
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum  = 0;
    long long squaresum = 0;
    int n = A.size();
    for(int i=0; i<n; i++){
        long long temp = A[i];
        long long temp2 = i+1;
        sum += temp;
        sum -= (temp2);
        squaresum += (temp*temp);
        squaresum -= (temp2*temp2);
    }
    //sum = A-B
    //squaresum = (A+B)(A-B)
    squaresum /= sum;
    int a = (squaresum+sum)/2;
    int b = a-sum;
    b = abs(b);
    a = abs(a);
    return {a,b};
    /*
    vector<int> v(A.begin(),A.end());
    int i =0,n = A.size();
    int dup;
    while(i<n){
        if(v[i] != i+1){
            if(v[i] == v[v[i]-1]){
                dup = v[i];//dup found is A[i]
                i += 1;
                continue;
            }
            swap(v[i],v[v[i]-1]);
        }
        else{
            i += 1;
        }
    }
    int missing;
    for(i=0; i<n; i++){
        if(v[i] != i+1){
            missing = i+1;
            break;
        }
    }
    return {dup,missing};
    */
    
    /*
    long long sum = 0;
    // long long product =1;n!fails for 1e5
    int n = A.size();
    int t_xor = 1;
    for(int i=0; i<n; i++){
        t_xor ^= A[i];
        t_xor ^= (i+1);
        sum += A[i];
    }
    long long n_sum = n*(n+1)/2;
    int diff = (n_sum-sum);
    int a_diff = abs(diff);
    int i;
    for(i=1; i<=n; i++){
        if(i^(i+a_diff) == t_xor){
            break;
        }
    }
    if(diff > 0){
        //no replaced/dup is less than original
        return {i,i+a_diff};
    }
    else{
        // no replced/dup is greater than missing
        return {i+a_diff,i};
    }
    //XOR is bitwise thing,In 2^n combinations, many give same xor value
    */
}
