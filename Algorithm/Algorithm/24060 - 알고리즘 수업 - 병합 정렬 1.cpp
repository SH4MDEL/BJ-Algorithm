#include <iostream>
#include <array>
#include <algorithm>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int a[505050];
int tmp[505050];
int n, k;
int counting;

void merge(int p, int q, int r);

void merge_sort(int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r)
{
    int i = p; int j = q + 1; int t = 0;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) {
            tmp[t++] = a[i++];
        }
        else {
            tmp[t++] = a[j++];
        }
    }
    while (i <= q) {
        tmp[t++] = a[i++];
    }
    while (j <= r) {
        tmp[t++] = a[j++];
    }
    i = p; t = 0;
    while (i <= r) {
        a[i++] = tmp[t++];
        ++counting;
        if (counting == k) {
            cout << a[i - 1];
        }
    }
}

int main()
{
    sws; fastip;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    if (counting < k) cout << -1;
}