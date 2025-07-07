#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i)
      ans.push_back(vector<int>(i + 1, 1));

    for (int i = 2; i < numRows; ++i)
      for (int j = 1; j < ans[i].size() - 1; ++j)
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

    return ans;
  }
};

// Helper function to print Pascal's triangle
void printTriangle(const vector<vector<int>>& triangle) {
    cout << "[";
    for (size_t i = 0; i < triangle.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < triangle[i].size(); ++j) {
            cout << triangle[i][j];
            if (j + 1 < triangle[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < triangle.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    int numRows1 = 5;
    cout << "Input: numRows = " << numRows1 << endl;
    cout << "Output: ";
    printTriangle(solution.generate(numRows1));

    int numRows2 = 1;
    cout << "Input: numRows = " << numRows2 << endl;
    cout << "Output: ";
    printTriangle(solution.generate(numRows2));

    return 0;
}
