#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    unordered_set<string> s;  // Set to store all words for quick lookup
    for(auto itr: wordList) {
        s.insert(itr);  // Insert all words from wordList into the set
    }
    
    // If the endWord is not in the wordList, return 0 as no transformation is possible
    if (s.find(endWord) == s.end()) {
        return 0;
    }

    queue<string> q;  // BFS queue to store current word being processed
    int ans = 0;  // Variable to store the number of transformations (levels)
    q.push(beginWord);  // Start BFS from the beginWord

    while(!q.empty()) {
        ans++;  // Increment the transformation step (level)
        int n = q.size();  // Number of words to process at the current level

        for(int i = 0; i < n; i++) {
            string str = q.front();  // Get the word at the front of the queue
            q.pop();  // Remove it from the queue
            
            // If we've reached the endWord, return the number of transformations (steps)
            if(str == endWord) {
                return ans;
            }
            
            // Try replacing each character in the current word with all possible characters
            for(int j = 0; j < str.size(); j++) {
                char ch = str[j];  // Store the original character
                for(int k = 0; k < 26; k++) {  // Try replacing it with 'a' to 'z'
                    str[j] = char(97 + k);  // Replace character at position j
                    
                    // If the transformed word is in the word list and hasn't been visited
                    if(s.find(str) != s.end()) {
                        q.push(str);  // Push the new word to the queue
                        s.erase(str);  // Remove it from the set to mark it as visited
                    }
                }
                str[j] = ch;  // Restore the original character at position j
            }
        }
    }
    
    return 0;  // If the queue is empty and endWord is not found, return 0 (no transformation possible)
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(beginWord, endWord, wordList);
    cout << "The length of the shortest transformation sequence is: " << result << endl;
    return 0;
}
