#include <iostream>

using namespace std;

/*시험관의 형태를 나타내줄 배열 grid와
  방향벡터를 사용할 수 있는 배열 dx, dy 정의*/
int n, k;
int grid[201][201];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void infection(){

    /*1 부터 k 까지 순서대로 감염 진행. 해당 자리가 0일 때만
      바이러스가 전염되고 그 이외에는 무시*/
    for(int virus = 1; virus <= k; virus++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j] == virus){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        /*이 부분이 제일 중요하다. 1초에 한칸씩만 감염이 되어야 하는데 
                          grid 배열을 탐색하다 이미 해당 시간에 전염이 된 위치에 대해서 
                          또 한번 더 전염 수행을 하는 불상사가 발생할 수 있기 때문에 virus 값을
                          그대로 넣어주는 것이 아닌 virus + k + 1 을 넣어준다.*/
                        if(nx > 0 && nx <= n && ny > 0 && ny <= n && grid[nx][ny] == 0)
                            grid[nx][ny] = virus + k + 1;
                    }
                }
            }
        }
    }

    /*그리고 그 후에 grid 내의 모든 값들을 k+1로 나눈 나머지 값들로
      채워넣어 다시 정상적인 값을 가지도록 해준다.*/
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j] %= k+1;
        }
    }
}

int main(){
    int s, x, y;
    cin >> n >> k;
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            cin >> grid[a][b];
        }
    }
    cin >> s >> x >> y;

    /*총 s번의 전염 수행*/
    for(int a  = 0; a < s; a++){
        infection();
    }
    cout << grid[x][y] << endl;
    return 0;
}