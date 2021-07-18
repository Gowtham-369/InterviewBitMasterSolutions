int Solution::isPower(int A) {
    if(A == 1){
        return true;
    }
    //2**32 ,2 is atmost multiplied for 32 times
    int maxx = pow(2,16);//sqaure of num > this > 32 bit interger
    int i = 2;
    while(i<maxx){
        int n = A;
        int cnt = 0;
        while(n>1 && n%i == 0){
            n /= i;
            cnt += 1;
        }
        if(n == 1 && cnt > 1){
            return true;
        }
        else{
            //not a power of i
            i += 1;
        }
    }   
    return false;
}
