#include <iostream>
#include <queue>
using namespace std;

// �Է� 
char list[250][250];
// �湮 ���� üũ
bool visited[250][250]; 
// �� ���� ��, �� ������ ��(���) 
int sumA = 0;
int sumB = 0;
// ������ ���� ��, ������ ������ ��
int thisA = 0;
int thisB = 0; 

struct point{
	int x;
	int y;
	char z;
};

// �� ���� �ȿ� �ִ� ���� ���� ������ �� �ľ��ϴ� �Լ� 
void bfs(int a, int b, int x, int y){
	queue<point> q;
	point p = {a,b,list[a][b]};
	visited[p.x][p.y]=true;
	q.push(p);
	while(!q.empty()){
		point ver = q.front();
		q.pop(); 
		// ver�� �̹��� �湮�� ����, (. o v) �̷��� 3���� ��� ���� 
		if(ver.z=='o'){
			thisA++;
		}
		else if(ver.z=='v'){
			thisB++;
		}
		// q�� push�� ���� ���� : �����¿쿡 #�� �ƴ�, ������ �ϳ��� �ִ�, 
                // �湮���� ���� �����̴�. 
		// ��, �����¿� ���� 0<= <x / 0<= <y
		point pp;
		//�� 
		if((ver.x+1)<x&&list[ver.x+1][ver.y]!='#'&&visited[ver.x+1][ver.y]==false){
			visited[ver.x+1][ver.y] = true;
			pp = {ver.x+1,ver.y,list[ver.x+1][ver.y]};
			q.push(pp);
		}
		//�� 
		if((ver.x-1)>=0&&list[ver.x-1][ver.y]!='#'&&visited[ver.x-1][ver.y]==false){
			visited[ver.x-1][ver.y] = true;
			pp = {ver.x-1,ver.y,list[ver.x-1][ver.y]};
			q.push(pp);
		}
		//�� 
		if((ver.y+1)<y&&list[ver.x][ver.y+1]!='#'&&visited[ver.x][ver.y+1]==false){
			visited[ver.x][ver.y+1] = true;
			pp = {ver.x,ver.y+1,list[ver.x][ver.y+1]};
			q.push(pp);
		}
		//�� 
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
	// �湮����  �ʱ�ȭ �� �Է� ���ÿ� �ޱ� 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin >> list[i][j];
			visited[i][j] = false;
		}
	} 
	// �Է� ����� �������� üũ 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(list[i][j]!='#'&&visited[i][j]==false){
				thisA=0;thisB=0;
				bfs(i,j,x,y);
				// �� ������ ����
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
