class Solution {
public:
    int arrow = 0;
    int MAX = -1;
    pair<int,int> curPos = {0,0};
    
    map<pair<int,int>,int> mp;
    
    int getArrow(int dir) {
        if (dir == -2) {
            if (arrow == 0) {
                arrow = 3;
            } else if (arrow == 1) {
                arrow = 0;
            } else if (arrow == 2) {
                arrow = 1;
            } else if (arrow == 3) {
                arrow = 2;
            }
        } else if ( dir == -1) {
            if (arrow == 0) {
                arrow = 1;
            } else if (arrow == 1) {
                arrow = 2;
            } else if (arrow == 2) {
                arrow = 3;
            } else if (arrow == 3) {
                arrow = 0;
            }
        }
        return arrow;
    }
    
    pair<int,int> getDir(int arrow) {
        pair<int,int> p;
        if (arrow == 0) {
            p = {0, 1};
        } else if (arrow == 1) {
            p = {1, 0};
        } else if (arrow == 2) {
            p = {0, -1};
        } else if (arrow == 3) {
            p = {-1,0};
        }
        return p;
    }
    
    bool cannotGo(int x, int y, vector<vector<int>>& obstacles) {
        for (int i = 0; i < obstacles.size(); i++) {
            if (x == obstacles[i][0] && y == obstacles[i][1]) return true;
        }
        return false;
    }
    
    void move(int command, vector<vector<int>>& obstacles) {
        auto p = getDir(arrow);
        
        for (int i = 1; i <= command; i++) {
            
            if (mp.find({curPos.first + p.first, curPos.second + p.second}) != mp.end()) break;
            // if (cannotGo(curPos.first + p.first, curPos.second + p.second, obstacles)) break;
            curPos.first += p.first;
            curPos.second += p.second;
        }
    }
    
    void getMap(vector<vector<int>>& obstacles) {
        for (int i = 0; i < obstacles.size(); i++) {
            mp[{obstacles[i][0], obstacles[i][1]}]++;
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        getMap(obstacles);
        for (int i = 0; i < commands.size(); i++) {
            int command = commands[i];
            if (command < 0) arrow = getArrow(command);
            else {
                move(command, obstacles);
                MAX = max((int)(pow(curPos.first,2) + pow(curPos.second, 2)), MAX);
            }
        }
        
        // ans = pow(curPos.first,2) + pow(curPos.second, 2);
        return MAX;
    }
};
