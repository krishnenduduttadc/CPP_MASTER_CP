#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
};

// Cross product: (OA × OB) > 0 if OB is counter-clockwise from OA
int cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns the convex hull in counter-clockwise order
vector<Point> convex_hull(vector<Point> P) {
    int n = P.size();
    if (n <= 1) return P;

    sort(P.begin(), P.end());
    vector<Point> H(2 * n);
    int k = 0;

    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) --k;
        H[k++] = P[i];
    }

    // Upper hull
    for (int i = n-2, t = k+1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) --k;
        H[k++] = P[i];
    }

    H.resize(k - 1);
    return H;
}

int main() {
    // Hardcoded input points
    vector<Point> points = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4},
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };

    // Compute convex hull
    vector<Point> hull = convex_hull(points);

    // Print the convex hull points
    cout << "Convex Hull Points (in order):\n";
    for (const Point& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}