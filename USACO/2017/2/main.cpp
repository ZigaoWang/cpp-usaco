#include <iostream>

const int MAX_N = 200000; // Maximum array size based on the constraint

int main() {
    using namespace std; // Use the standard namespace

    int n;
    cin >> n; // Reading the number of elements

    int values[MAX_N]; // Static array to store the values

    for(int i = 0; i < n; ++i) {
        cin >> values[i]; // Reading each value
    }

    // Simple Bubble Sort for demonstration (inefficient for large n)
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (values[j] > values[j+1]) {
                // Manual swap without using std::swap
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }

    // Count distinct values
    int distinct_count = 0;
    for(int i = 0; i < n; ++i) {
        // Increment distinct_count when at the first value or when the current value is not equal to the previous one
        if(i == 0 || values[i] != values[i-1]) {
            distinct_count++;
        }
    }

    // Output the count of distinct values
    cout << distinct_count << endl;

    return 0;
}
