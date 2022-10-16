#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Point
{
    public:
        float x;
        int iterations;
    public:
    Point(float x_new, int iterations_new)
    {
        this->x = x_new;
        this->iterations = iterations_new;
    }
};

float cost(float x)
{
    return (2 * exp(x) - 2 / (exp(x))) * (2 * exp(x) - 2 / (exp(x)));
}

float grad(float x)
{
    return 2 * (2 * exp(x) - 2 / (exp(x))) * (2 * exp(x) + 2 / (exp(x)));
}

vector<Point> GD1(float alpha, Point x0, float gra = 0.001, int loop = 5000)
{
    vector<Point> historyPoints;
    historyPoints.push_back(x0);
    int n = historyPoints.size();
    for (int i = 0; i < loop; i++)
    {
        Point x_new(historyPoints[n - 1].x - alpha * grad(historyPoints[n - 1].x), i);
        if (abs(grad(x_new.x)) < gra) break;
        historyPoints.push_back(x_new);
    }
    return historyPoints;
}


int main(){

    Point staPoint(-5,0);
    vector<Point> calculationPoints = GD1(0.01, staPoint);
    int n = calculationPoints.size();
    cout << "Solution X1 = " << calculationPoints[n - 1].x << ", Cost = " << cost(calculationPoints[n - 1].x)
                << ", obtained after " << calculationPoints[n - 1].iterations <<  " iterations ";

    return 0;
}