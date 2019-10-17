#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> LCS_table[1000 + 1][1000 + 1];

void LCS_topdown(std::string x, std::string y)
{
	// LCS ���̺��� �� ������ ���ϴ� �κ��� ��� �� ������ �����.
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++)
			if(i==0 || j==0)
				LCS_table[i][j].push_back("");
	}

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			// ���ڿ� x,y�� �ε����� ������ 0���� ���������� 
			// LCS ���̺��� 1,1�� �ε������� �����̱� ������ LCS_table�� ������ ���� ���� i,j�� 1�� �����־�� �Ѵ�.

			// 1. ���� ������ ���
			// ���� LCS�� ���� ���λ縦 �ٿ��ִ� ���̴�. �׷��� ������ ���� ���� �����Ƿ� ��� ����Ѵ�.
			if (x[i] == y[j]) {
				std::cout << i + 1 << "�� " << j + 1 << "���� ������ ";
				for (int k = 0; k < LCS_table[i + 1 - 1][j + 1 - 1].size(); k++) {
					std::string temp("");
					temp.append(LCS_table[i + 1 - 1][j + 1 - 1][k]);
					temp.push_back(x[i]);
					LCS_table[i + 1][j + 1].push_back(temp);
					std::cout << temp << ", ";
				}
				std::cout << "�Դϴ�.\n";
			}

			// 2. �ٸ� ������ ���
			else {
				// LCS[i-1][j]>LCS[i][j-1] �� ���
				// �� ������ ���� ������ LCS[i][j]�� �ִ´�.
				// ���̸� ���� �� ó�� ���λ��� ���̸� ���ϴµ� �̴� LCS ���̺��� �� �ε������� ���� ������ ���λ縸 �� �� �ۿ�
				// ���� �����̴�. �̰� LCS�� ���� �˰������� �翬�� ���̴�.
				if (LCS_table[i + 1 - 1][j + 1][0].size() > LCS_table[i + 1][j + 1 - 1][0].size()) {
					std::cout << i + 1 << "�� " << j + 1 << "���� ������ ";
					for (int k = 0; k < LCS_table[i + 1 - 1][j + 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1 - 1][j + 1][k]);
						std::cout << LCS_table[i + 1 - 1][j + 1][k] << ", ";
					}
					std::cout << "�Դϴ�.\n";
				}
				// LCS[i-1][j]<LCS[i][j-1] �� ���
				// �� ������ ���� ������ LCS[i][j[�� �ִ´�.
				else if (LCS_table[i + 1 - 1][j + 1][0].size() < LCS_table[i + 1][j + 1 - 1][0].size()) {
					std::cout << i + 1 << "�� " << j + 1 << "���� ������ ";
					for (int k = 0; k < LCS_table[i + 1][j + 1 - 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1][j + 1 - 1][k]);
						std::cout << LCS_table[i + 1][j + 1 - 1][k] << ", ";
					}
					std::cout << "�Դϴ�.\n";
				}
				// LCS[i-1][j]==LCS[i][j-1]�� ���
				// �� �ε����� ������ ��� �ִµ�, ���� ���Ҵ� �ߺ����� �ʰ� �ѹ��� �ִ´�.
				else {
					std::cout << i + 1 << "�� " << j + 1 << "���� ������ ";
					for (int k = 0; k < LCS_table[i + 1 - 1][j + 1].size(); k++) {
						LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1 - 1][j + 1][k]);
						std::cout << LCS_table[i+1-1][j+1][k] << ", ";
					}
					// ������ ���� ���߿� �ߺ������� ���� ���
					for (int k = 0; k < LCS_table[i + 1][j + 1 - 1].size(); k++) {
						bool find = false;
						for (int h = 0; h < LCS_table[i + 1][j + 1].size(); h++) 
							if (!LCS_table[i + 1][j + 1 - 1][k].compare(LCS_table[i + 1][j + 1][h])) {
								find = true; break;
							}
						if (!find) {
							LCS_table[i + 1][j + 1].push_back(LCS_table[i + 1][j + 1 - 1][k]);
							std::cout << LCS_table[i + 1][j + 1 - 1][k] << ", ";
						}
					}
					std::cout << "�Դϴ�.\n";
				}
			}
		}
	}
}

int main(void)
{
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;

	std::cout << "������ LCS���̺��� ������ ��Ÿ�� ���Դϴ�...\n\n";

	LCS_topdown(s1, s2);

	std::cout << "\n���� LCS(" << s1 << ", " << s2 << ")�� ";
	for (int i = 0; i < LCS_table[s1.size()][s2.size()].size(); i++) std::cout << LCS_table[s1.size()][s2.size()][i] << ' ';
	std::cout << "�Դϴ�.\n";
		

	return 0;

}