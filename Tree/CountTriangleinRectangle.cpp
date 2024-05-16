#include <bits/stdc++.h>
using namespace std;

#define max_coord 1000

int BIT[max_coord + 1][max_coord + 1];

void updateBIT(int x, int y)
{
    int y1;
    while (x <= max_coord)
    {
        y1 = y;
        while (y1 <= max_coord)
        {
            BIT[x][y1]++;
            y1 = y1 + ((y1) & (-y1));
        }
        x = x + ((x) & (-x));
    }
}
int query(int x, int y)
{
    int y1;
    int totalPoints = 0;
    while (x > 0)
    {
        y1 = y;
        while (y1 > 0)
        {
            totalPoints += BIT[x][y1];
            y1 = y1 - (y1 & (-y1));
        }
        x = x - (x & (-x));
    }
    return totalPoints;
}

int rectangle(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x1 - 1, y2) - query(x2, y1 - 1);
}
int triangle(int n)
{
    return (n * (n - 1) * (n - 2)) / 6;
}
//Time Complexity: For each query of either type: O(log(x) * log(y)) Or 
//infact: O( number of ones in binary representation of x * number of ones in a binary representation of y )
//Total time complexity: O(Q * log(maxX) * log(maxY))

int main()
{
    cout << "Enter the number of points (-1 if you want to run on test example) = ";

    int n;
    cin >> n;
    if (n == -1)
    {
        updateBIT(2, 2);
        updateBIT(3, 5);
        updateBIT(4, 2);
        updateBIT(4, 5);
        updateBIT(5, 4);
        // updateBIT(3, 3);
        cout<<triangle(rectangle(1,1,6,6))<<endl;
        return 0;

    }
    else
    {
        cout << "Enter the coordinates of the points: ";
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            updateBIT(x, y);
        }
    }
    cout << "Enter the coordinates of the rectangle: ";
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Number of triangles in the rectangle: " << triangle(rectangle(x1, y1, x2, y2)) << endl;
    return 0;
}
