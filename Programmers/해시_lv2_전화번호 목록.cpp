#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    int size_ = phone_book.size();
    for (int i = 0; i < size_; i++) {
        int s = phone_book[i].size();
        for (int j = 0; j < size_; j++) {
            
            if (s > phone_book[j].size()) continue;
            if (i == j) continue;
            //cout << phone_book[i] << " " << phone_book[j].substr(0, s) << " ";
            if (phone_book[i].compare(phone_book[j].substr(0, s)) == 0) {
                //cout << "O" << endl;
                answer = false;
                return false;
            }
            //cout << "X" << endl;
        }
    }

    return answer;
}

int main() {
    string a_[] = { "123", "456", "789" };
    
    vector<string> a;
    a.assign(a_, a_ + 3);


    cout << solution(a) << endl;

    return 0;
}