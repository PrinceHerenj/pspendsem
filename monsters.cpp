// Given N monsters, each monster has initial health h[i] which is an integer. A monster is alive if its health is greater than 0. In each turn a random monster kills another random monster, the monster which is attacked, its health reduces by the amount of health of the attacking monster. This process is continued until a single monster is left. What will be the minimum possible health of the last remained monster. In others words, the task is to play the game in such a way that monster which is left in the end has the least possible health.

// Imput: h[] = {2, 14, 28, 56} // Output: 2
// Input: h[] = {7, 17, 9, 100, 25} // Output: 1

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int findMinHealth(int h[], int n) {
    int currect_gcd = gcd(h[0], h[1]);
    for (int i = 2; i < n; i++) {
        currect_gcd = gcd(currect_gcd, h[i]);
    }
    return currect_gcd;
}

int main() {
    int health[] = {7, 17, 9, 100, 25};
    int n = sizeof(health) / sizeof(health[0]);
    cout << findMinHealth(health, n) << endl;
}