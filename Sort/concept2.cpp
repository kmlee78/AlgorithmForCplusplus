#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int i, int j){
    return i > j;
}

int main(){
   int n, k, num, sum = 0;
   cin >> n >> k;
   vector<int> v1;
   vector<int> v2;
   for(int a = 0; a < n; a++){
        cin >> num;
        v1.push_back(num);
   }
   for(int a = 0; a < n; a++){
        cin >> num;
        v2.push_back(num);
   }

   /*v1은 오름차순, v2는 내림차순으로 정렬해
     v2는 가장 앞 k개를 , v1은 가장 뒤 k개를 
     선택해 sum에 더해준다.*/
   sort(v1.begin(), v1.end());
   sort(v2.begin(), v2.end(), comp);
   
   for(int a = k; a < v1.size(); a++){
        sum += v1[a];
   }
   for(int a = 0; a < k; a++){
        sum += v2[a];
   }

   cout << sum << endl;
   return 0;
}
