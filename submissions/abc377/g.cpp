#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        fill(begin(children), end(children), nullptr);
        isEndOfWord = false;
    }
};

class Trie {
   public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    int minCostToMatch(const string& word) {
        TrieNode* node = root;
        int cost = 0;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (node->children[index]) {
                node = node->children[index];
            } else {
                // Remaining characters to delete
                cost += (word.size() - i);
                return cost;
            }
            cost++;  // Cost for matching each character
        }
        return cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> strings(N);

    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
    }

    Trie trie;
    vector<int> results(N);

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            // First string, cost to convert to empty string
            results[i] = strings[i].size();
        } else {
            // Find the minimum cost to match with any previous string
            results[i] = trie.minCostToMatch(strings[i]);
        }
        // Insert the current string into the Trie for future matches
        trie.insert(strings[i]);
    }

    // Output results
    for (int cost : results) {
        cout << cost << '\n';
    }

    return 0;
}
