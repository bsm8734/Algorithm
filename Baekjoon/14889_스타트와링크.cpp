#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N, result = 10000;
int arr[30][30] = { 0 };
int team_score[2] = { 0 };
vector<int> team_matching;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < (N / 2); i++) team_matching.push_back(0);
	for (int i = 0; i < (N / 2); i++) team_matching.push_back(1);

	// sort(team_matching.begin(), team_matching.end());	
	
	do {
		team_score[0] = team_score[1] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (team_matching[i] == team_matching[j])
					team_score[team_matching[i]] += arr[i][j];
			}
		}

		result = min(result, abs(team_score[0] - team_score[1]));
	} while (next_permutation(team_matching.begin(), team_matching.end()));

	cout << result << '\n';

	return 0;
}