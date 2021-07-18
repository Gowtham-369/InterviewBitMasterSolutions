void swap(char& a,char& b){
    char temp = a;
    a = b;
    b = temp;
}
string Solution::solve(string s) {
    //try tp replace least sifgnificant digit to get samllest
    int n = s.size();
    if(n == 0){
        return "-1";
    }
    int i = n-1;
    string ans = "-1";
    //4321
    //9999
    //524321 --> 534221 -- >531224
    while(i>0){
        while(i>0 && s[i-1]>=s[i]){
            i -= 1;
        }
        if(i>0){
            //at i-1,1st lesser found
            //replace it with least greater ele found right
            int j = i;
            while(j<n && s[j]>s[i-1]){
                j += 1;
            }
            swap(s[i-1],s[j-1]);
            //sort from i-1 to n-1
            sort(s.begin()+i,s.begin()+n);
            ans = s;
            break;
        }
    }
    return ans;
    
    
}
