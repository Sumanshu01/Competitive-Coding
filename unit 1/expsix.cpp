#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (words.find(endWord) == words.end()) return 0;
    queue<pair<string, int> > q;
    q.push(make_pair(beginWord, 1));
    words.erase(beginWord);
    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == endWord) return steps;
        for (size_t i = 0; i < word.size(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (words.find(word) != words.end()) {
                    q.push(make_pair(word, steps + 1));
                    words.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main() {
    string beginWord, endWord;
    int n;
    cin >> beginWord >> endWord >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; ++i)
        cin >> wordList[i];
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
