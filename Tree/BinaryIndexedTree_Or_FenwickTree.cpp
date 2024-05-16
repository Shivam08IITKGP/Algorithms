#include <bits/stdc++.h>
using namespace std;

// this function returns the sum of arr[0....index]
int get_Sum_Zero_To_Index(int BITree[], int index)
{
    index = index + 1;
    // Here index is 1 based that is according to the BITree indexes
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index = index - index & (-index);
    }
    return sum;
}
// get sum time complexity = O(logn)

void updateBITree_add_val_to_arr_index(int BITree[], int n, int val, int index)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index = index + index & (-index);
    }
    return;
}
// updating time complexity = O(logn)

int *construct_BITree(int arr[], int n)
{
    int *BITree = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        BITree[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        updateBITree_add_val_to_arr_index(BITree, n, arr[i], i);
    }
    return BITree;
}
// Constructing time complexity = O(nlogn)

// Geting range sum from l to r = get_Sum_Zero_To_Index(BITree,r) - get_Sum_Zero_To_Index(BITree,l-1)

void solve() {}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
