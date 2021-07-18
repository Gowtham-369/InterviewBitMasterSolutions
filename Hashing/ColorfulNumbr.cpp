typedef long long ll;
int Solution::colorful(int A)
{
    map<ll, ll> mp;
    int n = A;
    string res = "";
    while (n > 0)
    {
        res += char(n % 10 + '0');
        n /= 10;
    }
    reverse(res.begin(), res.end());
    int len = res.size();
    for (int i = 0; i < len; i++)
    {
        ll mul = 1;
        mul *= (res[i] - '0');
        // mp.insert({mul,0});
        if (mp.find(mul) != mp.end())
        {
            return 0;
        }
        mp[mul] += 1;
        for (int j = i + 1; j < len; j++)
        {
            mul *= (res[j] - '0');
            if (mp.find(mul) != mp.end())
            {
                return 0;
            }
            mp[mul] += 1;
        }
    }
    return 1;
}
