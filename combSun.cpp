#include <iostream>
using namespace std;

void backtrack(int index, int current, int target, int* arr, int length, string combination) {
    if (index == length) {
        if (current == target) {
            cout << combination << " = " << current << "\n";
        }
        return;
    }

    backtrack(index + 1, current, target, arr, length, combination);

    backtrack(index + 1, current + arr[index], target, arr, length, combination + " (+) " + to_string(arr[index]));

    backtrack(index + 1, current - arr[index], target, arr, length, combination + " (-) " + to_string(arr[index]));
}

void find_combinations(int* arr, int length, int target) {
    cout << "Combinations that sum to " << target << ":\n";
    backtrack(0, 0, target, arr, length, "");
}

int main() {
    int arr[] = {1, 2, 3, -6};
    int target = 4;
    int length = 4;

    find_combinations(arr, length, target);
}