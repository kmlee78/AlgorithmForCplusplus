#include <iostream>

using namespace std;

/*계산된 정보들을 저장하기 위한 테이블*/
int d1[100], d2[100];

/*탑다운 방식으로 피보나치 수열 나타내기*/
int fibo(int num){
    if(num == 1 || num == 2) return 1;
    if(d1[num] != 0) return d1[num];
    d1[num] = fibo(num-1) + fibo(num-2);
    return d1[num];
}

int main(){
    cout << fibo(10) << endl;

    /*바텀업 방식으로 피보나치 수열 나타내기*/
    d2[1] = 1, d2[2] = 1;
    for(int a = 3; a <= 10; a++){
        d2[a] = d2[a-1] + d2[a-2];
    }
    cout << d2[10] << endl;

    return 0;
}