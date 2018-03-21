#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

const int min = -1000000000;
const int max = 1000000000;

// �պ����� �˰����� �̿��ؼ� ���׸�Ʈ Ʈ���� �κк��� ����
std::vector<int> Merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> temp;
	int i = 0, j = 0, a_size = a.size(), b_size = b.size();

	while (i < a_size && j < b_size) {
		if (a[i] < b[j]) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(b[j]);
			j++;
		}
	}

	if (i == a_size) {
		while (j < b_size) {
			temp.push_back(b[j]);
			j++;
		}
	}
	else if (j == b_size) {
		while (i < a_size) {
			temp.push_back(a[i]);
			i++;
		}
	}

	return temp;
}

// �־����� i,j,k(����)���� i~j�� ���� �������͵��� �����͸� �ϳ��� ���ͷ� ������.
void query(std::vector<std::vector<int>*> &total, std::vector<int> tree[], int node, int start, int end, int left, int right)
{
	// ������ ����� ���
	if (left > end || right < start) return;
	// ���� �ȿ� start~end�� ���� ���, �� ������ü�� �ּҸ� ����
	if (left <= start && right >= end) total.push_back(&tree[node]);

	// start~end �ȿ� ������ ���� ��� ����/������ �ڽ� ����� ���ȣ��
	else {
		int mid = (start + end) / 2;
		query(total, tree, node * 2, start, mid, left, right);
		query(total, tree, node * 2 + 1, mid + 1, end, left, right);
	}
}

// k��° ���ڸ� ã�� �Լ�
int kthElement(std::vector<int> tree[], int n, int left, int right, int k)
{
	// ���ĵ� �������͵��� �����͸� ������ ����, ���۷����� �����Ѵ�.
	std::vector<std::vector<int>*> total;
	// i=left, j=right�� �־��� ������ �����Լ� ȣ��
	query(total, tree, 1, 0, n - 1, left, right);

	// num�� ������ ���ں��� ���� �������͵��� ���� ����
	// l1, r1�� -10��, 10����� �����ؼ� Binary Search����
	// mid1 = Binary Search�� ���Ǹ� ������ ���ڸ� �ǹ��Ѵ�.
	int num = 0, l1 = min, r1 = max, mid1;

	// k��° ���ڸ� ã�� Binary Search
	while (l1<=r1) {
		num = 0;
		// ���������͵��� ���� ������ ũ�⸸ŭ �ݺ�
		for (int i = 0; i < total.size(); i++) {
			mid1 = (l1 + r1) / 2; 
			// l2,r2�� 0�� �����Ͱ� ����Ű�� ������ ũ��-1(�ε���)
			// mid2 = �Ϲ����� Binary Search�� �߰����� �ǹ�
			int l2 = 0, r2 = total[i]->size() - 1, mid2;
			// ������ ���� mid1���� ���� ������ ������ ã�� Binary Search
			while(l2<=r2) {
				mid2 = (l2 + r2) / 2;
				// mid1���� �۰ų� ������ ������ ������ ��� mid1���� ���� ���̹Ƿ� mid2+1���� �ٽ� ����
				if (mid1 >= total[i]->at(mid2)) l2 = mid2 + 1;
				// mid1���� ũ�� ������ ������ ��� mid1���� ū ���̹Ƿ� mid2-1���� �ٽ� ����
				else r2 = mid2 - 1;
			}
			// r2�� �ǹ��ϴ� ���� r2 ������ ������ ��� r2���� �����Ƿ� r2(�ε���)+1�� �� ����.
			num += (r2 + 1);
		}
		// ������ ���ں��� ���� ������ ������ k���� ���� ��� ������ ���ڴ� �� Ŀ���� �ϰ�
		// ũ�ų� ���� ��� ������ ���ڴ� �� �۾����� �Ѵ�.
		num < k ? l1 = mid1 + 1 : r1 = mid1 - 1;
	}
	return l1;
}

// ���׸�Ʈ Ʈ�� �ʱ�ȭ
std::vector<int> init(int arr[], std::vector<int> tree[], int node, int start, int end)
{
	// ���������� �������� �� �� ���� push_back�ϰ� ����
	if (start == end) {
		tree[node].push_back(arr[start]);
		return tree[node];
	}

	// ������尡 �ƴ� ��� ����/������ �ڽĳ���� ���͵��� �պ��ؼ� �����忡 ������Ʈ
	int mid1 = (start + end) / 2;
	return tree[node] = Merge(init(arr, tree, node * 2, start, mid1), init(arr, tree, node * 2 + 1, mid1 + 1, end));
}

int main(void)
{
	int n, m; std::cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	// ���׸�Ʈ Ʈ���� ���̿� ���׸�Ʈ Ʈ���� ���� �迭�� ũ�� ���ϱ�
	int h = static_cast<int>(std::ceil(std::log2(n)) + 1);
	int tree_size = static_cast<int>(std::pow(2.0, h) - 1);

	// ���׸�Ʈ Ʈ�� ����
	std::vector<int> *tree = new std::vector<int>[tree_size + 1];

	// �ʱ�ȭ
	init(arr, tree, 1, 0, n - 1);


	int i, j, k;
	while (m--) {
		// ���� �Է�
		scanf("%d %d %d", &i, &j, &k);
		// �־����� i,j�� index������ �ƴϹǷ� 1�� ���ش�.
		i--; j--;
		printf("%d\n", kthElement(tree, n, i, j, k));
	}

	// �޸� ����
	delete[] arr, tree;
	return 0;
}