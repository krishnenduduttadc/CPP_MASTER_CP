#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool operator < (Point P) const {
        if (x == P.x) return y < P.y;
        else return x < P.x;
    }
    bool operator == (Point P) const {
        return (x == P.x && y == P.y);
    }
};

bool cw(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

bool cll(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}

vector<Point> convex_hull(vector<Point> points) {
    if (points.size() <= 2) return points;

    sort(points.begin(), points.end());  // Sort points lexicographically

    vector<Point> up, down;
    Point first = points[0], last = points.back();

    up.push_back(first); down.push_back(first);

    for (int i = 1; i < points.size(); i++) {
        if (i == points.size() - 1 || cw(first, points[i], last)) {
            // Construct upper hull
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i])) {
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if (i == points.size() - 1 || ccw(first, points[i], last)) {
            // Construct lower hull
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], points[i])) {
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }

    // Combine the upper and lower hulls
    points.clear();
    for (int i = 0; i < up.size(); i++) {
        points.push_back(up[i]);
    }
    for (int i = 0; i < down.size(); i++) {
        points.push_back(down[i]);
    }

    // Sort and remove duplicate points
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());

    return points;
}

int main()
{
    // Hardcoded input
    vector<Point> points = {
        {0, 0}, {2, 2}, {1, 1}, {3, 3}, {4, 4}, 
        {2, 1}, {1, 2}, {0, 3}
    };

    vector<Point> convex_hull_vector = convex_hull(points);

    for (auto x : convex_hull_vector) {
        cout << x.x << " " << x.y << '\n';
    }

    return 0;
}
