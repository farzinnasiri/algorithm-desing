#include<bits/stdc++.h>

using namespace std;

struct RectangleWithPoints {
    int x; // bottom left
    int y; // bottom right
    int z; // top left
};

struct RectangleWithEdges {
    int horizontal;
    int vertical;
};

bool compareRectangles(RectangleWithPoints &a, RectangleWithPoints &b) {
    return a.x <= b.x;
}

// in => sorted array of rectangles based on position on horizontal axis,all xy's of rectangles,number of rectangles
// out => total covered area
int GetCoveredArea(RectangleWithPoints rectangles[], int xys[], int k) {
    int area = 0; // initial value

    int x1, x2;
    int j = 0;
    for (int i = 0; i < 2*k - 1; i++) {
        x1 = xys[i];
        x2 = xys[i + 1];

        if (x1 < x2) {
            RectangleWithEdges rwe = {x2 - x1, 0};
            // If the range new rectangles edge is after the original rectangles, update counter
            while (rectangles[j].y < x1) {
                j++;
            }
            for (int t = j; t < k; t++) {
                if (rectangles[t].y >= x2 && rectangles[t].x <= x1) {
                    rwe.vertical = max(rectangles[t].z, rwe.vertical);
                }
            }

            area += rwe.vertical * rwe.horizontal;
        }

    }
    return area;
}

int main() {
    // n,m => size of field
    // k = > covered grass areas
    int n, m, k;

    cin >> n >> m >> k;

    // initializing array of rectangles(covered grass)

    RectangleWithPoints rectangles[k];

    // creating the rectangles
    for (int i = 0; i < k; i++) {
        cin >> rectangles[i].x;
        cin >> rectangles[i].y;
        cin >> rectangles[i].z;
//        rectangles[i].w = rectangles[i].y + rectangles[i].z;
    }

    sort(rectangles, rectangles + k, compareRectangles);

    int xys[2*k]; // all x and y positions of rectangles stored here

    for (int i = 0; i < k; i++) {
        xys[2*i] = rectangles[i].x;
        xys[2*i+1] = rectangles[i].y;
    }

    sort(xys,xys+2*k); // sorting all the x values

//    cout << "=============================\n";

//    for (int i = 0; i < k; i++) {
//        cout << rectangles[i].x;
//        cout << " ";
//        cout << rectangles[i].y;
//        cout << " ";
//        cout << rectangles[i].z;
//        cout << " ";
//        cout << rectangles[i].w ;
//        cout << endl;
//    }
//
//    for (int i = 0; i < 2*k; i++) {
//        cout << xys[i];
//        cout << " ";
//        cout << endl;
//    }

    int covered = GetCoveredArea(rectangles, xys, k);
    cout << m*n- covered << endl;

}