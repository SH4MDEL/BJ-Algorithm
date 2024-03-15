#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#define fastip std::cin.tie(nullptr)
#define sws std::ios::sync_with_stdio(false)
#define inf 987654321 
#define endl "\n"
using namespace std;

int n, q;

struct Node {
    shared_ptr<Node> next[26];
    shared_ptr<Node> fail;
    bool finished = false;

    void insert(const string& s, int depth) {
        if (s.length() == depth) {
            finished = true;
            return;
        }

        int word = s[depth] - 'a';
        if (!next[word]) next[word] = make_shared<Node>();
        
        next[word]->insert(s, depth + 1);
    }
};

void bfs(const shared_ptr<Node>& root)
{
    queue<shared_ptr<Node>> q;
    q.push(root);
    while (!q.empty())
    {
        auto current = q.front(); q.pop();

        for (int i = 0; i < 26; ++i) {
            shared_ptr<Node> next = current->next[i];
            if (!next) continue;

            if (current == root) {
                next->fail = root;
            }
            else {
                shared_ptr<Node> dest = current->fail;

                while (dest != root && !dest->next[i]) {
                    dest = dest->fail;
                }

                if (dest->next[i]) dest = dest->next[i];
                next->fail = dest;
            }

            if (next->fail->finished) next->finished = true;

            q.push(next);
        }
    }
}

int main()
{
    fastip; sws;

    shared_ptr<Node> root = make_shared<Node>();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        root->insert(s, 0);
    }
    bfs(root);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;

        shared_ptr<Node> current = root;
        bool ans = false;

        for (auto& c : s) {
            int next = c - 'a';

            while (current != root && !current->next[next]) {
                current = current->fail;
            }
            if (current->next[next]) {
                current = current->next[next];
            }

            if (current->finished) {
                ans = true;
                break;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}