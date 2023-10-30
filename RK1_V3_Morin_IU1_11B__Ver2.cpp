#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int size;  //количество
	cout<< "Введите количество заказанных блюд: " << endl;
	cin >> size;    //Ввод кол-ва блюд
	char**names = new char*[size];  //Динамичесский масив для наименований
	int*amount = new int[size];   //Динамичесский масив для кол-ва
	double*prices = new double[size];   //Динамичесский масив для цен за единицу
	cin.ignore();   //Чистка буфера
	for (int i = 0; i<size; ++i)     //Стандартная пробежка по масиву
	{
		char bufer[100];   //Создание строки для наименования
		cout<< "Ведите наименование блюда " << i+1 << " : "<< endl;
		cin.getline(bufer,100);  //Вводим название блюда
		names[i] = new char[strlen(bufer)];    //Присвоение названий в names
		strcpy(names[i], bufer);    //Копирование значения в буфер
		cout<<"Введите количество единиц:"<< i+1 << " : " << endl;
		cin>>amount[i] ;       //Вводим количесвто единиц
		cout<<"Введите цену за единицу блюда:"<< i+1<< " : " <<endl;
		cin >> prices[i];     //Вводим цену
		cin.ignore();  //Чистка буфера
	}
	for (int i = 0; i<size-1; ++i)               //Пробежка по внешней части масива
	{
		for (int j = 0; j<size-i-1;++j)          //Пробежка по внутреней части масива
		{
			if (strcmp(names[j],names[j+1])>0)   //Проверка букв по алфавиту
			{
				swap(names[j],names[j+1]);     //Замена названий по алфавиту
				swap(amount[j],amount[j+1]);   //Замена количества единиц по названиям 
				swap(prices[j],prices[j+1]);   //Замена цен по названиям 
			}
		}
	}
	
	double sum = 0;
	double sum1;
	double sum2;
	for (int i = 0; i<size; ++i) //цикл для сумм цен и количества
	{
	    double c;
	    double b;
	    b = double(amount[i]);                        //изменение интового значения на дабл(дробное)
	    c = double(b*prices[i]);                      //вычисление общей суммы на одино блюдо
	    sum += c;                                     //добавление этой суммы в переменную      
	    sum1 += double(prices[i]);                    //сумма цен
	    sum2 += double(amount[i]);                    //сумма кол-ва
	}
	  
	cout << "Общая сумма чека: " << sum << endl;
	for (int i = 0; i<size; ++i)             //Стандартная пробежка по масиву
	{
		cout << "Блюдо " << names[i] << " : кол-во " << amount[i] << ", цена за единицу: " << prices[i] << "\n"; //Вывод блюд,их кол-во и цены за единицу в алфавитном порядке
	}
	return 0; 
	delete(names);
    delete(amount);
    delete(prices);
    

}