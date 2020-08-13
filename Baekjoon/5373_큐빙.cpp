#include <iostream>
#include <string.h>
#include <map>
using namespace std;

/* --- 다시풀어보자 --- */

int T, N;
map<char, int> m;

char color[6] = { 'w','y','r', 'o', 'g', 'b' };
char dir[6] = { 'U','D','F', 'B', 'L', 'R' };
char cmd[2];

int clock_dir = 0;
int target = 0;

char tmp[3][3];
char temp[3];
char cube[6][3][3];

// 0시계, 1반시계
int rotate_clock[2][3][3][2] = {
    { {{2,0}, {1,0}, {0,0}}, {{2,1}, {1,1}, {0,1}}, {{2,2}, {1,2}, {0,2}} },
    { {{0,2}, {1,2}, {2,2}}, {{0,1}, {1,1}, {2,1}}, {{0,0}, {1,0}, {2,0}} } };

int next_to[6][4] = { {3,5,2,4}, {2,5,3,4}, {0,5,1,4}, {0,4,1,5}, {0,2,1,3}, {0,3,1,2} };

int nexto[6][4][3][2] = {
    {{{0,2},{0,1},{0,0}},{{0,2},{0,1},{0,0}},{{0,2},{0,1},{0,0}},{{0,2},{0,1},{0,0}}},
    {{{2,0},{2,1},{2,2}},{{2,0},{2,1},{2,2}},{{2,0},{2,1},{2,2}},{{2,0},{2,1},{2,2}}},
    {{  {2,0},{2,1},{2,2}  },{  {0,0},{1,0},{2,0}  },{  {0,2},{0,1},{0,0}  },{  {2,2},{1,2},{0,2}  } },
    {{  {0,2},{0,1},{0,0}  },{  {0,0},{1,0},{2,0}  },{  {2,0},{2,1},{2,2}  },{  {2,2},{1,2},{0,2}  } },
    {{  {0,0},{1,0},{2,0}  },{  {0,0},{1,0},{2,0}  },{  {0,0},{1,0},{2,0}  },{  {2,2},{1,2},{0,2}  } },
    {{  {2,2},{1,2},{0,2}  },{  {0,0},{1,0},{2,0}  },{  {2,2},{1,2},{0,2}  },{  {2,2},{1,2},{0,2}  }} };

void init() {
    for (int t = 0; t < 6; t++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cube[t][i][j] = color[t];
}

void rotate_me() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = cube[target][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[target][i][j] = tmp[rotate_clock[clock_dir][i][j][0]][rotate_clock[clock_dir][i][j][1]];
}

void roll() {
    rotate_me();

    if (clock_dir == 0) {
        for (int i = 0; i < 3; i++)
            temp[i] = cube[next_to[target][3]][nexto[target][3][i][0]][nexto[target][3][i][1]]; // side, x, y

        for (int i = 3; i > 0; i--) {
            for (int j = 0; j < 3; j++)
                cube[next_to[target][i]][nexto[target][i][j][0]][nexto[target][i][j][1]] = cube[next_to[target][i - 1]][nexto[target][i - 1][j][0]][nexto[target][i - 1][j][1]]; // side, x, y
        }

        for (int i = 0; i < 3; i++)
            cube[next_to[target][0]][nexto[target][0][i][0]][nexto[target][0][i][1]] = temp[i]; // side, x, y
    }
    else {
        for (int i = 0; i < 3; i++)
            temp[i] = cube[next_to[target][0]][nexto[target][0][i][0]][nexto[target][0][i][1]]; // side, x, y

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cube[next_to[target][i]][nexto[target][i][j][0]][nexto[target][i][j][1]] = cube[next_to[target][i + 1]][nexto[target][i + 1][j][0]][nexto[target][i + 1][j][1]]; // side, x, y
        }

        for (int i = 0; i < 3; i++)
            cube[next_to[target][3]][nexto[target][3][i][0]][nexto[target][3][i][1]] = temp[i]; // side, x, y
    }
}


int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 6; i++)
        m.insert({ dir[i], i });

    cin >> T;
    while (T--) {
        init();         // cube color init
        cin >> N;
       
        while (N--) {
           
            cin >> cmd;
            target = m[cmd[0]]; // target
            if (cmd[1] == '+') clock_dir = 0; // rotation(clock) dir
            else clock_dir = 1;

            roll();
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cube[0][i][j];
            cout << endl;
        }

    }

    return 0;
}