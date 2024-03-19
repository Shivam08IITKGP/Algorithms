#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string str = s + "#" + t;
    vector<int>pi(n+m+1),occurences;
    for(int i=1;i<n+m+1 ;i++)
    {
        int j = pi[i-1];
        while(j>0 and str[i]!=str[j])
        {
            j = pi[j-1];
        }
        if(str[i]==str[j])
        {
            j++;
        }
        pi[i] = j;
        if(j==n)
        {
            occurences.push_back(i-2*n);
        }
    }
    for(auto x:occurences)
    {
        cout<<x<<" ";
    }
}
int main()
{
    FAST;
    solve();
    return 0;
}
