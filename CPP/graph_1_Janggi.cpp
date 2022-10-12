#include <iostream>
#include <queue>
using namespace std;

int N, M;
int sx, sy, ex, ey;	// START, END or START, FINISH(fx, fy) 
int grid[110][110]; // ���� 

// ����  
int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

// Queue�� ���� ��ǥ ����ü 
struct xy {
	int x, y;	
};

// ���׸� Ŭ���� (Generic Class) queue
queue<struct xy> q; 

bool canGo(int nx, int ny);
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	q.push({sx,sy}) ;
	
	while (!q.empty()) {

		struct xy c = q.front(); // peek, c: current
		q.pop();

		if (c.x == ex && c.y == ey) { // pop�� ��尡 ������ ��ǥ�� ���
			cout << grid[c.x][c.y] ;
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			
			// queue push ���� Ȯ���ϱ� 
			if(!(1<=nx && nx<=N && 1<=ny && ny<=M)){ // out of bind 
				continue;
			}if(grid[nx][ny]!=0){ // �̹� Ž�� 
				continue;
			}
			
			// distance ��ŷ, queue�� push 
			grid[nx][ny] = grid[c.x][c.y] + 1;
			q.push({ nx, ny });
		}
	}
	
	return 0;
}

// �Լ� ����� �ð� 3ms -> 10ms�� �þ 
bool canGo(int nx, int ny){
	if(!(1<=nx && nx<=N && 1<=ny && ny<=M)){ // out of bind 
		return false;
	}if(grid[nx][ny]!=0){ // �̹� Ž�� 
		return false;
	}
	return true;
}

/*
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=386&sca=3030
9 9
3 5 2 8

2
*/
