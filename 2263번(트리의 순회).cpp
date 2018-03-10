#include <iostream>

int inorder[100001];
int postorder[100001];

void PreOrder(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe) return;

	int root = postorder[pe]; // postorder�� ������ ���� root
	std::cout << root << ' '; // root ���
	int k = 0; // root�� index

	// inorder���� root���� index�� ã�� ����
	for (int i = is; i <= ie; i++) {
		if (inorder[i] == root) {
			k = i;
			break;
		}
	}

	/* ��� �����ϴ��� ������ �ϴ� �������
	std::cout << "inorder : " << is << "���� " << ie << "����\n";
	std::cout << "postorder : " << ps << "���� " << pe << "����\n";
	std::cout << "k : " << k << '\n';*/

	// inorder�� ���۰� ���� ������ ���� k�������� ���ʰ� ���������θ� �����ָ� ��
	// ������ postorder�� ���۰� ���� ��� �������ִ����� ����!!
	// ������ ��������� �ذ��ϱ� ������ ������ ���҉������� ������ �������� ���ƾ� ��. �� �κ��� ��� �����ؼ� �ᱹ ��Ǯ����
	// root�� ���ϴ� ������ �׻� postorder�� ������ ���� postorder[pe]�� ���� ����ؾ� �Ѵ�.

	// postorder�� ������ ���۰� ���� �ְ� ���ʰ� �������� ����
	// ������ ���� : �׻� ps�� ���� �ڸ�
	// ������ �� : ���� k-1�� �ܼ��� �����ߴµ� ps,is�� ������� ������ ���� ���� �� ���� �ȵ�. ps+k-(is+1)
	// �������� ���� : ������ �� �����̹Ƿ� �翬�� ps+k-is
	// �������� �� : postorder[pe]���� ����ϱ� ������ index�� �ϳ��� �پ���. ���� pe-1

	// �ٽ��� ps+k-(is+1)�� �ľ��ؾ� �ϴ� ����. ������ �̷� ����� �˾Ƴ��Ⱑ ��ô �����.
	// �� �������� ������ �� ���� �ϳ��� ��󿡼��� �������� ���� �ٸ� ��� ����ؾ� �Ѵٴ� ��. ���� index�� ���踦 ����� �ľ��ϰ�
	// �ؾ��Ѵٴ� ���̴�. �����ϸ� ���� �� Ǭ��... ���� �� ����� ����.
	PreOrder(is, k - 1, ps, ps + k - (is + 1));
	PreOrder(k + 1, ie, ps + k - is, pe - 1);
}

int main(void)
{
	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> inorder[i];
	for (int i = 1; i <= n; i++) std::cin >> postorder[i];

	PreOrder(1, n, 1, n);
	return 0;
}