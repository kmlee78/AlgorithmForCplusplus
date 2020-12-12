#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
/*미로의 정보를 담을 201칸 짜리 2차원 벡터*/
vector<vector<int>> maze(201, vector<int>(201, 0));
/*방향 정보를 담은 배열*/
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/*이 문제는 너비 우선 탐색을 사용하여야 한다*/
int bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(pair<int, int>(a, b));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            /*미로의 범위를 벗어나거나 괴물이 
              있는 부분인 경우는 무시*/
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maze[nx][ny] == 0) continue;

            /*해당 노드를 처음 방문하는 경우에만
              인접했던 노드에 저장된 최단거리 값에
              1을 더해 최단거리 기록*/
            if(maze[nx][ny] == 1){
                maze[nx][ny] = maze[x][y] + 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
    /*(n,m)위치에 저장되어 있는 최단거리 값 리턴*/
    return maze[n-1][m-1];
}

int main(){
    cin >> n >> m;
    string position;
    for(int a = 0; a < n; a++){
        /*일단 각 줄을 문자열로 받고 문자열의 문자 
          하나하나를 숫자형으로 변환해서 벡터에 넣어줌*/
        cin >> position;
        for(int b = 0; b < m; b++){
            maze[a][b] = position[b] - '0';
        }
    }

    /*맨 왼쪽 위 부터 너비 우선 탐색 시작*/
    cout << bfs(0, 0) << endl;
    return 0;
}
