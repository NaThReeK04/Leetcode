class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size());
        stack<int>st;
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                int j=st.top();st.pop();
                ans[j]=i-j;
            }
            st.push(i);
        }
        return ans;
    }
};