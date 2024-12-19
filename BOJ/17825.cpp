#include <iostream>

using namespace std;

int board[][24] = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40}, 
	{0,2,4,6,8,10,13,16,19,25,30,35,40}, 
	{0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40}, 
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40}
};

int ans;
int loc[4], path[4], dice[10], point[4] = { 21,13,17,23 };

bool canMove(int pos) {
	int n = board[path[pos]][loc[pos]];

	if (!n) 
        return 1;

	for (int i = 0; i < 4; i++) {
		if (i == pos) 
            continue;
		if (board[path[i]][loc[i]] != n) 
            continue;
		if (n == 16 || n == 22 || n == 24 || n == 26 || n == 28) {
			if ((loc[i] == loc[pos]) && (path[i] == path[pos])) 
                return 0;
		}
		else if (n == 30) {
			if (path[pos] == 0 && loc[pos] == 15) {
				if (loc[i] == 15) 
                    return 0;
			}
			else if (path[pos] == 3 && loc[pos] == 15) {
				if (path[i] == 3 && loc[i] == 15) 
                    return 0;
			}
			else {
				if (path[i] == 3 && loc[i] == 15) 
                    continue;
				return 0;
			}

		}
        else 
            return 0;
	}
	return 1;
}
void dfs(int dep, int score) {
	if (dep >= 10) {
		if (score > ans) 
            ans = score;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if ((loc[i] > 0) && !board[path[i]][loc[i]]) 
            continue;
		if (i > dep) 
            continue;
		int nloc = loc[i], npath = path[i];
		loc[i] += dice[dep];

		if (loc[i] > point[path[i]])loc[i] = point[path[i]];

		int next = board[path[i]][loc[i]];

		if (canMove(i)) {
			if (next == 10 || next == 20 ||
				(path[i] == 0 && next == 30)) 
                    path[i] = next / 10;
			
            dfs(dep + 1, score + next);
		}

		loc[i] = nloc;
        path[i] = npath;
	}
}
void solve() {
	for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }

	dfs(0, 0);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
