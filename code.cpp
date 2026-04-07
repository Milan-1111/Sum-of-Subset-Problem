#include <iostream>
using namespace std;

int set[10], x[10], n, target;

void subset(int k, int sum, int total) {
    if (sum == target) {
        cout << "{ ";
        for (int i = 0; i < k; i++)
            if (x[i]) cout << set[i] << " ";
        cout << "}\n";
        return;
    }

    if (k == n || sum > target) return;

    x[k] = 1;
    subset(k + 1, sum + set[k], total - set[k]);

    x[k] = 0;
    subset(k + 1, sum, total - set[k]);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> set[i];
        total += set[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    subset(0, 0, total);
    return 0;
}