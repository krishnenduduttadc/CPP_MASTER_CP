#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
map<string, multiset<string>> m;

void dfs(string str)
{
    while(m[str].size() > 0)
    {
        auto it = m[str].begin();
        string str1 = *it;
        m[str].erase(it);
        dfs(str1);
    }
    ans.push_back(str);
}

vector<string> findItinerary(vector<vector<string>> tickets) {
    int n = tickets.size();
    ans.clear();
    m.clear();
    for(int i = 0; i < n; i++)
    {
        string str1 = tickets[i][0], str2 = tickets[i][1];
        m[str1].insert(str2);
    }
    dfs("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Hardcoded test case with some flights
    vector<vector<string>> tickets = {
        {"MUC", "LHR"},
        {"JFK", "MUC"},
        {"SFO", "SJC"},
        {"LHR", "SFO"},
        {"SJC", "JFK"}
    };

    // Find the itinerary
    vector<string> itinerary = findItinerary(tickets);

    // Output the result
    cout << "Itinerary: ";
    for(const string& place : itinerary) {
        cout << place << " ";
    }
    cout << endl;

    return 0;
}
