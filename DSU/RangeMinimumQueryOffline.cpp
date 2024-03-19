#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// idx is the position of ith query given as input
struct Query {
    int L, R, idx;
};


vector<int> answer;
vector<vector<Query>> container;

int main() {
    vector<int> a = {3, 1, 4, 1, 5, 9};
    int n = a.size();
    answer.assign(n, -1);
    container.resize(n);

    // Stack to keep track of indices
    stack<int> s;
    for (int i = 0; i < n; i++) 
    {
        // The current element is less than the top of the stack
        while (!s.empty() &&   a[i]<a[s.top()] ) {
            // Set the parent of the top element in the stack to the current index
            parent[s.top()] = i;
            // We are going from left to right
            // parent of i is the next smaller element to the right of it
            // so we keep iterating until we find the smallest one in the right of i
            s.pop();
        }
        // Push the current index onto the stack
        s.push(i);
        for (Query q : container[i]) {
            // Set the answer for the query index 'q.idx' as the value at the representative element for the query range
            answer[q.idx] = a[find_set(q.L)];
        }
    }
    for (int ans : answer) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
