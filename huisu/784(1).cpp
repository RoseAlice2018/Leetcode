class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result{S};
        for (int i = 0; i < S.size(); i++) {
            if (isupper(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = tolower(temp[i]);
                    result.emplace_back(move(temp));
                }
            } else if (islower(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = toupper(temp[i]);
                    result.emplace_back(move(temp));
                }
            }
        }
        return result;
    }
};