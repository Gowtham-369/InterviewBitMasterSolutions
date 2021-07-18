/*
map<string,int> mp;
int isScrambleVersion(string A,string B){
    int n = A.size();
    int m = B.size();
    if(A == B){
        return 1;
    }
    if(n<=1){
        return 0;
    }
    // if(n != m){
    //     return 0;
    // }
    string key = A+"_";
    key += B; 
    if(mp.find(key)!=mp.end())
    {
        return mp[key];
    }
    for(int len = 1; len<n; len++){
        int ans1 = isScrambleVersion(A.substr(0,len),B.substr(0,len));
        int ans2 = isScrambleVersion(A.substr(len),B.substr(len));
        int ans3 = isScrambleVersion(A.substr(0,len),B.substr(n-len,len));
        int ans4 = isScrambleVersion(A.substr(len),B.substr(0,n-len));
        if((ans1 && ans2) || (ans3 && ans4)){
            return mp[key] = 1;
        }
    }
    return mp[key]=0;
}
int Solution::isScramble(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    if(n != m){
        return 0;
    }
    mp.clear();
    return isScrambleVersion(A,B);
}
*/
map<pair<string,string>,int> mp;
int isScrambleVersion(string A,string B){
    int n = A.size();
    int m = B.size();
    if(n==1){
        if(A[0] == B[0]){
            return mp[{A,B}] = 1;
        }
        else{
            return mp[{A,B}] = 0;
        }
    }
    // if(n != m){
    //     return 0;
    // }
    for(int len = 1; len<n; len++){
        string s1=A.substr(0,len),s2 = B.substr(0,len);
        int ans1; 
        if(mp.find({s1,s2}) != mp.end()){
            ans1 = mp[{s1,s2}];
        }
        else{
            ans1 = isScrambleVersion(s1,s2);
            mp[{s1,s2}] = ans1;
        }
        s1 = A.substr(len);s2 = B.substr(len);
        int ans2;
        if(mp.find({s1,s2}) != mp.end()){
            ans2 = mp[{s1,s2}];
        }
        else{
            ans2 = isScrambleVersion(s1,s2);
            mp[{s1,s2}] = ans2;
        }
        s1 = A.substr(0,len);s2 = B.substr(n-len,len);
        int ans3;
        if(mp.find({s1,s2}) != mp.end()){
            ans3 = mp[{s1,s2}];
        }
        else{
            ans3 = isScrambleVersion(s1,s2);
            mp[{s1,s2}] = ans3;
        }
        s1 = A.substr(len);s2 = B.substr(0,n-len);
        int ans4;
        if(mp.find({s1,s2}) != mp.end()){
            ans4 = mp[{s1,s2}];
        }
        else{
            ans4 = isScrambleVersion(s1,s2);
            mp[{s1,s2}] = ans4;
        }
        if((ans1 && ans2) || (ans3 && ans4)){
            return mp[{A,B}] = 1;
        }
    }
    return mp[{A,B}]=0;
}
int Solution::isScramble(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    if(n != m){
        return 0;
    }
    mp.clear();
    return isScrambleVersion(A,B);
}