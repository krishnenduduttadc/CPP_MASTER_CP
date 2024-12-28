#include<bits/stdc++.h>

using namespace std;

struct node {
    node *nxt[26];
    bool is_end;
    node() {
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
        is_end = false;
    }
};

node *root;

void insert_trie(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int imap = s[i] - 'a';
        // new node
        if (cur->nxt[imap] == NULL) {
            cur->nxt[imap] = new node();
        }
        // goto that node
        cur = cur->nxt[imap];
    }
    // cur -> last node
    cur->is_end = true;
}

// O(|s|)
bool search_trie(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int imap = s[i] - 'a';
        if (cur->nxt[imap] == NULL) return false;
        cur = cur->nxt[imap];
    }
    return cur->is_end;
}

int main() {
    // Initialize the root node of the trie
    root = new node();

    // Hardcoded input: number of strings followed by the strings themselves
    int n = 3;  // Number of strings to be inserted
    vector<string> words = {"apaar", "apple", "bat"};  // Hardcoded list of words

    // Insert each string into the Trie
    for (int i = 0; i < n; i++) {
        insert_trie(words[i]);
    }

    // Search for the word "apaar" in the Trie
    if (search_trie("apaar")) {
        cout << "Found";
    }
    else {
        cout << "Not Found";
    }

    return 0;
}
