#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        int s = 0;

        for (auto & it : strs)
        {
            s += it.size() + 2;
        }

        string res;
        res.reserve(s);

        for (auto & it : strs)
        {
            res += to_string(it.size()) + "#" + it;
        }

        cout << s << "\n";
        cout << res.size() << "\n";

        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        
    }
};

int main()
{
    Solution s;
    vector<string> strs{"lint","code","love","you"};
    cout << s.encode(strs);

    return 0;
}
