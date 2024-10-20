class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.length();
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (c == ',') {
                continue;
            }
            if (c != ')') {
                st.push(c);
            } else {
                vector<char> values;
                while (!st.empty() && st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); 
                char op = st.top();
                st.pop();

                bool result;
                if (op == '!') {
                    result = (values[0] == 'f');
                } else if (op == '&') {
                    result = true;
                    for (char v : values) {
                        if (v == 'f') {
                            result = false;
                            break;
                        }
                    }
                } else if (op == '|') {
                    result = false;
                    for (char v : values) {
                        if (v == 't') {
                            result = true;
                            break;
                        }
                    }
                }

                st.push(result ? 't' : 'f');
            }
        }
        
        return st.top() == 't';
    }
};
