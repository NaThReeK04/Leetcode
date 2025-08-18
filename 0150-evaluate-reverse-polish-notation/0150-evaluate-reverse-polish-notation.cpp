class Solution
{
    public: int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else 
            {
                int second=st.top();st.pop();
                int first=st.top();st.pop();
                if (tokens[i] == "+")
                {
                    int result = first + second;
                    st.push(result);
                }
                else if (tokens[i] == "-")
                {
                    int result = first - second;
                    st.push(result);
                }
                else if (tokens[i] == "*")
                {
                    int result = first * second;
                    st.push(result);
                }
                else
                {
                    int result = first / second;
                    st.push(result);
                }
            }
        }
        if (!st.empty()) return st.top();
        return -1;
    }
};