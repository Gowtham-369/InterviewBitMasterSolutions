string Solution::convertToTitle(int A) {
    string res = "";
    map<int,char> mp;
    char start = 'A';
    for(int i=1; i<=26; i++){
        mp[i%26] = start;
        start += 1;
    }
    while(A>0){
        int rem = A%26;
        res += mp[rem];
        A /= 26;
        if(rem == 0){
            A -= 1;//shifting one 26 to units place
        }
    }
    // while(A>0){
    //     int rem = A%26;
    //     if(rem == 0){
    //         res += ('Z');
    //         A /= 26;
    //         A -= 1;//shifting one 26 to units place
    //     }
    //     else{
    //         res += mp[rem];
    //         A /= 26;
    //     }
    // }
    reverse(res.begin(),res.end());
    return res;
}
