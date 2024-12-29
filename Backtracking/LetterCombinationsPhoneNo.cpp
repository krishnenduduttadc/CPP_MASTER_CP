#include<bits/stdc++.h>
using namespace std;

int n;
vector<string>mapping={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void solve(int pos, string &cur, vector<string>&ans,string &digits)
{
    if(pos==n)
    {
        ans.push_back(cur);
        return;
    }
    for(char  ch: mapping[digits[pos]-'2'])
    {
        cur.push_back(ch);
        solve(pos+1,cur,ans,digits);
        cur.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string>ans;
    n=digits.size();
    if(n==0)
    {
        return ans;
    }
    string cur;
    solve(0,cur, ans,digits);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
string digits = "23"; // Example input

    vector<string> combinations = letterCombinations(digits);

    // Output the result
    cout << "Letter combinations for digits '" << digits << "':\n";
    for(const string &comb : combinations) {
        cout << comb << " ";
    }
    cout << endl;

    return 0;

}