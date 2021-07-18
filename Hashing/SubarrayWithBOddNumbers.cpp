#define deb2(x,y) cout<<#x<<" "<<x<<#y<<" "<<y<<"\n"; 
int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int n = A.size();
    int ans = 0;
    mp.insert({0,1});
    int sum = 0;
    for(int i=0; i<n; i++){
        if(A[i]%2 != 0){
            sum += 1;
        }
        if(mp.find(sum-B) != mp.end()){
            ans += (mp[sum-B]);
        }
        mp[sum] += 1;
    }
    return ans;
}
