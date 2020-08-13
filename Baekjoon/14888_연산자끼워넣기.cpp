#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int N, n, n1, n2;
int min_res = 0, max_res = 0;
vector<int> num, result;
vector<char> op;
char op_grp[4] = { '+', '-', '*', '/' };


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num.push_back(n);
	}
	for (int i = 0; i < 4; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) op.push_back(op_grp[i]);
	}
	sort(op.begin(), op.end());
	do {
		n1 = num[0];
		for (int i = 0; i < N - 1; i++) {
			n2 = num[i + 1];
			if (op[i] == '+') n1 += n2;
			else if (op[i] == '-') n1 -= n2;
			else if (op[i] == '*') n1 *= n2;
			else if (op[i] == '/') {
				n1 /= abs(n2);
				n1 *= (n2 / abs(n2));
			}
		}
		result.push_back(n1);
	} while (next_permutation(op.begin(), op.end()));

	min_res = max_res = result[0];
	for (int i = 0; i < result.size(); i++) {
		min_res = min(min_res, result[i]);
		max_res = max(max_res, result[i]);
	}

	cout << max_res << '\n' << min_res << '\n';

	return 0;
}

/*
// 사칙연산 우선순위 고려한 코드

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

// variables
int N, n, min_ = 0, max_ = 0;
string target;
string ops[4] = { "+", "-", "*", "/" };

vector<string> op_cases, original, post;
vector<int> num_input, result;

stack<int> num;
stack<string> op;

// post_calculate
int post_calculate() {
	for (int i = 0; i < post.size(); i++) {
		target = post[i];
		if (target == "*" || target == "/" || target == "+" || target == "-") { // operator
			int n1 = num.top();
			num.pop();
			int n2 = num.top();
			num.pop();

			if (target == "*")		n2 = n2 * n1;
			else if (target == "/") n2 = n2 / n1;
			else if (target == "+") n2 = n2 + n1;
			else if (target == "-") n2 = n2 - n1;

			num.push(n2);
		}
		else { // number
			num.push(stoi(target));
		}
	}
	int res = num.top();
	num.pop();
	return res;
}

// in-order to post-order
void in2post() {
	post.clear();
	for (int i = 0; i < original.size(); i++) {
		target = original[i];
		if (target == "*" || target == "/") {
			if (op.empty()) op.push(target);
			else {
				while (!op.empty()) {
					if (op.top() == "+" || op.top() == "-") break;
					else {
						post.push_back(op.top());
						op.pop();
					}
				}
				op.push(target);
			}
		}
		else if (target == "+" || target == "-") {
			if (op.empty()) op.push(target);
			else {
				while (!op.empty()) {
					post.push_back(op.top());
					op.pop();
				}
				op.push(target);
			}
		}
		else { // number
			post.push_back(target);
		}
	}
	while (!op.empty()) {
		post.push_back(op.top());
		op.pop();
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num_input.push_back(n);
	}
	for (int i = 0; i < 4; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) op_cases.push_back(ops[i]);
	}

	// for all cases
	sort(op_cases.begin(), op_cases.end());
	do {
		// for one case & calculate & push_back result
		original.clear();
		original.push_back(to_string(num_input[0]));

		for (int i = 1; i < N; i++) {
			string str(op_cases[i - 1]);
			original.push_back(str);
			original.push_back(to_string(num_input[i]));
		}

		in2post();
		int tmp_res = post_calculate();
		result.push_back(tmp_res);

	} while (next_permutation(op_cases.begin(), op_cases.end()));

	min_ = max_ = result[0];
	for (int i = 0; i < result.size(); i++) {
		min_ = min(min_, result[i]);
		max_ = max(max_, result[i]);
	}
	cout << max_ << '\n' << min_ << '\n';

	return 0;
}

*/