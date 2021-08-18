#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    // pricesum을 구한 후에 money와 비교
    long long answer = 0;
    long long pricesum = 0;
    for (int i = 1; i <= count; ++i){
        pricesum += price*i;
    }

    answer = pricesum - money;
    if (answer < 0) answer = 0;
    return answer;
}
