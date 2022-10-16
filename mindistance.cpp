#include<iostream>
#include<math.h>
#include<float.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class Point
{
    public: int x, y;
};

// So sánh dựa trên X
int CompareX(const void *a , const void *b)
{
    Point *p1 = (Point *)a; Point *p2 = (Point *)b;
    return (p1->x < p2->x);
}

// So sánh dựa trên Y
int CompareY(const void *a , const void *b)
{
    Point *p1 = (Point *)a; Point *p2 = (Point *)b;
    return (p1->y < p2->y);
}

// Tính distance giữa 2 point 
float distance(Point p1 , Point p2)
{
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// Đối với 3 điểm thì dùng trực tiếp 
float bruteForce(Point P[] , int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(distance(P[i], P[j]) < min)
            {
                min = distance(P[i], P[j]);
            }
        }
    }
    return min;
}

float stripClosest(Point stripPoint[], int size, float d)
{
    float min = d;
    
    qsort(stripPoint, size, sizeof(Point), CompareY);

    for (int i = 0; i < size ; i++)
    {
        for (int j = i + 1; j < size && (stripPoint[j].y - stripPoint[i].y) < min ; j++)
        {
            // Ở đây có thể thẩy giải thuật sử dụng 2 vòng lặp tức độ phức tạp O(n^2)
            // Nhưng với vòn lặp thứ 2 điều kiện thêm vào thì độ phức tạp đã giảm xuống với độ phức tạp là O(n)
            if (distance(stripPoint[i], stripPoint[j]) < min) 
            {
                min = distance(stripPoint[i], stripPoint[j]);
            }
        }
    }
    return min;
}

float ClosestUntil(Point P[], int n)
{
    if (n < 3) return bruteForce(P, n);

    int mid = n/2;
    Point midpoint = P[mid]; 

    float dl = ClosestUntil(P, mid);
    float dr = ClosestUntil(P + mid, n - mid);

    float d = (dl < dr)? dl : dr;

    Point stripPoint[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x - midpoint.x) < d)
        {
            stripPoint[j] = P[i], j++;
        }
    }
    return (d < stripClosest(stripPoint, j , n)) ?  d : stripClosest(stripPoint, j , n);
}

float closestDistance(Point P[], int n)
{
    qsort(P, n , sizeof(Point), CompareX);

    return ClosestUntil(P, n);
}

int main()
{
    Point P[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << closestDistance(P, n) << " is Closest distance of arr Point " << endl;
    return 0;
}