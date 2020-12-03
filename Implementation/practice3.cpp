#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    vector<int> answer;
    int length = s.length();
    string old, news, temp;
    int counting;

    /*주어진 문자열 길이가 1이면 답은 1*/
    if(length == 1) return 1;
    
    /*문자열 전체 길이의 절반을 넘는 단위로 자를 순 
      없으니 1 부터 length/2 까지 반복문 수행*/
    for(int standard = 1; standard <= length/2; standard++){
        /*임의로 문자열을 담아줄 temp와
          반복되는 문자열의 수를 나타내줄
          counting 변수 초기화*/
        temp = "";
        counting = 1;
        old = s.substr(0, standard);
        temp += old;
        int step = 0;
        for(step = standard; step <= length-standard; step += standard){
            news = s.substr(step, standard);

            /*이전 과정에서 단위 길이로 자른 문자열을 old,
              현재 과정에서 단위 길이로 자른 문자열을 news로 정한다.
              다르면 temp에 이어 붙여주고 같으면 counting만 늘린다.*/
            if(news == old){
                counting++;
            }else{
                temp += news;

                /*counting이 1 이상일 때에만 문자열로 변환 후
                  temp에 이어 붙여준다.*/
                if(counting != 1){
                    temp += to_string(counting);
                }
                counting = 1;
            }
            old = news;
        }

        /*반복문이 끝난 이후 미처 붙이지 못했던 숫자나 
          문자열이 있으면 붙여준다.*/
        if(counting != 1){
            temp += to_string(counting);
        }
        for(int a = step; a < length; a++){
            temp += s[a];
        }
        answer.push_back(temp.length());
    }

    /*가장 짧은 문자열 탐색*/
    sort(answer.begin(), answer.end());
    return answer.front();
}                                                                                                       