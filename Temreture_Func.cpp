#include <iostream>
#include <Windows.h>
#include "Conversions.h"
struct Tempteture_spec
{
	int min = 0, max = 0, step = 0;
};

void print_preliminary_message()
{
	std::cout << "Формула для преобразованя Цельсия в Фаренгейты: Tf = 1.8 * Tc + 32\n";
	std::cout << "Формула для преобразованя Цельсия в Кельвины: Tk= Tc + 273.15\n";
	std::cout << "Расчёт температуры в Фаренгейтах и Кельвинах, основываясь на введённых данных:\n";
	printf("%0s%12s%10s\n", "Цельсий", "Фаренгейт", "Кельвин");
}

Tempteture_spec input_table_specifications()
{
	int temp_min = 0, temp_max = 0, temp_step = 0;
	std::cout << "Введите минимальную температуру\n";
	std::cin >> temp_min;

	std::cout << "Введите максимальную температуру\n";
	std::cin >> temp_max;

	if (temp_max <= temp_min)
	{
		std::cout << "Минимальная температура должна быть больше максимальной\n";
		return {0,0,0};
	}

	std::cout << "Введите шаг для расчёта\n";
	std::cin >> temp_step;
	return { temp_min , temp_max , temp_step };
}

void print_message_echoing_input(int temp_min, int temp_max, int temp_step)
{
	std::cout << "Минимальная температура в Цельсиях: " << temp_min << "\n";
	std::cout << "Максимальная температура в Цельсиях: " << temp_max << "\n";
	std::cout << "Шаг для расчёта температуры: " << temp_step << "\n\n";
}

void print_table(int temp_C, float temp_Far, float temp_Kel)
{
	printf(" % 6d % 11.2lf % 9.2lf\n", temp_C, temp_Far, temp_Kel);
}

int main()
{
	int temp_Cel = 0; 
	float temp_F = 0.0, temp_K = 0.0;
	Tempteture_spec countspec;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Ввод данных и их проверка
	countspec = input_table_specifications();
	if (countspec.step<=0)
	return 0;

	//Пояснение к программе и вывод введённых данных
	print_preliminary_message();
	print_message_echoing_input(countspec.min, countspec.max, countspec.step);

	//Расчёт и вывод температуры
	temp_Cel = countspec.min;
	for (temp_Cel = countspec.min; temp_Cel <= countspec.max; temp_Cel += countspec.step)
	{
		temp_F = fahrenheit_of(temp_Cel);
		temp_K = absolute_value_of(temp_Cel);
		print_table(temp_Cel,temp_F,temp_K);
	}
	return 0;
}