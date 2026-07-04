#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int top = 0, bottom = H - 1;
    int left = 0, right = W - 1;

    // Remove white rows from the top
    while (top <= bottom) {
        bool allWhite = true;
        for (int j = 0; j < W; j++) {
            if (grid[top][j] == '#') {
                allWhite = false;
                break;
            }
        }
        if (!allWhite) break;
        top++;
    }

    // Remove white rows from the bottom
    while (bottom >= top) {
        bool allWhite = true;
        for (int j = 0; j < W; j++) {
            if (grid[bottom][j] == '#') {
                allWhite = false;
                break;
            }
        }
        if (!allWhite) break;
        bottom--;
    }

    // Remove white columns from the left
    while (left <= right) {
        bool allWhite = true;
        for (int i = top; i <= bottom; i++) {
            if (grid[i][left] == '#') {
                allWhite = false;
                break;
            }
        }
        if (!allWhite) break;
        left++;
    }

    // Remove white columns from the right
    while (right >= left) {
        bool allWhite = true;
        for (int i = top; i <= bottom; i++) {
            if (grid[i][right] == '#') {
                allWhite = false;
                break;
            }
        }
        if (!allWhite) break;
        right--;
    }

    // Output the cropped image
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
