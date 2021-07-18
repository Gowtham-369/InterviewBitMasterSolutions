int Solution::lengthOfLastWord(const string A) {
    int n = A.size();
    /*
    int i=0;
    string last = "";
    string s = "";
    while(i<n){
        while(i<n && A[i] != ' '){
            s += A[i];
            i += 1;
        }
        if(i<n){
            // "hello world   "
            if((int)s.size()>0)
                last = s;
            s = "";
            i += 1;
        }
    }
    if((int)s.size()>0)
        last = s;
    int ans = last.size();
    return ans;
    */
    stringstream ss;
    ss<<A;
    string word,last;
    while(ss>>word){
        last = word;
    }
    return (int)last.size();
}

// #include <iostream>
// #include <sstream>
