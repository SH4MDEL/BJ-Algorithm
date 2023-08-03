#include <iostream>
#include <memory.h>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n;
int cache[35][7];

int dp(int depth, int type)
{
    if (depth == n) return 1;
    if (depth == n - 1) {
        switch (type)
        {
        case 0: // ¾È Ã¤¿öÁü
            return cache[depth][type] = 0;
        case 1: // 1¹ø Ã¤¿öÁü
            return cache[depth][type] = 1;
        case 2: // 2¹ø Àç¿öÁü
            return cache[depth][type] = 0;
        case 3: // 3¹ø Ã¤¿öÁü
            return cache[depth][type] = 1;
        case 4: // 12 Ã¤¿öÁü
            return cache[depth][type] = 0;
        case 5: // 13 Ã¤¿öÁü
            return cache[depth][type] = 0;
        case 6: // 23 Ã¤¿öÁü
            return cache[depth][type] = 0;
        }
    }

    if (cache[depth][type] != -1) return cache[depth][type];

    switch (type)
    {
    case 0:
        return cache[depth][type] = dp(depth + 1, 1) + dp(depth + 1, 3) + dp(depth + 2, 0);
    case 1:
        return cache[depth][type] = dp(depth + 1, 0) + dp(depth + 1, 6);
    case 2:
        return cache[depth][type] = dp(depth + 1, 5);
    case 3:
        return cache[depth][type] = dp(depth + 1, 0) + dp(depth + 1, 4);
    case 4:
        return cache[depth][type] = dp(depth + 1, 3);
    case 5:
        return cache[depth][type] = dp(depth + 1, 2);
    case 6:
        return cache[depth][type] = dp(depth + 1, 1);
    }
}

int main()
{
    sws; fastip;

    cin >> n;

    memset(cache, -1, sizeof(int) * 35 * 7);

    cout << dp(0, 0);
}