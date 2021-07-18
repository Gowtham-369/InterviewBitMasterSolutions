bool isPalindrome(string& A,int low,int high){
    while(low<high){
        if(A[low] == A[high]){
            low += 1;
            high -= 1;
        }
        else{
            return false;
        }
    }
    return true;
}
int Solution::solve(string A) {
    int n = A.size();
    int low = 0,high = n-1;
    while(low<high){
        if(A[low] == A[high]){
            low += 1;
            high -= 1;
        }
        else{
            if(isPalindrome(A,low+1,high) || isPalindrome(A,low,high-1)){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    //given itself is a palindrome
    return 1;
    
}
