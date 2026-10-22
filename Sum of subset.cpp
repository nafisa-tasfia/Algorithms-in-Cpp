#include <iostream>
using namespace std;

int n, target;
int element[20], x[20];

void SumOfSubsets(int i, int sum, int remaining) {

    if (sum == target) {
        cout << "Subset found: ";

        for (int j = 1; j <= n; j++) {
            if (x[j] == 1)
                cout << element[j] << " ";
        }

        cout << endl;
        return;
    }

    if (i > n || sum > target) {
        return;
    }

    // Include element[i]
    x[i] = 1;
    SumOfSubsets(i + 1, sum + element[i], remaining - element[i]);

    // Exclude element[i]
    x[i] = 0;
    SumOfSubsets(i + 1, sum, remaining - element[i]);
}

int main() {

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements of the set: ";
    for (int i = 1; i <= n; i++) {
        cin >> element[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    int total = 0;

    for (int i = 1; i <= n; i++) {
        total += element[i];
        x[i] = 0;
    }

    cout << "Subsets with sum " << target << " are:" << endl;

    SumOfSubsets(1, 0, total);

    return 0;
}
