#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
const int p = 31;
const ll m = 1e9 + 9;

//Find The occurences of a string t in string s in O(|s|+|t|) time 
//Creates a sliding window and check if hash of the string matches

void solve(string s, string t)
{
    int n = s.size();

    vector<ll> hash(n + 1);
    vector<ll> p_powers(n + 1);
    p_powers[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p_powers[i] = (p_powers[i - 1] * p) % m;
    }
    hash[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * p_powers[i - 1]) % m;
    }
    ll hash_t = 0;
    for (int i = 1; i <= t.size(); i++)
    {
        hash_t = (hash_t + p_powers[i - 1] * (t[i - 1] - 'a' + 1)) % m;
    }
    vector<int> occurences;
    for (int i = 0; i <= n - t.size(); i++)
    {
        ll curr_hash = (hash[i + t.size()] + m - hash[i]) % m;
        if (curr_hash == hash_t * p_powers[i] % m)
        {
            occurences.push_back(i);
        }
    }
    for (auto x : occurences)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    string s, t;
    cin >> s >> t;
    solve(s, t);
}
