#include <bits/stdc++.h>
using namespace std;

// Function to count minimum swaps
int minimumSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        // Already visited or already in correct position
        if (visited[i] || arr[i] == i + 1)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr[j] - 1;
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minimumSwaps(arr) << '\n';
    return 0;
}
