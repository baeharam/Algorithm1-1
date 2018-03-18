#include <iostream>

// ���� ĥ�ϴ� ���� ������ �迭
// ���� �ִ� 1000��, ���� �׻� 3��
int cost[1000 + 1][3]; // n<=1000

// �ּڰ��� ���ϴ� ����
int min = 214546464;

// ����ڰ� �Է��� n�� �����ϴ� ����
int num;

// �������� ���� enum���� �ʱ�ȭ 0,1,2
enum {R,G,B};

// ��ĥ�ϴ� �ּڰ��� ���ϴ� �Լ�
// ĥ�Ϸ��� ����, ���° ������, �� ���� ����� ���� �������� ���ڷ� �޴´�.
void RGB_min(int rgb, int nth, int sum)
{
	// ��� ���� ĥ�ߴٸ� �ּڰ��� ���� ���ؼ� �����ϰ� �Լ���ȯ
	if (nth>num){
		if (min > sum) min = sum;
		return;
	}

	// ���� ������ ���� ĥ�� �� �ִ� ������ �޶�����.
	switch (rgb){
		// ���� sum�� ������Ʈ��Ű��
		// R�̸� G,B�� G�� R,B�� B�̸� R,G�� �̵���Ų��.
	case R:
		sum += cost[nth][R];
		RGB_min(G,nth+1,sum); RGB_min(B,nth+1,sum);
		break;
	case G:
		sum += cost[nth][G];
		RGB_min(R, nth + 1, sum); RGB_min(B, nth + 1, sum);
		break;
	case B:
		sum += cost[nth][B];
		RGB_min(R, nth + 1, sum); RGB_min(G, nth + 1, sum);
		break;
	}
	
}


int main(void)
{
	int n; std::cin >> n; num = n;

	for (int i = 1; i <= n; i++)
		std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	RGB_min(R, 1, 0); RGB_min(G, 1, 0); RGB_min(B, 1, 0);

	std::cout << min;

	return 0;
}