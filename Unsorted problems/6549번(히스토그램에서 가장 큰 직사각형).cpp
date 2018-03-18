#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

// ���׸�Ʈ Ʈ�� �ʱ�ȭ
void init(std::vector<int> &height, std::vector<int> &tree, int node, int start, int end)
{
	if (start == end) tree[node] = start;
	else {
		int mid = (start + end) / 2;
		init(height, tree, node * 2, start, mid);
		init(height, tree, node * 2 + 1, mid + 1, end);
		if (height[tree[node * 2]] < height[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}

// ���׸�Ʈ Ʈ������ �־��� ������ �ּڰ��� �䱸�ϴ� ����
int query(std::vector<int> &height, std::vector<int> &tree, int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return -1;
	else if (l <= start && r >= end) return tree[node];
	else {
		int mid = (start + end) / 2;
		int q1 = query(height, tree, node * 2, start, mid, l, r);
		int q2 = query(height, tree, node * 2 + 1, mid + 1, end, l, r);

		if (q1 == -1) return q2;
		else if (q2 == -1) return q1;
		else {
			if (height[q1] <= height[q2]) return q1;
			else return q2;
		}
	}
}

// ���������� ���� ���簢���� �ִ� ���ϱ�
long long largest(std::vector<int> &height, std::vector<int> &tree, int start, int end)
{
	int n = height.size();
	int min = query(height, tree, 1, 0, n - 1, start, end); // �־��� ������ �ּڰ� �ε���
	
	// ���� �������� �ּҳ��̷� ���� ����.
	long long area = static_cast<long long>(end - start + 1)*static_cast<long long>(height[min]);

	// ������ ������ �ּҳ����� �ε������� ������, �ּҳ��� �ε��� �������� �������� ���� �ִ��� ���Ѵ�.
	// �׸��� ���� ������ ���̿� ���ؼ� ������Ʈ �Ѵ�.
	if (start <= min - 1) {
		long long temp = largest(height, tree, start, min - 1);
		if (temp > area) area = temp;
	}
	// ������ ���� �ּҳ����� �ε������� ũ��, �ּҳ��� �ε��� ���ĺ����� �������� ���� �ִ��� ���Ѵ�.
	// �׸��� ���� ������ ���̿� ���ؼ� ������Ʈ �Ѵ�.
	if (end >= min + 1) {
		long long temp = largest(height, tree, min + 1, end);
		if (temp > area) area = temp;
	}
	return area;
}

int main(void)
{
	int n, h; scanf("%d", &n);
	while (n) {
		int tree_h = static_cast<int>(std::ceil(log2(n))) + 1;
		int tree_size = static_cast<int>(std::pow(2.0, tree_h));

		std::vector<int> height;
		std::vector<int> tree(tree_size);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &h);
			height.push_back(h);
		}

		init(height, tree, 1, 0, n - 1);
		printf("%lld\n", largest(height, tree, 0, n - 1));
		scanf("%d", &n);
	}

	return 0;
}