#include <iostream>
#include <vector>

using namespace std;
class Combinations {
    vector<string> ans;
public:
    void generateCombHelper(string s, int idx);
    void setAns(string s);
    void printAns();
};
void Combinations::setAns(string s) {
    ans.push_back(s);
}
void Combinations::printAns() {
    for(int i = 0; i < ans.size(); i++) {
        cout << "\n" << ans[i];
    }
}
void Combinations::generateCombHelper(string s, int idx) {
    //cout << "\ntemp: " << s;
    if(idx == s.size()) {
        setAns(s);
        return;
    }
    for(int i = 0; i < s.size(); i++) {
        string temp = s;
        if(s[i] == '?') {
            temp[i] = 0+'0';
            generateCombHelper(temp, i+1);
            temp[i] = 1+'0';
            generateCombHelper(temp, i+1);
            break;
        }
    }
    return;
}

vector<string> generateCombinations(string str) {
    vector<string> ans;
    if(!str.size()) {
        return ans;
    }
    Combinations *combination = new Combinations();
    combination->generateCombHelper(str, 0);
    cout << "\nfinal ans:";
    combination->printAns();
    return ans;
}

int main() {
    string str = "01?0??";
    generateCombinations(str);

    return 0;
}
