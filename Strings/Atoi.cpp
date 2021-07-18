int Solution::atoi(const string A) {
    int n = A.size();
    int i = 0;
        
    //for left whitespaces
    while(i<n && A[i] == ' '){
        i += 1;
    }
    //checkpoint
    if(i == n){
        return 0;
    }
    if(!((A[i]=='+') || (A[i] == '-') || (A[i]>='0' && A[i]<='9'))){
        //random char like U,V.. before num
        return 0;
    }

    
    bool neg=false;
    if(A[i] == '+'){
        neg = false;
        i += 1;
    }
    if(A[i] == '-'){
        neg = true;
        i += 1;
    }
    
    //it is a number now
    string res = "";
    while(i<n && (A[i]>='0' && A[i]<='9')){
        res += A[i];
        i += 1;
    }
    //ignores buffers or reached limit
    //now convert to int checking overflows
    int num = 0;
    int len = res.size();
    for(int j=0; j<len; j++){
        // cout<<"num "<<num<<"\n";
        int x = res[j]-'0';
        if(neg){
            if(num-1>INT_MAX/10){
                return INT_MIN;
            }
        }
        else{
            if(num>INT_MAX/10){
                return INT_MAX;
            }
        }
        num = num*10;
        if(neg){
            if(num-1>INT_MAX-x){
                return INT_MIN;
            }
        }
        else{
            if(num>INT_MAX-x){
                return INT_MAX;
            }
        }
        num += x;
    }
    if(neg){
        return -num;
    }
    else{
        return num;
    }
    
    
}
