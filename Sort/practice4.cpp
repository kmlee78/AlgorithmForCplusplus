#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
   int n, number, total = 0, sum;
   priority_queue<int> numbers;
   vector<int> addition;
   cin >> n;

   /*항상 가장 작은 크기의 두 카드 묶음을
     합쳤을 때 최적의 해를 보장하므로
     우선순위 큐를 사용한다. 가장 작은 값이
     top에 오게 하기 위해 큐에 값을 넣거나 
     큐에서 값을 꺼낼 때 (-)를 붙여준다.*/
   for(int a = 0; a < n; a++){
        cin >> number;
        numbers.push(-number);
   }

   while(!numbers.empty()){
        sum = -numbers.top();
        numbers.pop();
        sum -= numbers.top();
        numbers.push(-sum);
        numbers.pop();
        addition.push_back(sum);
   }
   for(int a = 0; a < n-1; a++){
        total += addition[a];
   }
   
   cout << total << endl;
   return 0;
}
