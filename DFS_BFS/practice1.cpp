#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*각 도시들의 연결 관계를 저장해 둘 벡터와
  도시로 가는 거리 정보를 저장해 둘 배열 생성*/
vector<int> v[300001];
int distances[300001];

/*concept2 문제랑 동일하게 너비 우선 탐색을
  하면서 각 도시 노드 방문시 거리를 1씩
  늘려주는 방식으로 거리 정보 저장*/
void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int a = 0; a < v[x].size(); a++){
            int y = v[x][a];
            if(!distances[y]){
                distances[y] = distances[x] + 1;
                q.push(y);
            }
        }
    }
}

int main(){
    vector<int> answer;
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for(int a = 0; a < m; a++){
        int i , j;
        cin >> i >> j;
        v[i].push_back(j);
    }

    bfs(x);

    for(int b = 0; b < 300001; b++){
        if(distances[b] == k){
            answer.push_back(b);
        }
    }
    sort(answer.begin(), answer.end());
    
    for(int c = 0; c < answer.size(); c++){
        cout << answer[c] << endl;
    }
    if(answer.size() == 0){
        cout << "-1" << endl;
    }
    return 0;
}