// 2D Prefix Sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char cell;
            cin >> cell;
            forest[i][j] = (cell == '*') ? 1 : 0;
            // Build the prefix sum matrix using previously calculated values
            prefix[i][j] = forest[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    // Process each query
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Use prefix sum matrix to calculate num trees
        int result = prefix[x2][y2]
                   - prefix[x1-1][y2]
                   - prefix[x2][y1-1]
                   + prefix[x1-1][y1-1];
        
        cout << result << endl;
    }
    
    return 0;
}
