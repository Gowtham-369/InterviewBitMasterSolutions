#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n"

int Solution::lengthOfLongestSubstring(string A) {

    int n = A.size();
    int i=0;
    map<char,int> mp;
    int prev_start=0,cur_start=0;
    int cnt = 0,ans = 0;
    while(i<n){
        char cur_char = A[i];
        auto it = mp.find(cur_char);
        if(it == mp.end()){
            mp[cur_char] = i;
            cnt += 1;
            ans = max(ans,cnt);
        }
        else{
            prev_start = cur_start;
            cur_start = it->second+1;
            //remove all chars in map from prev_start to cur_start
            for(int j=prev_start; j<cur_start; j++){
                mp.erase(A[j]);
            }
            //update cur_char index
            mp[cur_char] = i;
            cnt = i-cur_start+1;//cur window is [cur_start,i]
            // deb2(j,cnt);
        }
        // deb2(i,ans);
        i += 1;
    }
    return ans;
}
