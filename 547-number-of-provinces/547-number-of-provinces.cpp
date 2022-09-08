class Solution {
public:
    int find(int x, int parent[]){
        if(parent[x]==x) return x;
        else return find(parent[x], parent);
        
    }
    
    void _union(int x, int y, int parent[]){
        int x_rep=find(x, parent);
        int y_rep=find(y, parent);
        if(x_rep==y_rep) return;
        else{
            parent[y_rep]=x_rep;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int parent[n];
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(M[i][j]) _union(i, j, parent);
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(i==parent[i]) ans++;
        }
        return ans;
    }
};