#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    using LL = long long;

    static constexpr LL P = (1LL << 31) - 1;
    static constexpr LL BASE = 41;

    LL getHash(const string &s) {
        LL hashValue = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            hashValue = hashValue * BASE + s[i] - 'a' + 1;
            hashValue = hashValue % P;
        }
        return hashValue;
    }

    int respace(vector<string>& dictionary, string sentence) {
        unordered_set <LL> hashValues;
        for (const auto &word: dictionary) {
            hashValues.insert(getHash(word));
        }

        vector <int> f(sentence.size() + 1, sentence.size());

        f[0] = 0;
        for (int i = 1; i <= sentence.size(); ++i) {
            f[i] = f[i - 1] + 1;
            LL hashValue = 0;
            for (int j = i; j >= 1; --j) {
                int t = sentence[j - 1] - 'a' + 1;
                hashValue = hashValue * BASE + t;
                hashValue = hashValue % P;
                if (hashValues.find(hashValue) != hashValues.end()) {
                    f[i] = min(f[i], f[j - 1]);
                }
            }
        }

        return f[sentence.size()];
    }
};

