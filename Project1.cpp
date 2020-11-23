#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
void filling(int array[100][100], int size) {
	int k = 1; // Число, яким ми заповнюємо масив

	int S = 0; // Лічильник мінімального елемента, до якого ми заповнюємо маси
	int P = size - 1; // Лічиньник максимального елемента, до якого ми заповнюємо масив


	for (int count = 1; count <= round(size / 2) + 1; count++) { // оскільки матриця заповнюється з 2-х сторін, виконуємо таким чином, щоб заповнилась 1/2
		int i = S; // починаємо з S рядка
		for (int j = S + 1; j <= P + 1; j++) { // заповнення S рядка вперед
			array[i][j] = k;
			k++;
		}
		for (int i = S + 1; i <= P; i++) { // заповнення P + 1 стовпця вперед
			array[i][P + 1] = k;
			k++;
		}
		for (int j = P; j >= S + 1; j--) { // заповнення P рядка назад
			array[P][j] = k;
			k++;
		}
		for (int i = P - 1; i >= S + 1; i--) { // заповнення S + 1 стовпця назад
			array[i][S + 1] = k;
			k++;
		} S++; P--;
	}



}

int main()
{
	int size;; // розмір матриці
	scanf("%d", &size);
	int array[100][100] = {};
	filling(array, size);
	for (int i = 0; i <= size - 1; i++) { // вивід
		for (int j = 1; j <= size; j++) {
			if (array[i][j] > 9) // перевірка на кількість цифр для красивого виведення матриці
				printf("%d ", array[i][j]); // 1 пробіл, якщо цифра 2 значна
			else printf("%d  ", array[i][j]); // 2 пробіл, якщо цифра 1 значна
		} printf("\n"); // перехід на наступний рядок
	}
}