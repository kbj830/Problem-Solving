#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct FISH {
	int x;
	int y;
	int dir;
	bool life;
};

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int ans;
int map[4][4];
FISH fish[17];

void swapF(int a, int b) {
	FISH tmp = fish[a];
	fish[a].x = fish[b].x;
	fish[a].y = fish[b].y;
	fish[b].x = tmp.x;
	fish[b].y = tmp.y;
}

void copy(int narr[][4], int arr[][4], FISH nf[], FISH f[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			narr[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= 16; i++)
		nf[i] = f[i];
}

void move() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].life == false)
			continue;
		
		int x = fish[i].x,
			y = fish[i].y,
			dir = fish[i].dir;
		
		int nx = x + dx[dir],
			ny = y + dy[dir];
		
		bool flag = false;
		
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (map[nx][ny] == 0) {
				flag = true;
				fish[i].x = nx;
				fish[i].y = ny;
				map[nx][ny] = i;
				map[x][y] = 0;
			}
			else if (map[nx][ny] != -1) {
				flag = true;
				swapF(i, map[nx][ny]);
				swap(map[x][y], map[nx][ny]);
			}
		}
		
		// 방향 전환
		if (flag == false) {
			int ndir = dir + 1;
			if (ndir == 9) ndir = 1;
			
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			while (ndir != dir) {
				if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
					if (map[nx][ny] == 0) {
						fish[i].x = nx;
						fish[i].y = ny;
						map[nx][ny] = i;
						map[x][y] = 0;
						fish[i].dir = ndir;
						break;
					}
					else if (map[nx][ny] != -1)
					{
						swapF(i, map[nx][ny]);
						swap(map[x][y], map[nx][ny]);
						fish[i].dir = ndir;
						break;
					}
				}
				ndir++;
				
				if (ndir == 9) ndir = 1;
				nx = x + dx[ndir];
				ny = y + dy[ndir];
			}
		}
	}
}

void change(int x, int y, int nx, int ny, int num, bool flag) {
	if (flag) {
		map[x][y] = 0;
		map[nx][ny] = -1;
		fish[num].life = false;
	}
	else {
		map[x][y] = -1;
		map[nx][ny] = num;
		fish[num].life = true;
	}
}

void dfs(int x, int y, int dir, int Sum){
	ans = max(ans, Sum);
	int cmap[4][4];
	FISH cfish[20];
	copy(cmap, map, cfish, fish);
	move();
	for (int i = 1; i < 4; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (map[nx][ny] == 0)
				continue;
			
			int fish_Num = map[nx][ny];
			int ndir = fish[fish_Num].dir;
			
			change(x, y, nx, ny, fish_Num, true);
			dfs(nx, ny, ndir, Sum + fish_Num);
			change(x, y, nx, ny, fish_Num, false);
		}
		else break;
	}
	copy(map, cmap, fish, cfish);
}

void solve() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			
			map[i][j] = a;
			fish[a] = {i, j, b, true};
		}
	}
	
	int num = map[0][0];
	int dir = fish[num].dir;
	fish[num].life = false;
	map[0][0] = -1;
	
	dfs(0, 0, dir, num);
	
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
