class Cell{
    public:
    int price;
    int dist;
    int row;
    int col;
    Cell(int row, int col, int dist, int price):row(row), col(col), dist(dist), price(price){} 
};

class Compare
{
public:
    bool operator() (Cell* c1, Cell* c2)
    {
        if(c1->dist != c2->dist){
            return (c1->dist < c2->dist);
        }
        
        if(c1->price != c2->price){
            return (c1->price < c2->price);
        }
        
        if(c1->row != c2->row){
            return (c1->row < c2->row);
        }
        return c1->col < c2->col;
    }
};

vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        priority_queue<Cell*,vector<Cell*>, Compare>pq;
        queue<pair<pair<int, int>, int>> bfsQueue;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        bfsQueue.push(make_pair(make_pair(start[0], start[1]), 0));
        visited[start[0]][start[1]] = 1;
        
        while(!bfsQueue.empty()){
            pair<pair<int, int>, int> curr = bfsQueue.front();
            int row = curr.first.first, col = curr.first.second, dist = curr.second;
            
            bfsQueue.pop();
            if(grid[row][col] >= pricing[0]
               && grid[row][col] <= pricing[1]){
                pq.push(new Cell(row, col, dist, grid[row][col]));
                if(pq.size() > k){
                    pq.pop();
                }
            }
            

            for(int i = 0; i < dir.size(); i++){     
                if(row+dir[i][0] >= grid.size() || row+dir[i][0] < 0){
                    continue;
                }

                if(col+dir[i][1] >= grid[0].size() || col+dir[i][1] < 0){
                    continue;
                }

                if(visited[row+dir[i][0]][col+dir[i][1]] == 1){
                    continue;
                }
                
                if(grid[row+dir[i][0]][col+dir[i][1]] == 0){
                    continue;
                }
                
                visited[row+dir[i][0]][col+dir[i][1]] = 1;
                bfsQueue.push(make_pair(make_pair(row+dir[i][0], col+dir[i][1]), dist+1));
            }
        }
                      
        vector<vector<int>> sol;
        while(!pq.empty()){
            Cell* cell = pq.top();
            sol.push_back({cell->row, cell->col});
            pq.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};