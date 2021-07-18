/*
typedef long long ll;
string Solution::multiple(int A) {
    ll res = 1;
    queue<ll> q;
    q.push(res);
    string ans = "";
    // bool ok = true;
    while(!q.empty()){
        int q_size = q.size();
        while(q_size > 0){
            ll x = q.front();
            q.pop();
            if(x%A == 0){
                ans = to_string(x);
                // if(ans.back() != '0'){
                //     // ans.push_back('0');//all ones(1111..) case
                //     // no need this according to TC
                // }
                return ans;
            }
            
            if(x> INT64_MAX/10){
                break;
            }
            else{
                x = x*10;//0 is appended
                q.push(x);
                if(x>INT64_MAX-1LL){
                    break;
                }
                else{
                    q.push(x+1);
                }
            }
        
                
        }
        
    }
    return "-1";
}
*/
string Solution::multiple(int N)
{
    if (N == 1)
        return "1";
    vector<int> p(N, -1); //parent state
    vector<int> s(N, -1); //step from parent to current
    //BFS
    int steps[2] = {0, 1};
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == 0)
            break;
        for (int step : steps)
        {
            int next = (curr * 10 + step) % N;
            if (p[next] == -1)
            {
                p[next] = curr;
                s[next] = step;
                q.push(next);
            }
        }
    }
    //build reversed string
    string number;
    for (int it = 0; it != 1; it = p[it])
        number.push_back('0' + s[it]);
    number.push_back('1');
    //return the reverse if it
    return string(number.rbegin(), number.rend());
}
