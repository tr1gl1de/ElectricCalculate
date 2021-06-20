//Расчет 0.1.1
// Не корректно работает функция расчет потери напряжения (inf) скорее всего переполнение
// но я не могу понять почему
//

#include <iostream>
#include <string>
#include <iomanip>					// вызов бибилиотеки для функции setprecision()
#include "calculate.h"

using namespace std;

// --------------- Переменные для расчетов--------------------------------------------------------------------
double Un = 0.4;					//напряжение в будущем возможно изменение длярасчета ВН
double cosfi = 0.96;				//по умолчанию сделаю 0,96 коэф-т мощности
double prasch = 1;					//по умолчанию 1 кВт
double L = 1;						//длина линии в м по умалочанию 1м
double poperechS = 0;				// поперечное сечение кабеля в мм^2
const double sq3 = 1.73205080757;	//ну тут константа корня из трех
// --------------- Переменные для расчетов--------------------------------------------------------------------

const string helloText = ("\n\
	Расчеты 0.1.1:\n\
\n\
1. Расчет тока 1 фаза\n\
2. Расчет трехфазного  тока \n\
3. Расчет потери напряжения\n\
4. Расчет однофазного тока кз (пока что отсутствует)\n\
5. Выполнить полный расчет всех позиций\n\
6. Выход\n\
");


//переменныt для логики
int numf = 0; // переменная для выбора функции в гл коде


int main()
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локализации
	setprecision(3);			// Задаем колличество цифо после запятой в переменных типа double

	calculate c;

	while (numf != 6)
	{
		double result;
		int typeCabel = 0;

		cout << helloText;
		cout << "Введите номер расчета: ";
		cin >> numf;
		switch (numf)
		{
		case 1:
			std::cout << "Введите расчетную мощность, напряжение и коэф-т мощности" << std::endl;
			std::cin >> prasch >> Un >> cosfi;
			result = c.current1p(prasch, Un, cosfi);
			std::cout << "Однофазный ток = "s + std::to_string(result) << std::endl;
			break;
		case 2:
			std::cout << "Введите расчетную мощность, напряжение и коэф-т мощности" << std::endl;
			std::cin >> prasch >> Un >> cosfi;
			result = c.current3p(prasch, sq3, Un, cosfi);
			std::cout << "Трехфазный ток = "s + std::to_string(result) << std::endl;
			break;
		case 3:
			std::cout << "Введите расчетную мощность, длину и поперечное сечение кабеля" << std::endl;
			std::cin >> prasch >> Un >> cosfi;
			cout << "Введите тип кабеля: 1 - Алюминий; 2 Медь" << endl;
			cin >> typeCabel;
			result = c.deltau(typeCabel, prasch, L, poperechS);
			std::cout << "Потеря напряжения в линии равна = "s + std::to_string(result) + " %"s << std::endl;
			break;
		case 4:
			//
		case 5:
			//
		case 6:
			break;
		}
	}
	return 0;
}
