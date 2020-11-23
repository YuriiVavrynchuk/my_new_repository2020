#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void filling(int array[100][100], int size) {
	int k = 1; // �����, ���� �� ���������� �����

	int S = 0; // ˳������� ���������� ��������, �� ����� �� ���������� ����
	int P = size - 1; // ˳������� ������������� ��������, �� ����� �� ���������� �����


	for (int count = 1; count <= round(size / 2) + 1; count++) { // ������� ������� ������������ � 2-� �����, �������� ����� �����, ��� ����������� 1/2
		int i = S; // �������� � S �����
		for (int j = S + 1; j <= P + 1; j++) { // ���������� S ����� ������
			array[i][j] = k;
			k++;
		}
		for (int i = S + 1; i <= P; i++) { // ���������� P + 1 ������� ������
			array[i][P + 1] = k;
			k++;
		}
		for (int j = P; j >= S + 1; j--) { // ���������� P ����� �����
			array[P][j] = k;
			k++;
		}
		for (int i = P - 1; i >= S + 1; i--) { // ���������� S + 1 ������� �����
			array[i][S + 1] = k;
			k++;
		} S++; P--;
	}



}

int main()
{
	int size;; // ����� �������
	scanf("%d", &size);
	int array[100][100] = {};
	filling(array, size);
	for (int i = 0; i <= size - 1; i++) { // ����
		for (int j = 1; j <= size; j++) {
			if (array[i][j] > 9) // �������� �� ������� ���� ��� ��������� ��������� �������
				printf("%d ", array[i][j]); // 1 �����, ���� ����� 2 ������
			else printf("%d  ", array[i][j]); // 2 �����, ���� ����� 1 ������
		} printf("\n"); // ������� �� ��������� �����
	}
}