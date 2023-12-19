// AISD Lab3.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include "AISD Lab3.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Сортировка СТРИНГОВЫХ векторов" << endl << endl;

	vector<int> intvector1 = { 7,6,9,4,1,2,8,0,3 };
	cout << "Вектор до сортировки: " << endl;
	Print(intvector1);
	Stats statisticsint = ShakerSort(intvector1);
	cout << "Вектор после <<<шейкерной>>> сортировки " << endl;
	Print(intvector1);




	vector<string> stringvector1 = { "a", "f", "c" , "f", "a", "r" , "i", "e" };
	vector<string> stringvector2 = { "i", "y", "t" , "x", "z", "r" , "q", "l", "s", "k" };
	vector<string> stringvector3 = { "w", "t", "h" , "j", "a", "b" , "s", "e", "d", "m", "k", "a", "x", "q", "z" , "x", "b", "l" };

	cout << "Вектор до сортировки:" << endl;
	Print(stringvector1);
	Stats statistics1 = InsertSort(stringvector1);
	cout << "Вектор после сортировка <<<вставками>>> сортировки " << endl;
	Print(stringvector1);
	cout << "Кол-во сравнений: " << statistics1.comparison_count << endl;
	cout << "Кол-во копий: " << statistics1.copy_count << endl << endl;

	cout << "Вектор до сортировки: " << endl;
	Print(stringvector2);
	Stats statistics2 = ShakerSort(stringvector2);
	cout << "Вектор после <<<шейкерной>>> сортировки " << endl;
	Print(stringvector2);
	cout << "Кол-во сравнений:  " << statistics2.comparison_count << endl;
	cout << "Кол-во копий: " << statistics2.copy_count << endl << endl;

	cout << "Вектор до сортировки: " << endl;
	Print(stringvector3);
	Stats statistics3 = HeapSort(stringvector3);
	cout << "Вектор после <<<пирамидальной>>> сортировки" << endl;
	Print(stringvector3);
	cout << "Кол-во сравнений: " << statistics3.comparison_count << endl;
	cout << "Кол-во копий: " << statistics3.copy_count << endl << endl;

	cout << "Сортировка векторов СОБСТВЕННОГО КЛАССА" << endl << endl;

	vector<ComparisonClass> v1;
	vector<ComparisonClass> v2;
	vector<ComparisonClass> v3;

	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 15; ++i) {
		v1.push_back(rand() % 100);
	}

	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 15; ++i) {
		v2.push_back(rand() % 100);
	}

	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 15; ++i) {
		v3.push_back(rand() % 100);
	}

	cout << "Сортировка <<<вставками>>>" << endl << endl;

	cout << "Вектор ДО сортировки: " << endl << endl;
	for (const auto& obj : v1) {
		cout << obj.get_value() << " ";
	}
	Stats statistics4 = InsertSort(v1);
	cout << endl;
	cout << "Вектор ПОСЛЕ сортировки: " << endl << endl;
	for (const auto& obj : v1) {
		cout << obj.get_value() << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Сортировка <<<шейкерная>>>" << endl << endl;

	cout << "Вектор ДО сортировки: " << endl << endl;
	for (const auto& obj : v2) {
		cout << obj.get_value() << " ";
	}
	Stats statistics5 = ShakerSort(v2);
	cout << endl;
	cout << "Вектор ПОСЛЕ сортировки: " << endl << endl;
	for (const auto& obj : v2) {
		cout << obj.get_value() << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Сортировка <<<пирамидальная>>>" << endl << endl;

	cout << "Вектор ДО сортировки: " << endl << endl;
	for (const auto& obj : v3) {
		cout << obj.get_value() << " ";
	}
	Stats statistics6 = HeapSort(v3);
	cout << endl;
	cout << "Вектор ПОСЛЕ сортировки: " << endl << endl;
	for (const auto& obj : v3) {
		cout << obj.get_value() << " ";
	}
	cout << endl;

	const int num_vectors = 100;
	const vector<size_t> vector_lengths = { 1000, 2000, 3000 , 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000 };

	// создаём файл для дальнейшей записи туда данных
	std::ofstream outputFile("example.txt");
	if (outputFile.is_open()) {
		outputFile.close();
	}


	for (size_t length : vector_lengths) {
		Stats InsertSort_random{ 0, 0 };
		Stats InsertSort_sorted{ 0, 0 };
		Stats InsertSort_reverse{ 0, 0 };

		Stats shaker_random{ 0, 0 };
		Stats shaker_sorted{ 0, 0 };
		Stats shaker_reverse{ 0, 0 };

		Stats HeapSort_random{ 0, 0 };
		Stats HeapSort_sorted{ 0, 0 };
		Stats HeapSort_reverse{ 0, 0 };

		for (int i = 0; i < num_vectors; ++i) {
			vector<int> random_vector = RandomVec<int>(length);

			vector<int> InsertSort_random_vector = random_vector;
			Stats InsertSort_random_stats = InsertSort(InsertSort_random_vector);
			InsertSort_random.comparison_count += InsertSort_random_stats.comparison_count;
			InsertSort_random.copy_count += InsertSort_random_stats.copy_count;

			vector<int> shaker_random_vector = random_vector;
			Stats shaker_random_stats = ShakerSort(shaker_random_vector);
			shaker_random.comparison_count += shaker_random_stats.comparison_count;
			shaker_random.copy_count += shaker_random_stats.copy_count;

			vector<int> HeapSort_random_vector = random_vector;
			Stats HeapSort_random_stats = HeapSort(HeapSort_random_vector);
			HeapSort_random.comparison_count += HeapSort_random_stats.comparison_count;
			HeapSort_random.copy_count += HeapSort_random_stats.copy_count;
		}

		vector<int> sorted_vector = SortedVec<int>(length);

		vector<int> InsertSort_sorted_vector = sorted_vector;
		Stats InsertSort_sorted_stats = InsertSort(InsertSort_sorted_vector);
		InsertSort_sorted.comparison_count += InsertSort_sorted_stats.comparison_count;
		InsertSort_sorted.copy_count += InsertSort_sorted_stats.copy_count;;

		vector<int> shaker_sorted_vector = sorted_vector;
		Stats shaker_sorted_stats = ShakerSort(shaker_sorted_vector);
		shaker_sorted.comparison_count += shaker_sorted_stats.comparison_count;
		shaker_sorted.copy_count += shaker_sorted_stats.copy_count;

		vector<int> HeapSort_sorted_vector = sorted_vector;
		Stats HeapSort_sorted_stats = HeapSort(HeapSort_sorted_vector);
		HeapSort_sorted.comparison_count += HeapSort_sorted_stats.comparison_count;
		HeapSort_sorted.copy_count += HeapSort_sorted_stats.copy_count;

		vector<int> reverse_sorted_vector = ReverseSortedVec<int>(length);

		vector<int> InsertSort_reverse_sorted_vector = reverse_sorted_vector;
		Stats InsertSort_reverse_sorted_stats = InsertSort(InsertSort_reverse_sorted_vector);
		InsertSort_reverse.comparison_count += InsertSort_reverse_sorted_stats.comparison_count;
		InsertSort_reverse.copy_count += InsertSort_reverse_sorted_stats.copy_count;

		vector<int> shaker_reverse_sorted_vector = reverse_sorted_vector;
		Stats shaker_reverse_sorted_stats = ShakerSort(shaker_reverse_sorted_vector);
		shaker_reverse.comparison_count += shaker_reverse_sorted_stats.comparison_count;
		shaker_reverse.copy_count += shaker_reverse_sorted_stats.copy_count;

		vector<int> HeapSort_reverse_sorted_vector = reverse_sorted_vector;
		Stats HeapSort_reverse_sorted_stats = HeapSort(HeapSort_reverse_sorted_vector);
		HeapSort_reverse.comparison_count += HeapSort_reverse_sorted_stats.comparison_count;
		HeapSort_reverse.copy_count += HeapSort_reverse_sorted_stats.copy_count;

		Stats InsertSort_random_average_stats{
			InsertSort_random.comparison_count / num_vectors,
			InsertSort_random.copy_count / num_vectors
		};

		Stats shaker_random_average_stats{
			shaker_random.copy_count / num_vectors,
			shaker_random.comparison_count / num_vectors
		};

		Stats HeapSort_random_average_stats{
			HeapSort_random.comparison_count / num_vectors,
			HeapSort_random.copy_count / num_vectors
		};

		

		cout << endl << endl << "___________________________________________________" << endl << endl;

		cout << "Текущая длина вектора: " << length << endl << endl;

		std::ofstream outputFile("example.txt", std::ios::app);
		// Проверяем, успешно ли открыт файл
		if (outputFile.is_open()) {
			// Добавляем данные в конец файла
			outputFile << endl << endl << "___________________________________________________" << endl << endl;

			outputFile << "Текущая длина вектора: " << length << endl << endl;

			outputFile << "---сортировка вставками---:" << endl << endl;

			outputFile << "Статистика для РАНДОМНОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << InsertSort_random_average_stats.comparison_count << endl;
			outputFile << "   Кол-во копий: " << InsertSort_random_average_stats.copy_count << endl << endl;

			outputFile << "Статистика для ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Количество сравнений: " << InsertSort_sorted.comparison_count << endl;
			outputFile << "   Кол-вл копий: " << InsertSort_sorted.copy_count << endl << endl;

			outputFile << "Статистика для ОБРАТНОГО ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << InsertSort_reverse.comparison_count << endl;
			outputFile << "   Кол-во копий: " << InsertSort_reverse.copy_count << endl << endl;

			outputFile << "---шейкерная сортировка---:" << endl << endl;

			outputFile << "Статистика для РАНДОМНОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << shaker_random_average_stats.comparison_count << endl;
			outputFile << "   Кол-во копий: " << shaker_random_average_stats.copy_count << endl << endl;

			outputFile << "Статистика для ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << shaker_sorted.comparison_count << endl;
			outputFile << "   Кол-во копий: " << shaker_sorted.copy_count << endl << endl;

			outputFile << "Статистика для ОБРАТНОГО ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << shaker_reverse.comparison_count << endl;
			outputFile << "   Кол-во копий: " << shaker_reverse.copy_count << endl << endl;

			outputFile << "---пирамидальная сортировка---:" << endl << endl;

			outputFile << "Статистика для РАНДОМНОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << HeapSort_random_average_stats.comparison_count << endl;
			outputFile << "   Кол-во копий: " << HeapSort_random_average_stats.copy_count << endl << endl;

			outputFile << "Статистика для ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << HeapSort_sorted.comparison_count << endl;
			outputFile << "   Кол-во копий: " << HeapSort_sorted.copy_count << endl << endl;

			outputFile << "Статистика для ОБРАТНОГО ОТСОРТИРОВАННОГО ВЕКТОРА:" << endl;
			outputFile << "   Кол-во сравнений: " << HeapSort_reverse.comparison_count << endl;
			outputFile << "   Кол-во копий: " << HeapSort_reverse.copy_count << endl << endl;

			// Закрываем файл после записи
			outputFile.close();
			cout << endl << endl << "Статистика добавлена в конец файла" << endl << endl;
		}
		else {
			std::cerr << "Не удалось открыть файл для добавления данных." << std::endl;
		}


		
	}
	return 0;
}
