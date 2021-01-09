#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int num = arr.size();
    for (int i = 0; i < num; i++)
        answer += arr[i];
    answer = (answer / num);// + (answer % num);
    return answer;
}