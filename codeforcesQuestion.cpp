#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to handle the interaction for a single test case
void solve() {
    int n;
    // Read n
    if (!(cin >> n)) return; 

    // Iterate through all unique pairs (i, j) where 1 <= i < j <= n.
    // This performs exactly C(n, 2) = n*(n-1)/2 queries.
    // Since the maximum query limit is floor(n^2 / a) and a >= 2, 
    // the limit is at least floor(n^2 / 2). Since n^2 / 2 is close to C(n, 2),
    // and for n=40, C(40, 2) = 780 which is less than floor(40^2 / 2) = 800,
    // this brute-force check guarantees success within the limit.
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            
            // Query the pair (i, j)
            cout << i << " " << j << endl;
            
            int x;
            // Read the result
            if (!(cin >> x)) return;

            // If the result is -1 (error from interactor), exit immediately
            if (x == -1) {
                exit(0);
            }

            // If the flashlight turned on (x=1), we found a working pair.
            // The problem specifies that the interaction is successful and terminates now.
            if (x == 1) {
                return; 
            }
        }
    }
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read number of test cases
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}
