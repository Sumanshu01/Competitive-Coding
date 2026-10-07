#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size(), i = 0;
    while (i < n) {
        int lineLen = words[i].size(), j = i + 1;
        while (j < n && lineLen + 1 + (int)words[j].size() <= maxWidth)
            lineLen += 1 + words[j++].size();
        int numWords = j - i;
        int totalSpaces = maxWidth - (lineLen - (numWords - 1));
        string line;
        line.reserve(maxWidth);
        line += words[i];
        if (numWords == 1 || j == n) {
            for (int k = i + 1; k < j; ++k) {
                line += ' ';
                line += words[k];
            }
            line.append(maxWidth - line.size(), ' ');
        } else {
            int gaps = numWords - 1;
            int spaceEach = totalSpaces / gaps;
            int extra = totalSpaces % gaps;
            for (int k = i + 1; k < j; ++k) {
                line.append(spaceEach + (k - i <= extra ? 1 : 0), ' ');
                line += words[k];
            }
        }
        result.push_back(line);
        i = j;
    }
    return result;
}

int main() {
    int n, maxWidth;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    cin >> maxWidth;
    vector<string> res = fullJustify(words, maxWidth);
    for (int i = 0; i < (int)res.size(); ++i)
        cout << "\"" << res[i] << "\"\n";
    return 0;
}
