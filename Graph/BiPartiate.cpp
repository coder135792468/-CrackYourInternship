bool dfs(int src, vector<int> adj[], vector<int>& col)
    {
        for(auto it : adj[src])
        {
            if(col[it] == col[src])
            {
                return false;
            }
            
            if(col[it] == -1)
            {
                if(col[src] == 1)
                {
                    col[it] = 0;
                }
                else
                {
                    col[it] = 1;
                }
                if(!dfs(it, adj, col))
                {
                    return false;
                }
            }
        }
        return true;
    }
    


	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int> col(v,-1);
	    
	    for(int i = 0; i<v ;i++)
	    {
	        if(col[i] == -1)
	        {
	            col[i] = 0;
	            if(!dfs(i, adj, col))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}