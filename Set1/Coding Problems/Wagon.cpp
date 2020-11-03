#include<bits/stdc++.h>

using namespace std;

struct Wagon {
    int position;
    int speed;
};


int main() {
    int n, l;
    cin >> n >> l;

    Wagon wagons[n];

    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> wagons[i].position >> wagons[i].speed;
        if(wagons[i].speed < 0){
            res = max(res,wagons[i].position);
        }else{
            res = max(res,l-wagons[i].position);
        }
    }

    cout << res << endl;



}