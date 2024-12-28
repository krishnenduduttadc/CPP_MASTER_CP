#include<bits/stdc++.h>

using namespace std;

struct node {
    node *nxt[26];
    vector<int> indices;  // Stores indices where the pattern has been found
    node() {
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

node *root;

void insert_trie(string s, int index) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int imap = s[i] - 'a';
        // new node
        if (cur->nxt[imap] == NULL) {
            cur->nxt[imap] = new node();
        }
        // go to that node
        cur = cur->nxt[imap];
    }
    // Store the index where the suffix starts
    cur->indices.push_back(index);
}

// O(|s|)
bool search_trie(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int imap = s[i] - 'a';
        if (cur->nxt[imap] == NULL) return false;
        cur = cur->nxt[imap];
    }
    return true;
}

// Function to find all occurrences of the pattern
vector<int> find_pattern_occurrences(string pat) {
    node *cur = root;
    vector<int> result;
    for (int i = 0; i < pat.size(); i++) {
        int imap = pat[i] - 'a';
        if (cur->nxt[imap] == NULL) return result;
        cur = cur->nxt[imap];
    }
    return cur->indices;  // return all stored indices where the pattern occurs
}

int main() {
    // root initialization
    root = new node();

    // Hardcoded text and pattern
    string text = "ababba";
    string pat = "aba";

    int n = text.size();

    // Insert all suffixes of the text into the Trie
    for (int i = 0; i < n; i++) {
        insert_trie(text.substr(i), i);
    }

    // Find all occurrences of the pattern
    vector<int> occurrences = find_pattern_occurrences(pat);

    if (occurrences.empty()) {
        cout << "Not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : occurrences) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
