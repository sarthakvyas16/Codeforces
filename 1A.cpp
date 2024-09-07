// Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

// What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

// Input
// The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).

// Output
// Write the needed number of flagstones.

// Examples
// InputCopy
// 6 6 4
// OutputCopy
// 4


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    
    // Compute the number of flagstones required along each dimension
    long long num_flagstones_length = (n + a - 1) / a; // Equivalent to ceil(n / a)
    long long num_flagstones_width = (m + a - 1) / a;  // Equivalent to ceil(m / a)
    
    // Calculate the total number of flagstones
    long long total_flagstones = num_flagstones_length * num_flagstones_width;
    
    // Print the result
    cout << total_flagstones << endl;
    
    return 0;
}
