// Лаба № 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>

int main()
{
	int i, j, ** Mas_Smaj, n, razmer = 0;
	setlocale(0, "rus");
	printf("Введите количество вершин в графе (матрица смежности): ");
	scanf("%d", &n);
	Mas_Smaj = (int**)malloc(n * sizeof(int*));
	srand(time(0));
	//Задание 1
	printf("Сгенерированный граф:\n");
	for (i = 0;i < n;i++)
	{
		Mas_Smaj[i] = (int*)malloc(n * sizeof(int));

		for (j = i;j < n;j++)
		{
			Mas_Smaj[i][j] = rand() % 2;
			if (i == j) Mas_Smaj[i][j] = 0;
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			Mas_Smaj[j][i] = Mas_Smaj[i][j];
			printf("|%4d| ", Mas_Smaj[i][j]);
		}
		printf("\n");
	}
	//Задание 2
	int count = 0;
	for (i = 0;i < n;i++)
	{
		for (j = i;j < n;j++)
		{
			if (Mas_Smaj[i][j] == 1) count += 1;
		}
		razmer += count;
		count = 0;
	}
	printf("Размер графа = %d\n", razmer);
	//Задание 3
	int count_dk = 0;
	for (i = 0;i < n;i++)
	{
		count_dk = 0;
		for (j = 0;j < n;j++)
		{
			if ((i!=j) && (Mas_Smaj[i][j] == 1)) count_dk += 1;
		}
		if (count_dk == 0) printf("Вершина №%d является изолированным\n", i + 1);
		if (count_dk == n - 1) printf("Вершина №%d является доминирующим\n", i + 1);
		if (count_dk == 1) printf("Вершина №%d является концевым\n", i + 1);
	}
	_getch();
	printf("\n");
	int** Mas_Incen = (int**)malloc(n * sizeof(int*));
	for (i = 0;i < n;i++)
	{
		Mas_Incen[i] = (int*)malloc(razmer * sizeof(int));
		for (j = 0;j < razmer;j++) Mas_Incen[i][j] = 0;
	}
	
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (Mas_Smaj[i][j])
			{
				Mas_Incen[i][k] = 1;
				Mas_Incen[j][k] = 1;
				k++;
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < razmer;j++)
		{
			printf("|%4d| ", Mas_Incen[i][j]);
		}
		printf("\n");
	}
	count = 0;
	for (i = 0;i < razmer;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (Mas_Incen[j][i] == 1)
			{
				count++;
				break;
			}
		}
	}
	printf("Размер графа = %d\n", count);
	count = 0;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < razmer;j++)
		{
			if (Mas_Incen[i][j] == 1)
			{
				count++;
			}
		}
		if (count == n - 1) printf("Вершина №%d является доминирующим\n", i+1);
		if(count == 1) printf("Вершина №%d является концевым\n", i+1);
		if(count == 0) printf("Вершина №%d является изолирующим\n", i+1);
		count = 0;
	}
}
/*int k = 0;
	int v = 0;
	for (int i = 0; i < ct; i = n - v - 1 + i)
	{
		k = i;
		int answer = 0;
		for (int j = v; j < n; j++)
		{
			if (j > v)
			{
				printf("Соединить вершины №%d и №%d?\n1 - Да, 0 - Нет\n", v + 1, j + 1);
				scanf("%d", &answer);
			}
			if (answer == 1)
			{
				Mas_Incen[j][k + j - 1] = 1;
				Mas_Incen[v][k + j - 1] = 1;
			}
		}
		v++;
	}*/