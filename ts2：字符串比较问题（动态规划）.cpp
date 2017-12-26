#include "iostream"
#include "string"
using namespace std;

#define MAXNUM 65535

int val[100][100];	//�����Сֵ
int k;				//�ո��������ַ��ľ���ֵ

string str1, str2;

//���������ַ�֮���ASCII����
int dist(char a, char b) {
	return abs(a - b);
}

//����С����
int mindist() {
	int len1 = str1.length();
	int len2 = str2.length();
	int temp;
	val[0][0] = 0;	//��ʾ�ո�
	for (int i = 0; i < len1; i++) {	//�±��1��ʼ���������ϴν�����в���
		for (int j = 0; j < len2; j++) {
			if (i + j > 0) {	//������һ�����ǿո�,Ӧ�ÿո��໥�Ƚ϶��ڽ��û�б任�������Ƕ����
				val[i][j] = MAXNUM;
				//���1
				if (i > 0) {
					temp = val[i - 1][j] + k;
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
				//���2
				if (j > 0) {
					temp = val[i][j - 1] + k;
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
				//���3
				if (i * j > 0) {
					temp = val[i - 1][j - 1] + dist(str1[i], str2[j]);
					if (temp < val[i][j]) {
						val[i][j] = temp;
					}
				}
			}			
		}
	}
	return val[len1-1][len2-1];
}

int main() {
	cin >> str1 >> str2;
	cin >> k;
	str1 = " " + str1;	//���ַ��ıȽ��м�����ո�ıȽ�
	str2 = " " + str2;
	cout << mindist() << endl;
	return 0;
}