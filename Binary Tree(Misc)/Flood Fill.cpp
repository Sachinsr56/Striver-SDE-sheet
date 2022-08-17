#define vvi vector<vector<int>> 
class Solution {
    void solve(vvi &image,int sr,int sc,int newColor,int rows,int cols,int source){
        if(sr<0 || sr>=rows || sc<0 || sc>=cols){
            return;
        }
        else if(image[sr][sc]!=source)
            return;
        
        image[sr][sc]=newColor;
        solve(image,sr+1,sc,newColor,rows,cols,source);
        solve(image,sr-1,sc,newColor,rows,cols,source);
        solve(image,sr,sc+1,newColor,rows,cols,source);
        solve(image,sr,sc-1,newColor,rows,cols,source);
        
    }
public:
    vvi floodFill(vvi &image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int rows=image.size(),cols=image[0].size();
        int source=image[sr][sc];
        solve(image,sr,sc,color,rows,cols,source);
        return image;
    }
};