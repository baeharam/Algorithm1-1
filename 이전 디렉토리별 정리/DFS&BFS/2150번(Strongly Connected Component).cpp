#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[10005];
vector<int> graph[10005];
vector<int> transpose[10005];
vector<int> SCC;


struct vf {
	int d;
	int f;
	int v;
};
vf v_time[10005];
int time;

// ���� �׷����� ���� Transpose �� �׷����� ���� ������ �����ϴ� ���� �߿���.
// time ����ϴ� ���� Transpose �� �׷��� �� ���� ���Խ��Ѽ� �������!!
void DFS(int v, bool isTranspose, vector<int> g[])
{
	if (visited[v]) return;
	else {
		if (isTranspose) SCC.push_back(v);
		else {
			time++; 
			v_time[v].d = time;
			v_time[v].v = v;
		}
		visited[v] = true;
		for (int i = 0; i < g[v].size(); i++)
			DFS(g[v][i],isTranspose,g);
		if (!isTranspose) { 
			time++; 
			v_time[v].f = time; 
		}
	}
}

// �׷��� Transpose ��Ű�� (���� ������)
void Transpose(int vNum)
{
	for (int i = 1; i <= vNum; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			transpose[graph[i][j]].push_back(i);
		}
	}
}

// finish time�� �������� ������ �� ����ϴ� ���Լ�
bool cmp(const vf& v1, const vf& v2)
{
	return v1.f > v2.f;
}

// SCC�� ����ִ� ������ ���͵��� ������ �� ����ϴ� ���Լ�
bool cmp2(const vector<int>& scc1, const vector<int>& scc2)
{
	return scc1[0] < scc2[0];
}

int main(void)
{
	int v, e; cin >> v >> e;
	
	while (e--) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}

	for (int i = 1; i <= v; i++) visited[i] = false;
	for (int i = 1; i <= v; i++) DFS(i,false,graph);


	sort(v_time + 1, v_time + v + 1, cmp);
	Transpose(v);

	for (int i = 1; i <= v; i++) visited[i] = false;

	// SCC���͵��� �����ϴ� ����
	vector<vector<int>> SCCS;
	for (int i = 1; i <= v; i++) {
		DFS(v_time[i].v, true,transpose);
		if (SCC.size()) {
			sort(SCC.begin(), SCC.end());
			SCCS.push_back(SCC);
			SCC.clear();
		}
	}

	cout << SCCS.size() << '\n';
	sort(SCCS.begin(), SCCS.end(), cmp2);
	for (int i = 0; i < SCCS.size(); i++) {
		for (int j = 0; j < SCCS[i].size(); j++) cout << SCCS[i][j] << " ";
		cout << "-1\n";
	}


	
	return 0;
}