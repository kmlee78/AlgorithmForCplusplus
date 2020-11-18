#include <iostream>
#include <vector>

using namespace std;

int main (){
    int N, M, K;
    vector<int> ball;
    cin >> N >> M;

    /*N개의 볼링공들 중 2개의 공들을
      조합할 수 있는 방법 수*/
    int answer = N * (N-1) / 2;
    for(int a = 0; a < N; a++){
        cin >> K;
        ball.push_back(K);
    }

    /*두 볼링공의 무게가 서로 같으면
      answer을 1씩 차감*/
    int size = ball.size();
    for(int b = 0; b < size; b++){
        for(int c = b+1; c < size; c++){
            if(ball[b] == ball[c])
                answer--;
        }
    }

    cout << answer << endl;
    return 0;
}