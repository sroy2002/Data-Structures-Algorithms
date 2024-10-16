// Consider a rat placed at (0, 0) in a square matrix mat of order n*n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

//Expected Time Complexity: O(3n^2)
// Expected Auxiliary Space: O(l * x)
// Here l = length of the path, x = number of paths.

class Solution {
  private:
    bool isValid(int row, int col, int n){
        if(row<n && row>=0 && col<n && col>=0) return true;
        else return false;
    }
    void solve(int row, int col,int n,vector<vector<int>> &mat, string path,vector<string>&ans, vector<vector<int>>& vis,
        int drow[], int dcol[])
    {
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(isValid(nrow,ncol,n) && mat[nrow][ncol]==1 && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                solve(nrow,ncol,n,mat,path+dir[i],ans,vis,drow,dcol);
                vis[nrow][ncol]=0;
            }
        }
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n, 0));
         int drow[] = {+1,0,0,-1};
        int dcol[] = {0,-1,+1,0};
        if(mat[0][0]){
            vis[0][0]=1;
            solve(0,0,n,mat,"",ans,vis,drow,dcol);
        }
        return ans;
    }
};