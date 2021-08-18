#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    // 점수를 다 더한 후에 유일한 최고점 / 최저점 여부 파악해서 학점을 계산
    string answer = "";
    for(int i = 0; i < scores.size(); ++i){
        int max = 0;
        int maxcnt = 0;
        int min = 100;
        int mincnt = 0;
        double sum = 0; // 소숫점 가능
        double average = 0; // 소숫점 가능
        
        // 점수 연산(다 더하기)
        for (int j = 0; j < scores. size(); ++j){
            if (scores[j][i] > max) {
                max = scores[j][i];
                maxcnt = 1;
            }
            else if (scores[j][i] == max) maxcnt++;
            
            if (scores[j][i] < min) {
                min = scores[j][i];
                mincnt = 1;
            }
            else if (scores[j][i] == min) mincnt++;
            
            sum += scores[j][i];
        }
        
        // 자기 자신에게 평가한 점수가 max or min인지 확인
        if ((scores[i][i] == max && maxcnt == 1) || (scores[i][i] == min && mincnt == 1)) {
            sum -= scores[i][i];
            average = sum / (scores.size() - 1); // 소숫점이 나올 수 있기 때문에 sum과 average를 double형태로
        }
        else {
            average = sum / scores.size(); // 소숫점이 나올 수 있기 때문에 sum과 average를 double형태로
        }
        
        cout << average;
        
        // 학점 부여
        if (average >= 90) answer += "A";
        else if (average < 90 && average >= 80) answer += "B";
        else if (average < 80 && average >= 70) answer += "C";
        else if (average < 70 && average >= 50) answer += "D";
        else if (average < 50) answer += "F";
    }
    
    return answer;
}
