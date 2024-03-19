#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;
//The orriginal approach would be to 
//for every substring j=0 to i - O(n)
//for every length check if the prefix and suffix are equal - O(n^2)
//Hence the total time complexity will be - O(n^3)


//Where as this approach is only O(n).
//Here two facts are used
//1) pi[i+1] <= pi[i] + 1
//2) Using the above argument further there will be two cases
//     a) a[i+1]=a[pi[i]], then the pi[i+1]=pi[i]+1
//     b) a[i+1]!=a[pi[i]], then we have to decrease the length till we find a[i]=a[j]



void prefixFunction()
{
    ll n;
    cin >> n;
    string a;
    cin >> a;
    ll pi[n];
    pi[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 and a[i] != a[j])
        {
            j = pi[j - 1];
        }
        if (a[i] == a[j])
        {
            j++;
        }
        pi[i] = j;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << pi[i] << " ";
    }
}
int main()
{
    FAST;
    prefixFunction();
    return 0;
}
