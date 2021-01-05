#include <iostream>
#include <queue>
using namespace std;

// 입력 
char list[250][250];
// 방문 여부 체크
bool visited[250][250]; 
// 총 양의 수, 총 늑대의 수(출력) 
int sumA = 0;
int sumB = 0;
// 영역의 양의 수, 영역의 늑대의 수
int thisA = 0;
int thisB = 0; 

struct point{
	int x;
	int y;
	char z;
};

// 그 영역 안에 있는 양의 수와 늑대의 수 파악하는 함수 
void bfs(int a, int b, int x, int y){
	queue<point> q;
	point p = {a,b,list[a][b]};
	visited[p.x][p.y]=true;
	q.push(p);
	while(!q.empty()){
		point ver = q.front();
		q.pop(); 
		// ver은 이번에 방문한 정점, (. o v) 이렇게 3개의 경우 가능 
		if(ver.z=='o'){
			thisA++;
		}
		else if(ver.z=='v'){
			thisB++;
		}
		// q에 push할 정점 조건 : 상하좌우에 #이 아닌, 정점이 하나라도 있는, 
                // 방문하지 않은 정점이다. 
		// 단, 상하좌우 값이 0<= <x / 0<= <y
		point pp;
		//하 
		if((ver.x+1)<x&&list[ver.x+1][ver.y]!='#'&&visited[ver.x+1][ver.y]==false){
			visited[ver.x+1][ver.y] = true;
			pp = {ver.x+1,ver.y,list[ver.x+1][ver.y]};
			q.push(pp);
		}
		//상 
		if((ver.x-1)>=0&&list[ver.x-1][ver.y]!='#'&&visited[ver.x-1][ver.y]==false){
			visited[ver.x-1][ver.y] = true;
			pp = {ver.x-1,ver.y,list[ver.x-1][ver.y]};
			q.push(pp);
		}
		//우 
		if((ver.y+1)<y&&list[ver.x][ver.y+1]!='#'&&visited[ver.x][ver.y+1]==false){
			visited[ver.x][ver.y+1] = true;
			pp = {ver.x,ver.y+1,list[ver.x][ver.y+1]};
			q.push(pp);
		}
		//좌 
		if((ver.y-1)>=0&&list[ver.x][ver.y-1]!='#'&&visited[ver.x][ver.y-1]==false){
			visited[ver.x][ver.y-1] = true;
			pp = {ver.x,ver.y-1,list[ver.x][ver.y-1]};
			q.push(pp);
		}
	}
}

int main(){
	int x,y;
	cin >> x >> y ;
	// 방문여부  초기화 및 입력 동시에 받기 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin >> list[i][j];
			visited[i][j] = false;
		}
	} 
	// 입력 제대로 끝나는지 체크 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(list[i][j]!='#'&&visited[i][j]==false){
				thisA=0;thisB=0;
				bfs(i,j,x,y);
				// 한 영역이 끝남
				if(thisA>thisB) {
					sumA += thisA;
				}
				else{
					sumB += thisB;
				}
			}
		}
	} 
	cout << sumA << " " << sumB ;
	return 0;
}
