#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Point
{
    public:
        int x, y;
};

int clockwiseOrcouterclockwise(Point P, Point Q, Point R)
{
    int val = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);
    if (val == 0) return 0;
    // 1. Clockwise or 2. CouterClockwise
    return (val > 0) ? 1 : 2;
}

void convexHull(Point Points[], int n)
{
    if (n < 3) return;

    vector<Point> hull;

    // find leftmost 
    int l = 0;
    for (int i = 1; i < n; ++i)
    {
        if (Points[i].x < Points[l].x)
        {
            l = i;
        }
    }

    int p = l, q; 
    do
    {
        hull.push_back(Points[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (clockwiseOrcouterclockwise(Points[p], Points[i], Points[q]) == 2)
            {
                q = i;
            }
        }
        p = q;
    }
    while(p != l);

    for (int i = 0; i < hull.size(); i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")" << endl;
    }
    
}

int main()
{
    Point P[] = {{3, 4}, {5, 3}, {6, 5}, {7, 6}, {8, 7}, {4, 9}, {3, 8}, {4, 8}, {7, 10}, {7, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    convexHull(P, n);
    return 0;
}