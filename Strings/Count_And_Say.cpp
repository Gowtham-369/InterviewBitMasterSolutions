string Solution::countAndSay(int n) {
    
    string res = "1";
    while(n>1){
        
        string cur = "";
        int m = res.size();
        int i = 0;
        for(;i<m; i++){
            int cnt = 1;
            while(i<m-1 && res[i] == res[i+1]){
                i += 1;
                cnt += 1;
            } 
            // cur += to_string(cnt);
            cur += char('0'+cnt);
            cur += res[i];
        }
        res = cur;
        n -= 1;
    }
    return res;
}
