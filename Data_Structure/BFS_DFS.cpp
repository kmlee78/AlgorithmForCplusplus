#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v_bfs[8];
int check_bfs[8];
vector<int> v_dfs[8];
int check_dfs[8];

void bfs(int start){
    queue<int> q;
    q.push(start);
    check_bfs[start] = true;

    while(!q.empty()){
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int a = 0; a < v_bfs[x].size(); a++){
            int y = v_bfs[x][a];
            if(!check_bfs[y]){
                q.push(y);
                check_bfs[y] = true;
            }
        }
    }
}

void dfs(int x){
    if(check_dfs[x]) return;
    check_dfs[x] = true;
    cout << x << " ";
    for(int a = 0; a < v_dfs[x].size(); a++){
        int y = v_dfs[x][a];
        dfs(y);
    }
}

int main(){
    v_bfs[1].push_back(2);
    v_bfs[1].push_back(2);
    v_bfs[2].push_back(1);
    v_bfs[2].push_back(3);
    v_bfs[2].push_back(4);
    v_bfs[2].push_back(5);
    v_bfs[3].push_back(1);
    v_bfs[3].push_back(2);
    v_bfs[3].push_back(6);
    v_bfs[3].push_back(7);
    v_bfs[4].push_back(2);
    v_bfs[4].push_back(5);
    v_bfs[5].push_back(2);
    v_bfs[5].push_back(4);
    v_bfs[6].push_back(3);
    v_bfs[6].push_back(7);
    v_bfs[7].push_back(3);
    v_bfs[7].push_back(6);
    cout << "bfs: ";
    bfs(1);
    cout << endl;
    v_dfs[1].push_back(2);
    v_dfs[1].push_back(2);
    v_dfs[2].push_back(1);
    v_dfs[2].push_back(3);
    v_dfs[2].push_back(4);
    v_dfs[2].push_back(5);
    v_dfs[3].push_back(1);
    v_dfs[3].push_back(2);
    v_dfs[3].push_back(6);
    v_dfs[3].push_back(7);
    v_dfs[4].push_back(2);
    v_dfs[4].push_back(5);
    v_dfs[5].push_back(2);
    v_dfs[5].push_back(4);
    v_dfs[6].push_back(3);
    v_dfs[6].push_back(7);
    v_dfs[7].push_back(3);
    v_dfs[7].push_back(6);
    cout << "dfs: ";
    dfs(1);
}
