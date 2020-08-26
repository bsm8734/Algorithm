#include <iostream>
#include <string.h>
using namespace std;

int R, C, M;
int shark[10001][5]; // r, c, 2방향, 3속력, 4크기 // shark[1][]~shark[M][]
int map[101][101] = { 0 };
int tmp_map[101][101] = { 0 };
int result = 0;
pair<int, int> cal_helper[5] = { {0,0}, {0, 1}, {0, 0}, {1, 0}, {1, 1} }; // 0:R,1:C  // 0:+,1:-
int RC_helper[2];
int op_dir[5] = { 0,2,1,4,3 };

void hunt_shark(int y) {
    for (int i = 0; i < R; i++)
        if (map[i][y] != 0) {
            // cout << "hunt!! " << shark[map[i][y]][4] << endl;
            int target = map[i][y];
            map[i][y] = 0;
            result += shark[target][4];
            return;
        }
}

void move_shark() {
    for (int a = 0; a < R; a++)
        for (int b = 0; b < C; b++)
            if (map[a][b] != 0) {
                int target = map[a][b];
                int RC = cal_helper[shark[target][2]].first;   // 0 or 1
                int pm = cal_helper[shark[target][2]].second;   // 0 or 1

                int cur = shark[target][RC];   // 행열 따지지 않고 (현재 좌표)값 저장
                int rc = RC_helper[RC] - 1;      // 행열 따지지 않고 (격자판의 크기)값 저장
                int v = shark[target][3];      // 속력 저장
                int dir_updater = shark[target][2]; // 방향 업데이트 저장

                // 경우의 수
                if (pm == 1)  // <-
                    if (v <= cur)
                        v = cur - v;  // 범위 내 움직임
                    else {
                        v -= cur;
                        v %= (rc * 2);
                        if (v > rc) v = (rc * 2) - v;
                        else dir_updater = op_dir[dir_updater];
                    }
                else if (pm == 0)  // ->
                    if (v <= (rc - cur)) v = cur + v; // 범위 내 움직임
                    else {
                        v -= (rc - cur);
                        v %= (rc * 2);
                        if (v > rc) v = (rc * 2) - v;
                        else dir_updater = op_dir[dir_updater];
                        v = rc - v;
                    }

                // 상어의 위치 업데이트
                shark[target][RC] = v;
                if (RC == 0) { // R
                    if (shark[tmp_map[v][b]][4] < shark[target][4]) tmp_map[v][b] = target;
                    if (v == 0) dir_updater = 2;
                    else if (v == rc) dir_updater = 1;
                }
                else if (RC == 1) { // C
                    if (shark[tmp_map[a][v]][4] < shark[target][4]) tmp_map[a][v] = target;
                    if (v == 0) dir_updater = 3;
                    else if (v == rc) dir_updater = 4;
                }

                // 상어의 방향 업데이트
                shark[target][2] = dir_updater;
            }
    for (int a = 0; a < R; a++) 
        for (int b = 0; b < C; b++) {
            map[a][b] = tmp_map[a][b];
            tmp_map[a][b] = 0;
        }

}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // input
    cin >> R >> C >> M;
    RC_helper[0] = R;
    RC_helper[1] = C;
    for (int i = 1; i <= M; i++) {
        cin >> shark[i][0] >> shark[i][1] >> shark[i][3] >> shark[i][2] >> shark[i][4];
        shark[i][0]--; shark[i][1]--;
        map[shark[i][0]][shark[i][1]] = i;
    }

    for (int T = 0; T < C; T++) { // step1: move fisher
        for (int a = 0; a < R; a++) {
            for (int b = 0; b < C; b++) {
             //   cout << shark[map[a][b]][4] << '(' << shark[map[a][b]][2] << ") ";
            }
          //  cout << endl;
        }
        

       // step2
        hunt_shark(T);
        // step3
        move_shark();

      ///  cout << endl;
    }
    for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
         //   cout << shark[map[a][b]][4] << '(' << shark[map[a][b]][2] << ") ";
        }
      //  cout << endl;
    }


    cout << result << '\n';

    return 0;
}