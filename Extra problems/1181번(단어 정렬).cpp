#include <cstdio>
#include <algorithm>
#include <cstring>

// sort�Լ��� ������ �� �Լ�
// ���̰� ������ ���� �������� �տ� �ִ� ���� �켱�ǰ�
// ���̰� �ٸ��� �� ª���� �켱�ȴ�.
bool comp(char* a, char* b)
{
	int len_a = strlen(a), len_b = strlen(b);
	int compare = strcmp(a, b);
	if (len_a == len_b)
		return compare < 0;
	return len_a < len_b;
}

int main(void)
{
	int n; scanf("%d", &n);

	// �ܾ��� ������ŭ ���������� �迭 �����Ҵ�
	char **list = new char*[n];

	// ������ �����Ϳ� ���ڿ� �ִ����+�ι��� 51�� char �迭 �����Ҵ�
	for (int i = 0; i < n; i++) list[i] = new char[50+1];
	
	// scanf�� 50���� ���� �� �ֵ��� ����
	for (int i = 0; i < n; i++) scanf("%50s", list[i]);

	// sort�Լ��� ���� ���̰� ����������� ����
	std::sort(list, list + n, comp);

	for (int i = 0; i < n; i++){
		if (!strcmp(list[i], " ")) continue;
		for (int j = i + 1; j < n; j++){
			if (!strcmp(list[i], list[j])) strcpy(list[j], " ");
		}
	}

	

	// �� ���ڿ��� �ƴѰ�츸 ���
	for (int i = 0; i < n; i++){
		if (strcmp(list[i], " ") != 0)
			printf("%s\n", list[i]);
	}

	// �޸� ����
	for (int i = 0; i < n; i++) delete[] list[i];
	delete[] list;

	return 0;
}