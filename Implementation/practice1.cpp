#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, sum1 = 0 ,sum2 = 0;
    cin >> n;
    string score = to_string(n);
    int length = score.length();
    for(int a = 0; a < length/2; a++){
        sum1 += score[a] - '0';
        sum2 += score[a+length/2] - '0';
    }
    if(sum1 == sum2){
        cout << "LUCKY" << endl;
    }else{
        cout << "READY" << endl;
    }
    return 0;
}