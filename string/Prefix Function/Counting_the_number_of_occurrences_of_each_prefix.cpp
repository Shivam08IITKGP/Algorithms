#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    vector<int> pi(n);
    vector<int> ans(n+1);
    pi[0]=0;
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
    for(int i=0;i<n;i++)
    {
        ans[pi[i]]++;
    }
    for(int i=n-1;i>0;i--)
    {
        ans[pi[i-1]]+=ans[i];
    }
    for(int i=0;i<=n;i++)
    {
        ans[i]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }

}
int main()
{
    FAST;
    solve();
    return 0;
}