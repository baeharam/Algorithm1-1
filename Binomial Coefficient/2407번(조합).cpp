#include <iostream>
#include <string>
#include <cstring>


std::string combination[100 + 1][100 + 1];
const int long_len = 30;
char result[long_len+1]; // �ִ��� 30�ڸ��̹Ƿ� 31�ڸ��� ����.

// string�� ���ϴ� �Լ�
std::string addBig(std::string s1, std::string s2)
{
	int temp = 0, n, m;

	// s1�� �� ũ�� true s2�� �� ũ�� false
	bool whoisbig = s1.size() > s2.size() ? true : false;
	// s1�� s2�� ũ�Ⱑ �ٸ��� true
	bool isdiff = s1.size() != s2.size() ? true : false;

	// ���̰� �� ū ���� �������� ����ؾ� �ϱ� ������ (ū�� ����)
	int lenBig = whoisbig ? s1.size() : s2.size();
	int lenSmall = whoisbig ? s2.size() : s1.size();

	int len = long_len-1; // ��� �迭�� ����ֱ� ���� ������� ����

	// ���� �ڿ������� �����ؼ� ū ���̰� ����� ������ ����� ����Ѵ�.
	for (int i = lenBig - 1, j = lenSmall - 1; j >= 0; i--, j--){
		if (whoisbig){
			n = s1[i] - '0'; // ���ڸ� ���ڷ� ��ȯ
			m = s2[j] - '0';
		}
		else{
			n = s1[j] - '0'; // ���ڸ� ���ڷ� ��ȯ
			m = s2[i] - '0';
		}
		
		temp = n + m + temp; // ���ڷ� ��ȯ�� ���� ����, �� �� temp�� 1�������� �����Ƿ� ���� �����ش�.
		// ������ �� ���ڸ��� �Ǹ� ���� �ڸ��� ��� �迭�� �ִ´�.
		if (temp / 10 != 0) {
			result[len--] = (temp % 10) + '0';
			temp = 1; // �����ڸ��� �׻� 1�̹Ƿ� 1����
		}
		else{
			result[len--] = temp + '0';
			temp = 0; // �ʱ�ȭ
		}
	}

	// �� ������ 10�� �ڸ��� ���� ��� ä����� �Ѵ�.
	// ��, ũ�Ⱑ �ٸ��� �ȵȴ�.
	if (temp && !isdiff) result[len] = '1';

	// 1) ũ�Ⱑ �ٸ��鼭 ���� ���� 10�̻��� ��� : ���ڸ�+temp�� ������� ��
	// 2) ũ�Ⱑ �ٸ��鼭 ���� ���� 10�̸��� ��� : ���ڸ��� �����ָ� ��
	else if (isdiff){
		if (whoisbig){
			// temp�� ���� ���� 10�̻��� �� �����Ƿ� �� ���鿡 ����
			// ó���� ���־�� ��
			for (int i = s1.size() - s2.size()-1; i>=0; i--){
				int toResult = (s1[i] - '0') + temp;
				if (toResult / 10 != 0){
					result[len--] = (toResult % 10) + '0';
					temp = 1;
				}
				else{
					result[len--] = toResult + '0';
					temp = 0;
				}
			}	
		}  
		else{
			for (int i = s2.size() - s1.size() - 1; i >= 0; i--){
				int toResult = (s2[i] - '0') + temp;
				if (toResult / 10 != 0){
					result[len--] = (toResult % 10) + '0';
					temp = 1;
				}
				else{
					result[len--] = toResult + '0';
					temp = 0;
				}
			}
		}

		// temp�� 0�� �ƴ϶� �Ҹ��� ���ؼ� 10�� �Ѿ��µ� �ڸ����� ���� ����̹Ƿ�
		// ó�����ش�.
		if (temp) result[len] = temp+'0';
	}

	

	std::string toReturn;


	// result �迭�� 0�� �ƴѰ��� �ٽ� real_result�� �ִ´�.
	for (int i = 0; i < long_len; i++){
		if (result[i] != '\0')
			toReturn.append(std::to_string(result[i]-'0'));
	}

	for (int i = 0; i <= long_len; i++) result[i] = '\0'; // result�迭 �ʱ�ȭ

	return toReturn;
}

int main(void)
{


	int n, m; std::cin >> n >> m;

	// 1C0=1C1=1�� ����
	combination[1][0] = combination[1][1] = "1";

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || i == j) combination[i][j] = "1";
			else if (j == 1) combination[i][j] = std::to_string(i);
			else combination[i][j] = addBig(combination[i - 1][j - 1], combination[i - 1][j]);
		}
	}

	std::cout << combination[n][m];

	

	
	return 0;
}