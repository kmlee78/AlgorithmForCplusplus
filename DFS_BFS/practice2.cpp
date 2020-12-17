#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lab[8][8]; 
int temp[8][8];
int n, m, stat;

/*방향벡터 설정. 바이러스가 있는 구역 마다
  모두 탐색 할 수 있도록 구현해야 됨*/
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


void dfs(int x, int y){
    for(int counting = 0; counting < 4; counting++){
        int nx = x + dx[counting];
        int ny = y + dy[counting];

        /*범위를 벗어나지 않는 구간 내에서 빈칸을
          만나면 바이러스 감염 후 해당 구간에 대해서
          dfs 한번 더 수행*/
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(temp[nx][ny] == 0){
                temp[nx][ny] = 2;
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    int answer;
    vector<pair<int, int>> space;
    vector<int> answers;
    cin >> n >> m;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            cin >> stat;
            lab[a][b] = stat;

            /*빈칸인 좌표를 모두 space 라는 벡터 안에
              pair의 형태로 저장해 줄 것이다*/
            if(stat == 0){
                space.push_back(pair<int, int>(a, b));
            }
        }
    }
    int space_size = space.size();

    /*벽을 3개 세워야 하므로 모든 빈칸에 대해서 
      벽을 3개 세울 수 있는 경우를 3중for문을 이용해서
      구현해준다*/
    for(int a = 0; a < space_size-2; a++){
        for(int b = a+1; b < space_size-1; b++){
            for(int c = b+1; c < space_size; c++){
                
                /*벽을 다른 방법으로 세우는 경우마다 answer 및 temp 초기화*/
                answer = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        temp[i][j] = lab[i][j];
                    }
                }

                /*빈칸의 좌표에 대한 정보를 저장해 놓은 space 벡터에서
                  벽을 세우기 위해 이렇게 좌표값을 불러온다*/
                temp[space[a].first][space[a].second] = 1;
                temp[space[b].first][space[b].second] = 1;
                temp[space[c].first][space[c].second] = 1;

                /*바이러스가 있는 칸에 대해서 dfs 수행*/
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(temp[i][j] == 2)
                            dfs(i, j);
                    }
                }

                /*안전영역의 크기를 구해서 answers 벡터에 삽입*/
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(temp[i][j] == 0)
                            answer++;
                    }
                }
                answers.push_back(answer);
            }
        }
    }
    /*가장 큰 안전영역의 크기 구하기*/
    sort(answers.begin(), answers.end());

    cout << answers.back() << endl;
    return 0;
}
