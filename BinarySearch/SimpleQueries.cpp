int mod = 1e9+7;
typedef long long ll;
int product_of_divisors(int n){
    long long res = 1;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            res = res*i%mod;
            int q = n/i;
            if(q != i){
                res = res*q%mod;
            }
        }
    }
    return (int)res;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    //subarrys in O(n**2)
    
    // 3 4 6 7
    // [1 2 3 4]
    // 6 7 4 3
    // [6 67 674 6743 7 74 743 4 43 3]
    
    int n = A.size();
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int maxx = A[i];
        mp[maxx] += 1;
        for(int j=i+1; j<n; j++){
            maxx = max(maxx,A[j]);
            mp[maxx] += 1;
        }
    }
    vector<int> v;
    
    for(auto it=mp.begin(); it!=mp.end(); it++){
        int x = it->first,cnt = it->second;
        int prod = product_of_divisors(x);
        while(cnt>0){
            v.push_back(prod);
            cnt -= 1;
        }
    }
    
    sort(v.begin(),v.end(),greater<int>());
    // for(auto e:v){
    //     cout<<e<<" ";
    // }
    // cout<<"\n";
    int len = B.size();
    for(int i=0; i<len; i++){
        B[i] = v[B[i]-1];
    }
    return B;
}
/*
void put_max(vector<pair<int,int>> & v,int l,int r){
    long long mod = 1e9+7;
    stack<pair<int,int>> st;
    for(int i=l;i<=r;i++){
        while(st.size() && (v[i].first >= st.top().first)){
            st.pop(); 
        }
        v[i].second = st.empty() ? (i+1) : (i - st.top().second);
        st.push({v[i].first,i});
    }
    
    while(st.size())
        st.pop();
        
    for(int i=r;i>=l;i--){
        while(st.size() && v[i].first > st.top().first){
            st.pop();
        }
        int gt = r - i + 1;
        if(st.size()){
            gt = st.top().second - i;
        }
        v[i].second = (v[i].second * gt) % mod;
        st.push({v[i].first,i});
    }
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> v(A.size()),q;
    for(int i=0;i<A.size();i++){
        v[i] = {A[i],0};
    }
    put_max(v,0,A.size()-1);
    // for(auto & i:v){
    //     // cout << i.first << "," << i.second << " ";
    // }
    // cout << endl;
    long long mod = 1e9+7;
    int id = 1;
    for(auto & pr:v){
        int ele = pr.first;
        long long num=1;
        int i;
        for(i=1;i*i<ele;i++){
            if(ele%i==0){
                num = (num * i)%mod;
                num = (num * (ele/i))%mod;
            }
        }
        if((i*i)==ele)
            num = (num * i)%mod;
        pr.first = num;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<B.size();i++){
        q.push_back({B[i],i});
    }
    sort(q.begin(),q.end());
    long long ind = 0,mind=v[0].second;
    for(auto & i:q){
        // cout << i.first << "," << i.second << " ";
        while(i.first > mind){
            mind+=v[++ind].second;
        }
        i.first = v[ind].first;
        swap(i.first,i.second);
    }
    // cout<< endl;
    sort(q.begin(),q.end());
    for(int i=0;i<B.size();i++){
        B[i] = q[i].second;
    }
    return B;
}
*/