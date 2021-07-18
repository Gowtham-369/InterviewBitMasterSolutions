string Solution::longestCommonPrefix(vector<string> &s) {
    int n = s.size();
    if(n == 1){
        return s[0];
    }
    int min_len = INT_MAX;
    for(int i=0; i<n; i++){
        min_len = min(min_len,(int)s[i].size());
    }

    string res = "";
    int i;
    for(i=0; i<min_len; i++){
        for(int j=0; j<n-1; j++){
            if(s[j][i] != s[j+1][i]){
                return res;
            }
        }
        res += s[0][i];
    }
    return res;
}
