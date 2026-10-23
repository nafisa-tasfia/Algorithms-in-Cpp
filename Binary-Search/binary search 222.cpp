#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int left = 0, right = n - 1;
    bool found = false;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
