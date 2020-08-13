#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10][10] = { 0 };

int xy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int op_count[6] = { 0,4,2,4,4,1 };

int num_cctv = 0;
int result = 0;
int wall = 0;

bool visit[10][10] = { false };

vector<pair<pair<int, int>, int>> cctv; // { {x, y}, arr_num }

void mem_cpy(bool src[10][10], bool dst[10][10]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dst[i][j] = src[i][j];
}

int visit_counter() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (visit[i][j] == true) cnt++;
	
	return cnt;
}

// one direction, make visit true;
void watchable(int x, int y, int dir_x, int dir_y) {
	int cur_x = x + dir_x;
	int cur_y = y + dir_y;

	if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= M) return; // range out
	if (arr[cur_x][cur_y] == 6) return; // wall

	if (visit[cur_x][cur_y] == false && arr[cur_x][cur_y] == 0) {
		visit[cur_x][cur_y] = true;
	}
	watchable(cur_x, cur_y, dir_x, dir_y);
}

void DFS(int depth) { // make number of cases
	int x = cctv[depth].first.first;
	int y = cctv[depth].first.second;
	int cctv_type = cctv[depth].second;

	bool visit_tmp[10][10] = { false };

	mem_cpy(visit, visit_tmp);

	for (int k = 0; k < op_count[cctv_type]; k++) {
		int start = k;
		mem_cpy(visit_tmp, visit);
		if (cctv_type == 1) {
			watchable(x, y, xy[start][0], xy[start][1]);
		}
		else if (cctv_type == 2) {
			watchable(x, y, xy[start][0], xy[start][1]);
			watchable(x, y, xy[start + 2][0], xy[start + 2][1]);
		}
		else if (cctv_type == 3) {
			watchable(x, y, xy[start][0], xy[start][1]);
			start = (start + 1) % 4;
			watchable(x, y, xy[start][0], xy[start][1]);
		}
		else if (cctv_type == 4) {
			watchable(x, y, xy[start][0], xy[start][1]);
			start = (start + 1) % 4;
			watchable(x, y, xy[start][0], xy[start][1]);
			start = (start + 1) % 4;
			watchable(x, y, xy[start][0], xy[start][1]);
		}
		else if (cctv_type == 5) {
			watchable(x, y, xy[start][0], xy[start][1]);
			watchable(x, y, xy[start + 1][0], xy[start + 1][1]);
			watchable(x, y, xy[start + 2][0], xy[start + 2][1]);
			watchable(x, y, xy[start + 3][0], xy[start + 3][1]);
		}

		if (depth == num_cctv - 1) result = max(result, visit_counter());
		else DFS(depth + 1);
	}

	mem_cpy(visit_tmp, visit);

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (0 < arr[i][j] && arr[i][j] < 6)
				cctv.push_back({ { i, j }, arr[i][j] });
			else if (arr[i][j] == 6) wall++;
		}
	num_cctv = cctv.size();
	
	if(num_cctv > 0) DFS(0);

	result = (N * M) - num_cctv -wall - result;
	
	cout << result << '\n';

	return 0;
}

