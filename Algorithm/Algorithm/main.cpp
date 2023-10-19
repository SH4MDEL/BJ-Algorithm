#include <iostream>
#include <string>
#include <vector>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

void splitArray(const vector<int>& arr, vector<int>& b, vector<int>& c, int idx, int& count) 
{
    if (idx == arr.size()) {
        ++count;
        return;
    }

    int prev_b = (idx == 0) ? -1 : b[idx - 1];
    int prev_c = (idx == 0) ? 1e9 + 7 : c[idx - 1];

    // b와 c의 가능한 모든 값에 대해 재귀 호출
    for (int i = 0; i <= arr[idx]; ++i) {
        if (i >= prev_b && arr[idx] - i <= prev_c) {
            b[idx] = i;
            c[idx] = arr[idx] - i;
            splitArray(arr, b, c, idx + 1, count);
        }
    }
}

int main() {
    vector<int> arr = { 2, 3, 2 };
    vector<int> b(arr.size(), 0);
    vector<int> c(arr.size(), 0);
    int count = 0;

    splitArray(arr, b, c, 0, count);

    cout << "Total possible ways: " << count << endl;

    return 0;
}