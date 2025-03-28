class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        
        vector<int>q1=q;

        sort(q.begin(),q.end());
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int n=grid.size();
        int m=grid[0].size();

        map<int,int>mp;
        mp[0]=0;

        pq.push({grid[0][0],0,0});

        int curr_maxi=grid[0][0];
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;

        while(!pq.empty() && curr_maxi<q.back()){
            int temp=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];

            pq.pop();
            curr_maxi=max(temp,curr_maxi);
            mp[curr_maxi]++;

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nr<n && nc<m && nc>=0 && vis[nr][nc]==0){
                    pq.push({grid[nr][nc],nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }

        int prev=0;
        for(auto &it:mp){
            it.second+=prev;
            prev=it.second;
        }

        vector<int>ans;

        for(auto it:q1){
            auto i=mp.upper_bound(it-1);
            i--;
            ans.push_back((*i).second);
        }

        return ans;
    }
};