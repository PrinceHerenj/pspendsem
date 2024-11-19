// You are given a 1D array of integers. Write a program using constructors and destructors to find the biggest of all the numbers at the prime number locations.

#include <iostream>
#include <string>
using namespace std;

class Printer {
    public:
        string PrimeLocations;
        int max;
        Printer(int arr[], int n) {
            this->PrimeLocations = this->findPrimeIndexes(n);
            this->max = arr[2];
            for (int i = 0; i < this->PrimeLocations.length(); i++) {
                if (arr[this->PrimeLocations[i] - '0'] > this->max) {
                    max = arr[this->PrimeLocations[i] - '0'];
                }
            }
            cout << "Max = " << max << endl;
        }
        ~Printer() {
            cout << "Printer object is being destroyed" << endl;
        }
        bool isPrime(int num) {
            if (num < 2) return false;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) return false;
            }
            return true;
        }

        string findPrimeIndexes(int n) {
            string out = "";
            for (int i = 0; i < n; i++) {
                if (isPrime(i)) out += to_string(i);
            }
            return out;
        }
};

int main() {
    int a[] = {1, 4, 45, 2, 92, 108, 116, 7, 6, 9};
    int n = sizeof(a)/sizeof(a[0]);
    Printer p(a, n);
}