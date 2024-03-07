class Solution {
public:
    vector<string> solutions;

    vector<string> generateParenthesis(int n) {
        stack<int> stack;
        recursiveGenerator(n, , stack);
        return solutions; 
    }

    void recursiveGenerator(int n, string s, stack<int>& stackTmp) {
        // base case:
        if (n == 0 && stackTmp.empty()) {
            solutions.push_back(s);
            return;
        }

        // choice 1: open
        if (n > 0) {
            s.push_back('(');
            stackTmp.emplace(0);
            // recursively call itself
            recursiveGenerator(n - 1, s, stackTmp);
            s.pop_back();
            stackTmp.pop();
        }

        // choice 2: close
        if (!stackTmp.empty()) {
            s.push_back(')');
            stackTmp.pop();
            // recursively call itself
            recursiveGenerator(n, s, stackTmp);
            s.pop_back();
            stackTmp.emplace(0);
        }
    }
};

