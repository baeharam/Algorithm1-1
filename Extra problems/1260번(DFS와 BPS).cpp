#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

// ������ �ִ밳��
const int max_vertex = 1000+1;
// ���͸� �迭�� ���� �� �迭�� ���͸� ���� �ȴ�.
// �迭�� index�� �ִ��� 1000�̹Ƿ� max_vertex�� 1000+1�� �ȴ�.
std::vector<int> graph[max_vertex];

// DFS(���� �켱 Ž��)
// ������ ���� �׸��� ���۹�ȣ�� �Ѱ��ش�
void DFS(int m, int v)
{
	// �湮���θ� Ȯ���ϴ� bool�� �迭�� �����Ҵ��ϴµ�
	// �� ������ ���� index�� ���� ������ m+1�� ���־�� �Ѵ�.
	// index�� 0���� �����̹Ƿ�
	bool *visited = new bool[m + 1];
	for (int i = 1; i <= m; i++) visited[i] = false; // false�� �ʱ�ȭ

	// ������ġ, ó���� ���۹�ȣ�� �ʱ�ȭ
	int vertex = v;

	// ������ ��θ� ��� ������ �����
	std::stack<int> path;
	// ������ġ�� ���ÿ� �ִ´�.
	path.push(vertex);

	// ���� ���� �� (����� ���� �������϶� ���� ������ ã�ƾ� ��)
	int next = 0;

	// vertex���� �湮�� �� �ִ� ���� �ִ��� �˷��ִ� ����
	bool nothing = true;

	// ������ ������ ������� �� ������ �ݺ��Ѵ�.
	while (!path.empty()){

		// vertex�� ó�� ����Ǿ��ִ� ��
		// �������� ���ĵǾ������Ƿ� �� ���� �湮���� ���� ���̱⸸ �ϸ� �ȴ�.
		// �߰���� break���ش�. ���� ������ ��� �ٲ�Ƿ�
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++)
			if (visited[graph[vertex][i]] == false) {
				next = graph[vertex][i]; break;
			}
		
		// ������ ���͸��� ���� �湮���� ���� �����̱� ������
		// ���� �������� ���ؾ� �Ѵ�.
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++)
			// vertex�� ����� ���� �� �ϳ��� �湮���� ���� ���� �ִٸ� nothing�� false�� ���ְ� ���´�.
			if (visited[graph[vertex][i]] == false) { nothing = false; break; }

		// vertex�� �湮���� ���� �Ŷ�� ����� �ϰ� �� ���� �湮�ߴٰ� ǥ���Ѵ�.
		if (visited[vertex] == false){
			std::cout << vertex << " ";
			visited[vertex] = true;
		}
		// nothing�� true�̹Ƿ� ������ ���� ������ ���ÿ��� ����� ���� vertex�� ���ư���
		if (nothing){	
			vertex = path.top();
			path.pop();
		}
		// nothing�� false�̹Ƿ� ������ �ֱ� ������ ������Ʈ �ؾ��Ѵ�.
		// �׸��� vertex�� ���ÿ� �ְ� next�� ������Ʈ.
		else{
			path.push(vertex);
			vertex = next;
		}

		//nothing�� false�� �� ���� �����Ƿ� �ݵ�� �ʱ�ȭ ���־�� �Ѵ�.
		nothing = true;

	}

	delete[] visited; // �޸�����
}

// BFS(�ʺ� �켱 Ž��)
// ������ ���� �׸��� ���۹�ȣ�� �Ѱ��ش�
void BFS(int m, int v)
{
	// �湮���θ� Ȯ���ϴ� bool�� �迭�� �����Ҵ��ϴµ�
	// �� ������ ���� index�� ���� ������ m+1�� ���־�� �Ѵ�.
	// index�� 0���� �����̹Ƿ�
	bool *visited = new bool[m + 1];
	for (int i = 1; i <= m; i++) visited[i] = false; // false�� �ʱ�ȭ

	// ������ġ, ó���� ���۹�ȣ�� �ʱ�ȭ
	int vertex = v;

	// ������ ��θ� ��� ť�� �����
	std::queue<int> path;
	// ������ġ�� ť�� �ִ´�.
	path.push(vertex);
	// ������ġ�� �湮������ true�� �����.
	visited[vertex] = true;

	// ť�� ����� ������ �ݺ��Ѵ�.
	while (!path.empty()){
		// ť�� ���� ���� ���� ����ϰ� ����.
		vertex = path.front();
		std::cout << path.front() << " "; path.pop();

		// vertex�� ����ǰ� �湮���� �ʾҴ� vertex�� ť�� �ִ´�.
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++){
			if (visited[graph[vertex][i]] == false){
				path.push(graph[vertex][i]);
				visited[graph[vertex][i]] = true;
			}
		}
	}

	delete[] visited; // �޸�����
}

int main(void)
{
	// ���� m, ���� n, ���۹�ȣ v
	int m, n, v;
	std::cin >> m; std::cin >> n; std::cin >> v;

	// �Է��ϴ� 2���� ����
	int v1, v2; 

	while (n--){
		std::cin >> v1; std::cin >> v2;
		// ������ �׷����̱� ������ ���� ��������ش�.
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	// �������� ����
	for (int i = 0; i < m; i++){
		for (std::vector<int>::size_type j = 0; j < graph[i].size(); j++)
			std::sort(graph[i].begin(), graph[i].end());
	}

	DFS(m, v);
	std::cout << '\n';
	BFS(m, v);

	return 0;
}
