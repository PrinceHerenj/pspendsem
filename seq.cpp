// Given an integer 'n' (user defined), generate the first "n' terms of the following sequence, where the sequence is formed with the first prime number, i. e., 2 as its first term. The subsequent terms of the sequence are made up of the nex? fwo prime numbers, i.e 3 and 5, followed by the next three non-prime numbers, i.e 6, 8 and 9, l'ollowed by the next four prime numbers, i.e 11, 13, 17 and 19 and so on.... the sequence continues. Write a program in C+ + to implement it.
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int getNextPrime(int num) {
    num++;
    while (!isPrime(num)) num++;
    return num;
}

int getNextNonPrime(int num) {
    num++;
    while (isPrime(num)) num++;
    return num;
}

void sequence_printer(int n) {
    if (n <= 0) return;
    if (n == 1) cout << "2";
    else cout << "2, ";
    int currentNum = 2;
    int groupSize = 2;
    bool isPrimeGroup = true;
    int groupCount = 0;
    int numbersGenerated = 1;
    
    while (numbersGenerated < n) {
        if (isPrimeGroup) 
            currentNum = getNextPrime(currentNum);
        else 
            currentNum = getNextNonPrime(currentNum);
        
        cout << currentNum;
        numbersGenerated++;
        
        if (numbersGenerated < n) cout << ", ";
        
        groupCount++;
        
        if (groupCount == groupSize) {
            if (isPrimeGroup) 
                isPrimeGroup = false;
            else {
                isPrimeGroup = true;
            }
            groupSize++;
            groupCount = 0;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    sequence_printer(n);
    return 0;
}