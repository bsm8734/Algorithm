#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int xy[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};
int R, C;
int arr[12][12] = {0,};
int arr_new[12][12];
string s;
int r_st, r_end;
int c_st, c_end;

void make_ocean(){
    copy(&arr[0][0], &arr[0][0] + 12 * 12, &arr_new[0][0]);
    for(int i = 0; i < R; i++)
        for(int j = 0; j <C; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int x_ = i + xy[k][0];
                int y_ = j + xy[k][1];
                if (x_ < 0 || x_ >= R || y_ < 0 || y_ >= C) cnt++;
                else if(arr[x_][y_] == 0) cnt++;
            }
            if(cnt >= 3) arr_new[i][j] = 0;
        }
    copy(&arr_new[0][0], &arr_new[0][0] + 12 * 12, &arr[0][0]);
}

void add_map_info(){
    // sum all lines
    for (int i = 0; i < R; i++){
        int sum_r = 0;
        for (int j = 0; j < C; j++)
            sum_r += arr[i][j];
        arr[i][C] = sum_r;
    }

    for (int j = 0; j < C; j++){
        int sum_c = 0;
        for (int i = 0; i < R; i++)
            sum_c += arr[i][j];
        arr[R][j] = sum_c;
    }

    // get start, end points
    for (int i = 0; i < R; i++)
        if (arr[i][C] != 0) {
            r_st = i;
            break;
        }
    for (int i = R - 1; i >= 0; i--)
        if (arr[i][C] != 0){
            r_end = i;
            break;
        }

    for (int i = 0; i < C; i++)
        if (arr[R][i] != 0){
            c_st = i;
            break;
        }
    for (int i = C - 1; i >= 0; i--)
        if (arr[R][i] != 0){
            c_end = i;
            break;
        }
}

void print_map(){
    for (int i = r_st; i <= r_end; i++) {
        for (int j = c_st; j <= c_end; j++)
            if (arr[i][j] == 0)
                cout << '.';
            else cout << 'X';
        cout <<'\n';
    }
}
        
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // input
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++)
            if (s[j] == 'X') arr[i][j] = 1;
    }
    r_st = 0; r_end = R - 1;
    c_st = 0; c_end = C - 1;

    make_ocean();
    add_map_info();
    print_map();

    return 0;
}