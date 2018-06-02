//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define SORT(c) sort((c).begin(),(c).end())
#define ANS(ans) cout<<(ans)<<endl;
typedef vector<int> VI;


//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  for (int i = 0; i < (n); ++i)

int field[9][9];
int n;


void check(char player, int x, int y) {
	int me, you;
	if (player == 'B') {
		me = 1;
		you = 0;
	}
	else if (player == 'W') {
		me = 0;
		you = 1;
	}
	field[y][x] = me;
	int i, j;
	int flag;

	//右
	i = y, j = x + 1;
	flag = 1;

	while (true) {
		if (j >= 9) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			j++;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		FOR(k, x, j) {
			field[i][k] = me;
		}
	}
	//左
	i = y, j = x - 1;
	flag = 1;

	while (true) {
		if (j < 1) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			j--;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		FOR(k, j, x) {
			field[i][k] = me;
		}
	}
	//上
	i = y - 1, j = x;
	flag = 1;

	while (true) {
		if (i < 1) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i--;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		FOR(k, i, y) {
			field[k][x] = me;
		}
	}
	//下
	i = y + 1, j = x;
	flag = 1;

	while (true) {
		if (i >= 9) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i++;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		FOR(k, y, i) {
			field[k][x] = me;
		}
	}

	//左上
	i = y - 1, j = x - 1;
	flag = 1;

	while (true) {
		if (i < 1 || j < 1) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i--;
			j--;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		int num = abs(x - j);
		REP(k, num) {
			field[y - k][x - k] = me;
		}
	}
	//右上
	i = y - 1, j = x + 1;
	flag = 1;

	while (true) {
		if (i < 1 || j>8) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i--;
			j++;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		int num = abs(x - j);
		REP(k, num) {
			field[y - k][x + k] = me;
		}
	}
	//左下
	i = y + 1, j = x - 1;
	flag = 1;

	while (true) {
		if (i < 1 || j < 1 || i>8 || j>8) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i++;
			j--;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		int num = abs(x - j);
		REP(k, num) {
			field[y + k][x - k] = me;
		}
	}
	//右下
	i = y + 1, j = x + 1;
	flag = 1;

	while (true) {
		if (i < 1 || j < 1 || i>8 || j>8) {
			flag = 0;
			break;
		}

		if (field[i][j] == you) {
			i++;
			j++;
		}
		else if (field[i][j] == me) {
			break;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		int num = abs(x - j);
		REP(k, num) {
			field[y + k][x + k] = me;
		}
	}
}



int main() {


	cin >> n;

	char player;
	int x, y;

	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			field[i][j] = 8;
		}
	}
	field[4][4] = 0;
	field[5][4] = 1;
	field[4][5] = 1;
	field[5][5] = 0;



	REP(i, n) {
		cin >> player >> x >> y;
		check(player, x, y);
	}


	int black = 0;
	int white = 0;
	FOR(i, 1, 8) {
		FOR(j, 1, 8) {
			//cout << field[i][j];
			if (field[i][j] == 1) black++;
			if (field[i][j] == 0) white++;
		}
	}
	string strb, strw;
	if (black < 10) strb = '0' + to_string(black);
	else strb = to_string(black);
	if (white < 10) strw = '0' + to_string(white);
	else strw = to_string(white);

	cout << strb << "-" << strw<<" ";

	string winner;
	if (black > white) {
		winner = "The black won!";
	}
	else if (black < white) {
		winner = "The white won!";
	}
	else {
		winner = "Draw!";
	}

	cout << winner << endl;

	return 0;
}

