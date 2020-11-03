#include<bits/stdc++.h>

using namespace std;


vector<vector<int>> allInvitedCommandersCombinations;

// check if arr2 is subset of arr1
bool isSubset(vector<int> arr1, int arr2[],
              int m, int n) {
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == m)
            return 0;
    }
    return 1;
}
// find all possible combination of commanders
void findCombination(int *arr, vector<int> data,
                     int start, int end,
                     int index, int k) {
    // Stop if seats got full
    if (index == k) {
        allInvitedCommandersCombinations.push_back(data);
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= k - index; i++) {
        data.insert(data.begin() + index, arr[i]);
        findCombination(arr, data, i + 1,
                        end, index + 1, k);
    }
}


// Driver code
int main() {

    int n, k, m;
    cin >> n >> k >> m;


    int commanders[n];
    for (int i = 0; i < n; i++) {
        commanders[i] = i + 1;
    }

    int conflicts[m][2];

    for (int i = 0; i < m; i++) {
        cin >> conflicts[i][0] >> conflicts[i][1];
    }
//    allInvitedCommandersCombinations.reserve(33554432);

    vector<int> invitedCommanders;
    findCombination(commanders, invitedCommanders, 0, n - 1, 0, k);
    int res = 0;
    for (int i = 0; i < allInvitedCommandersCombinations.size(); i++) {
//        cout << "\n";
//        for (int j = 0; j < allInvitedCommandersCombinations[0].size(); j++) {
//            cout << allInvitedCommandersCombinations[i][j] << " ";
//        }
        for (int s = 0; s < m; s++) {
            if (isSubset(allInvitedCommandersCombinations[i], conflicts[s], k, 2)) {
                res++;
                break;
            }
        }
    }

    cout  << allInvitedCommandersCombinations.size() - res;


}

