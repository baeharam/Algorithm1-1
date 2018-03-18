#include <iostream>
#include <algorithm>

int spiral[5001][5001];

int main(void)
{
	int r1, c1, r2, c2;
	std::cin >> r1 >> c1 >> r2 >> c2;
	
	int i, j, begin_r1, begin_c1, end_r2, end_c2;

	// r1�� c1�� ����� �����Ŀ� ���� (0,0)�� �ε����� �������� ����� �ٸ���
	// �������� ����� �� ��𼭺��� ������ ����� �������� �ٸ��� ������
	// ���⼭ �� ������ش�. i,j�� ó���� (0,0)�� �ǹ��ϴ� �ε��� ������ ��������
	// begin_r1,begin_c1�� ����� ������ ��� ���� �ε���, end_r2,end_c2�� ����� ���� ��� ���� �ε����̴�.
	if (r1 < 0) {
		i = r1 * -1;
		begin_r1 = 0;
		end_r2 = r2 - r1;
	}
	else {
		i = 0;
		begin_r1 = r1;
		r1 == 0 ? end_r2 = r2 - r1 : end_r2 = r2;
	}

	if (c1 < 0) {
		j = c1 * -1;
		begin_c1 = 0;
		end_c2 = c2 - c1;
	}
	else {
		j = 0;
		begin_c1 = c1;
		c1 == 0 ? end_c2 = c2 - c1 : end_c2 = c2;
	}

	// �ҿ뵹���� ù ������ 1
	spiral[i][j] = 1;
	
	// �ҿ뵹�̰� �������̳� ���� ������ �� 1,3,5,7...�� ����
	// �ҿ뵹�̰� �����̳� �Ʒ��� ������ �� 2,4,6,8...�� ����
	int right_up = 1;
	int left_down = 2;

	// �ҿ뵹�̸� �ݺ��ϴ� Ƚ���� r1,c1,r2,c2�� �������� ���� ū ���� ���ѵ� 1�� �����ִ� ����
	int iter = std::max(std::max(std::abs(r1), std::abs(r2)), std::max(std::abs(c1), std::abs(c2))) + 1;

	// temp�� ������ �ҿ뵹�̸� ����� �� �ε����� ������ �Ǵ� ��쿡 ���ؼ� ���� spiral �迭�� ���� �� ���� ������
	// �ӽú����μ� temp�� ���� �ҿ뵹���� �� ��ҷ� �ν��ϰ� ����ϴ� ��.
	int temp = 1;

	// ������ ����� iter��ŭ �ݺ��Ѵ�.
	while(iter--){
		// ������
		for (int k = 0; k < right_up; k++) {
			// �ϴ� �ε����� ���� ������Ʈ���Ѿ� �Ѵ�.
			j++;
			// �׸��� ����� i,j���� �ּ� (begin_r1, begin_r2)�̰� �ִ� (end_r2,end_c2)�̱� ������ ���� ������ ���� ��
			// �����ϸ� temp�� �����ְ� temp�� �������� �������ش�.
			if (i>=begin_r1 && j>=begin_c1 && i<=end_r2 && j <=end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			// �� �κ��� �ε����� ������ �ʰ��� �κ����� temp�� ���� ������Ŵ���� �ҿ뵹�̸� ��� ����� ������ �Ѵ�.
			else temp++;
		}
		// ����
		for (int k = 0; k < right_up; k++) {
			i--;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// ����
		for (int k = 0; k < left_down; k++) {
			j--;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// �Ʒ���
		for (int k = 0; k < left_down; k++) {
			i++;
			if (i >= begin_r1 && j >= begin_c1 && i <= end_r2 && j <= end_c2) {
				spiral[i][j] = temp + 1;
				temp = spiral[i][j];
			}
			else temp++;
		}
		// ������/���ʰ� ����/�Ʒ����� 2�� �����ϹǷ� 2�� �ݺ��� ������ �����ش�.
		right_up += 2;
		left_down += 2;
	}
	
	// ���� ���̰� �� ���ڸ� ����. (���� ū ���ڶ� ����)
	int Longest = 0;
	for (int i = begin_r1; i <=end_r2; i++) {
		for (int j = begin_c1; j <=end_c2; j++) {
			if (Longest < spiral[i][j]) Longest = spiral[i][j];
		}
	}

	// �� ���̰� ���̳� �Ǵ��� ���Ѵ�.
	int print_format = 1;
	while (Longest / 10) {
		Longest /= 10;
		print_format++;
	}

	// �����Ʈ
	for (int i = begin_r1; i <=end_r2; i++) {
		for (int j = begin_c1; j <=end_c2; j++) {
			// ������ ���� ���� �� ���̷� ��³ʺ� ���Ѵ�.
			std::cout.width(print_format);
			// �ʺ� �� ä���� ���ϴ� ���ڴ� �������� ä���.
			std::cout.fill(' ');
			std::cout << spiral[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}