#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
   int n, location, sum;
   vector<int> house;
   vector<pair<int, int>> time;
   cin >> n;

   /*집의 위치를 받은 벡터를 계산하기 편하게
     정렬 수행.*/
   for(int a = 0; a < n; a++){
        cin >> location;
        house.push_back(location);
   }
   sort(house.begin(), house.end());

   /*(각 집까지 거리의 총합, 안테나의 위치) 를 담은
     pair을 time 이라는 벡터에 넣어주고 정렬한다.*/
   for(int a = house.front(); a < house.back(); a++){
        sum = 0;
        for(int b = 0; b < n; b++){
            sum += abs(a - house[b]);
        }
        time.push_back(pair<int, int>(sum, a));
   }
   sort(time.begin(), time.end());

   cout << time[0].second << endl;
   return 0;
}