class Solution {
public:
    
    void helper(vector<vector<int>>& arr,int i, int j,int color,int newCol){
           if(i<0 or j< 0 or i>= arr.size() or j>= arr[0].size() or arr[i][j] != newCol)return;
        
        arr[i][j] = color;
        helper(arr,i+1,j,color,newCol);
        helper(arr,i,j+1,color,newCol);
        helper(arr,i-1,j,color,newCol);
        helper(arr,i,j-1,color,newCol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)return image;
        helper(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};