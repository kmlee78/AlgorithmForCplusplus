#include <string>
#include <vector>

using namespace std;

/*key를 시계방향으로 90도 회전시켜주는 함수.
  2차원 벡터를 리턴해줘야 하기 때문에 자료형
  vector<vector<int>> 를 사용한다.*/
vector<vector<int>> rotation(vector<vector<int>>& v){
    vector<vector<int>> temp(v);
    int size = v.size();
    for(int a = 0; a < size; a++){
        for(int b = 0; b < size; b++){
            temp[a][b] = v[size-b-1][a];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int size = lock.size();
    int size2 = key.size();

    /*기존의 lock의 크기를 가로세로 3배씩 늘린 벡터가 bigger이다.
      bigger의 한가운데 부분만 lock과 동일하게 해주고 나머지 부분은
      1로 채운다. dft는 이런 bigger의 형태를 저장하기 위한 벡터이다.*/
    vector<vector<int>> bigger(size*3, vector<int> (size*3,1));
    vector<vector<int>> dft;
    for(int a = size; a < size*2; a++){
        for(int b = size; b < size*2; b++){
            if(lock[a-size][b-size] == 0) bigger[a][b] = 0;
        }
    }
    dft = bigger;

    /*총 4번의 회전을 해야 한다.*/
    for(int step = 0; step < 4; step++){
        key = rotation(key);

        /*key가 bigger의 왼쪽 위에서 부터 오른쪽 아래까지
          쓸고 내려간다.*/
        for(int a = 0; a <= 3*size-size2; a++){
            for(int b = 0; b <= 3*size-size2; b++){
                
                /*그리고 key가 bigger 내에서 한칸씩 움직일 때마다
                  key가 자물쇠를 열수 있는지 판단한다. 판단 과정에서
                  bigger의 값이 바뀌기 때문에 매 판단 수행 마다
                  bigger를 dft로 초기화 해준다.*/
                bigger = dft;
                for(int i = 0; i < size2; i++){
                    for(int j = 0; j < size2; j++){
                         /*key의 돌기 부분이 있으면 bigger의 원소값에
                          1을 더해주는 형태다. 만약 돌기와 돌기가 만나면
                          2가 된다.*/
                        if(key[i][j] == 1) bigger[i+a][j+b] += key[i][j];
                    }
                }
                bool correct = true;
                for(int c = size; c < size*2; c++){
                    for(int d = size; d < size*2; d++){
                        /*만약 bigger의 중앙 부분, 즉 실제 lock 부분에
                          만약 1이 아닌 값이 있다면 key가 자물쇠에 맞지
                          않다는 의미이므로 false가 된다.*/
                        if(bigger[c][d] != 1) correct = false; 
                    }   
                }
                /*판단 수행 중 자물쇠와 key가 맞는 경우가 생긴다면
                  곧바로 true를 리턴해 프로그램을 종료시킨다.*/
                if(correct) return true;

            }
        }
    }
    /*위와 같은 과정 속에서도 프로그램이 모든 반복문을 
      빠져 나온다면 key가 자물쇠에 맞는 경우가 없다는 뜻
      이므로 원래 false 값이었던 answer를 리턴한다.*/
    return answer;
}
