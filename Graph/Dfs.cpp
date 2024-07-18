class Solution {
    private:
    void solveForDfs(int node, vector<int> &ans, unordered_map<int, bool> &visited, vector<int> adj[] ){
        ans.push_back(node);
      if(visited[0]!=true){
          visited[0]= true;
           
      }
        for(auto i: adj[node]){
            if(!visited[i]){
                visited[i]= true;
            solveForDfs(i, ans, visited, adj);
            
        }
            
        }
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //creating the answer of the vecor
        vector<int> ans;
        ///// creating the unordered map for tracking named visited
        unordered_map<int , bool> visited;
        
        //call the function;
        solveForDfs(0, ans, visited, adj);
        return ans;
        
        
    }
};