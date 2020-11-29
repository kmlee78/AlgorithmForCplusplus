#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   int n, number, total;
   vector<int> numbers;
   cin >> n;
   for(int a = 0; a < n; a++){
        cin >> number;
        numbers.push_back(number);
   }
   sort(numbers.begin(), numbers.end());

   /*입력받은 숫자들을 오름차순 정렬 후
     문제의 조건에 따라 연산 수행.*/
   int sum = numbers[0] + numbers[1];
   total = sum;
   for(int b = 2; b < n; b++){
        sum += numbers[b];
        total += sum;
   }

   cout << total << endl;
   return 0;
}
