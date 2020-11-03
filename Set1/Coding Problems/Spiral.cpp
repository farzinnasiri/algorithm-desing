#include<bits/stdc++.h>

using namespace std;


float distanceCalculate(int x1, int y1, int x2, int y2) {
    int x = x1 - x2;
    int y = y1 - y2;
    float dist;

    dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    dist = sqrt(dist);

    return dist;
}

// Get the coordinates of `first` and `second` in the spiral and put in res[2][2]

void getCoordinates(int res[2][2], int first, int second) {

    // movement unit vectors
    int dx = 0;
    int dy = 1;

    // for every direction it must walk until the direction is reset
    int must_walk = 1;

    int x,y = 0;
    int walks_passed = 0;

    for (int k = 0; k < second - 1; ++k) {
        x += dx;
        y += dy;
//        cout << i << " " << j << endl;
        ++walks_passed;
        if (k == first - 2) {
            res[0][0] = x;
            res[0][1] = y;
//            cout << "first " << k << " " << i << " " << j << endl;
        }
        if (k == second - 2) {
            res[1][0] = x;
            res[1][1] = y;
//            cout << "second " << k << " " << i << " " << j << endl;
            return;
        }

        if (walks_passed == must_walk) {
            walks_passed = 0;

            int temp = dx;
            dx = -dy;
            dy = temp;

            // direction resets so the next walk should get longer
            if (dx == 0) {
                ++must_walk;
            }
        }
    }

}

int main() {
    int a, b;

    cin >> a >> b;

    int m1 = max(a, b);
    int m2 = min(a, b);

    cout << std::fixed;
    cout << std::setprecision(2);

    int res[2][2];
    getCoordinates(res, m2, m1);
//
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            std::cout << res[i][j] << ' ';
//        }
//        cout << endl;
//    }

    cout << distanceCalculate(res[0][0], res[0][1], res[1][0], res[1][1]);

}