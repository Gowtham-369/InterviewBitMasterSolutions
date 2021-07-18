typedef long long ll;
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n = A.size();
    int res = INT_MIN;
    for(int i=0; i<n; i++){
        map<pair<int,int>,int> mp;
        int overlap = 0,vertical=0,cnt = 0;
        for(int j=i+1; j<n; j++){
            if(A[i]==A[j] && B[i]==B[j]){
                overlap += 1;
            }
            else if(A[i] == A[j]){
                vertical += 1;
            }
            else{
                int xdiff = A[j]-A[i];
                int ydiff = B[j]-B[i];
                int g = gcd(xdiff,ydiff);
                xdiff /= g;
                ydiff /= g;
                mp[{ydiff,xdiff}] += 1;
                cnt = max(cnt,mp[{ydiff,xdiff}]);
            }
        }
        //vertical case
        cnt = max(cnt,vertical);
        res = max(res,cnt+overlap+1);
    }
    return (res==INT_MIN?0:res);
}
/*
    int ans = INT_MIN;
    if(n<=1){
        return n;
    }
    map<pair<ll,ll>,int> mp2; 

    for(int i=0; i<n; i++){
        mp2[{A[i],B[i]}] += 1;
    }
    int m = mp2.size();
    if(m == 1){
        return mp2.begin()->second;
    }
    for(auto it1=mp2.begin(); it1 != mp2.end() ;it1++){
        auto it2 = it1;
        it2++;
        map<pair<ll,ll>,int> mp;
        int cnt = 0;
        for(; it2 != mp2.end(); it2++){
            int num = it2->first.second-it1->first.second;//y2-y1
            int denum = it2->first.first-it1->first.first;//x2-x1
            ll x = gcd(num,denum);
            if(x != 0){
                num /= x;
                denum /= x;
            }
            mp[{num,denum}] += it2->second;
        }
        for(auto it:mp){
            // deb2(it1->first,it1->second);
            // deb(it.second);
            cnt = max(cnt,it.second);
        }
        cnt += (it1->second);//adding points pointed by it1
        ans = max(ans,cnt);
    }
    
    return (ans==INT_MIN?0:ans);
    */