#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int main(){
   int n, grade;
   string name;
   vector<pair<string, int>> chart;
   cin >> n;

   /*pair을 사용해 (이름, 점수) 형식으로 값을
     저장하고 두번째 값인 점수를 기준으로 정렬*/
   for(int a = 0; a < n; a++){
        cin >> name >> grade;
        chart.push_back(pair<string, int>(name, grade));
   }
   sort(chart.begin(), chart.end(), comp);
   
   for(int b = 0; b < n; b++){
        cout << chart[b].first << " ";
   }
   return 0;
}