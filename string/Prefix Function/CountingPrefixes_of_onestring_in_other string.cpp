#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
const int p =31;
const ll M= 1e9+9;

int prefixFunction(string s,string t,vector<ll>&pi)
{
    string str = s+"#"+t;
    int n = (int)s.length();
    int m = (int)t.length();

    for(int i=1;i<n+m+1;i++)
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
            return i-2*n;
        }
    }
}

void solve()
{
    string s,t;
    cin>>s>>t;
    int n = (int)s.length();
    int m = (int)t.length();
    vector<ll>pi(n+m+1);
    vector<ll>p_powers(n+m+1);
    for(int i=0;i<n+m+1;i++)
    {
        p_powers[i]= (i==0)?1:(p_powers[i-1]*p)%M;
    }
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++)
    {
        ans[i]= prefixFunction(s.substr(0,i),t,pi);
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