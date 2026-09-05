class Solution {
public:
    int rank[2005];
    int parent[2005];
    int find(int x)
    {
        if(x==parent[x])
            return x;
        else return parent[x]=find(parent[x]);
    }

    void unionfind(int x,int y)
    {
        int px=find(x);
        int py=find(y);

        if(px!=py)
        {
            if(rank[px]<rank[py])
                parent[px]=py;
            else if(rank[py]<rank[px])
                parent[py]=px;
            else 
            {
                parent[py]=px;
                rank[px]++;
            }
            //return true;
        }
        //return false;
        return;

    }
    int countComponents(int n, vector<vector<int>>& edges) {

            for(int i=0;i<n;i++)
                {
                    rank[i]=1;
                    parent[i]=i;
                }
            for(int i=0;i<edges.size();i++)
                unionfind(edges[i][0],edges[i][1]);
            int count=0;
            for(int i=0;i<n;i++)
                if(parent[i]==i)
                    count++;
            return count;
    }
};
