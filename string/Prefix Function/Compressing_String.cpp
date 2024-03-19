#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    int k = n - pi[n - 1];
    cout<<endl;
    if (n % k == 0)
    {

        cout << s.substr(0, k) << endl;
    }
    else
    {
        cout << s << endl;
    }
}
int main()
{
    FAST;
    solve();
    return 0;
}
