typedef long long ll;

int findFirstNumIndex(int& k, int n)
{
 
    if (n == 1)
        return 0;
    n--;
 
    int first_num_index;
    // n_actual_fact = n!
    int n_partial_fact = n;
 
    while (k >= n_partial_fact
           && n > 1) {
        n_partial_fact= n_partial_fact* (n - 1);
        n--;
    }
 
    // First position of the
    // kth sequence will be
    // occupied by the number present
    // at index = k / (n-1)!
    first_num_index = k / n_partial_fact;
 
    k = k % n_partial_fact;
 
    return first_num_index;
}
string Solution::getPermutation(int A, int B) {
    // if(A>12) return to_string(INT_MAX);
    int n = A;
    string ans = "";
    vector<ll> v;
    for(ll i=1; i<=n; i++){
        v.push_back(i);
    }
    int k = B;
    k = k - 1;//for 0 indexing
 
    for (int i = 0; i < n; i++) {
 
        int index = findFirstNumIndex(k, n - i);
 
        // itr now points to the
        // number at index in set s
        ans += (to_string(v[index]));
 
        // remove current number from the set
        v.erase(v.begin() + index);
 
    }
    return ans;
    
}
/*
    ll n = A;
    string ans = "";
    vector<ll> v;
    for(ll i=1; i<=n; i++){
        v.push_back(i);
    }
    long long fact = 1LL;
    //n > 12 wrong ans
    for(ll i=1; i<=n; i++){
        fact = fact*i;
    }
    ll k = B;
    while((int)v.size() > 0){
        fact /= n;
        ll q = k/fact;
        ll r = k%fact;
        ll ind;
        //0 indexing
        if(r == 0){
            ind = q-1;
        }
        else{
            ind = q;
        }
        //number q comes
        //k decreases
        //fact decreases
        // cout<<"ind "<<ind<<"\n";
        auto it = v.begin()+ind;
        ll num = *it;
        // cout<<"num "<<num<<"\n";
        
        ans += to_string(num);
        v.erase(it);
        k -= (ind*fact);
        // cout<<"k "<<k<<"\n";
        n -= 1;
    }
    while((int)v.size()>0){
        ans += to_string(*v.begin());
        v.erase(v.begin());
    }
    */
