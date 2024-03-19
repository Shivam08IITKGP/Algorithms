#include <bits/stdc++.h>
using namespace std;
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long int ll;

void solve_n3logn()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            st.insert(temp);
        }
    }
    cout << st.size() << endl;
}
void solve_n2()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    int ans = 0;
    string reverse_s = "";
    for (int i = 0; i < n; i++)
    {
        reverse_s = s[i] + reverse_s;
        vector<int> pi((int)reverse_s.length());
        pi[0] = 0;
        int pi_max = 0;
        for (int i = 1; i < pi.size(); i++)
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
            pi_max = max(pi_max, pi[i]);
        }
        ans += (int)reverse_s.length() - pi_max;
    }
    cout << ans << endl;
}

int main()
{
    FAST;
    solve_n2();
    return 0;
}
