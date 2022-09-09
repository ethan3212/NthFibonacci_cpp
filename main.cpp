#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(n^2) time | O(n) space
int getNthFibRecursive(int n) {
    if(n <= 2) {
        return n - 1;
    }
    return getNthFibRecursive(n - 2) + getNthFibRecursive(n - 1);
}

// O(n) time | O(n) space
int hashTableHelper(unordered_map<int, int> table, int n) {
    if(table.find(n) != table.end()) {// O(1) time
        return table[n];
    } else {
        table[n] = hashTableHelper(table, n - 2) + hashTableHelper(table, n - 1);// O(n) time | O(n) space
        return table[n];
    }
}

// O(n) time | O(n) space
int getNthFibHashTable(int n) {
    unordered_map<int, int> table({
        {1, 0},
        {2, 1}
    });// O(1) space
    return hashTableHelper(table, n);// O(n) time | O(n) space
}

// O(n) time | O(1) space
int getNthFibArray(int n) {
    int array[] = {0, 1};// O(1) space
    int counter = 3;
    while(counter <= n) {// O(n) time
        int nextFibNumber = array[0] + array[1];
        array[0] = array[1];
        array[1] = nextFibNumber;
        counter++;
    }
    return (n > 1) ? array[1] : array[0];
}

int main() {
    int fibNum = 18;
    cout << getNthFibRecursive(fibNum);
    cout << endl;
    cout << getNthFibHashTable(fibNum);
    cout << endl;
    cout << getNthFibArray(fibNum);
    return 0;
}
