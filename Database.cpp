
/**************************************************************************************
*Project Name  : Database														      *
*File Name	   : Database.cpp													      *
*Language	   : CPP, MSVS ver 2015 and above										  *
*Programmers   : Ратников Роман Олегович, группа : М3О - 210Б - 20					  *
*Modified By   :																	  *
*Created	   : 23.11.2021														      *
*Last Revision : 07.12.2021														      *							
*Comment       : База данных										    			  *
***************************************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


// Функция создания списка
void Create_List(const char* Fname);

// Функция печати списка
void Print_List();

// Функция удаления списка
void Delete_List();

// Функция добавления элемента
void Insert_Data(const string& name,				// Название
				 const string& address,				// Адрес
				 const string& number,				// Номер телефона
				 const int& halls,					// Количество залов
				 const int& capacity,				// Вместимость
				 const int& price,					// Средняя цена
				 const int& location);				// Расположение

// Функция удаления хвоста
void Delete_Tail();

// Функция сортировки по строке 
void Sort_Data(const int& x, const string& value);

// Функция сортировки по числам
// Перегрузка
void Sort_Data(const int& x,const int& value);

// Удаление заданной строки
void Delete_Data(const int&location);


// Функция выборки по строкам
void Selection(const int& x, const string& request);

// Функция выборки по числам
// Перегрузка
void Selection(const int& x, const int& request2);

// Функция максимальной вместимости
void Max_Capacity();

// Функция удаления элемента в файле
void Delete_Data_File(const int& x);		// Расположение

// Функция добавления элемента в файл
void Insert_Data_File(const string& name, const string& address, const string& phone,
	const int& halls, const int& capacity, const int& price, const int& location);

// Элемент списка
struct list
{
    string name;      // Название
	string address;   // Адрес
	string number;    // Номер телефона
	int halls;     // Количество залов
	int capacity;  // Вместимость
	int price;     // Средняя цена

	

	list* next;       // Указатель на следующий элемент
	list* prev;       // Указатель на предыдущий элемент
};



list* head = NULL;    // Указатель на начало списка
list* tail = NULL;    // Указатель на конец списка

int Count=0;        // Количество элементов в списке
const char* Fname = "Data.txt";		// Файл


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Create_List(Fname);

	int location;
	int value;
	// Запросы
	string request;
	int request2;
	// Данные
	string name;
	string address;
	string phone;
	int halls;
	int capacity;
	int price;
	

	int number = 1;   //Для первого вывода
	while (number)
	{

		cout << "\t\tМеню: " << 
			 "\n 0) Выйти из программы" << 
			 "\n 1) Создать список" << 
			 "\n 2) Вывести список" << 
			 "\n 3) Удалить список" << 
			 "\n 4) Добавить элемент" << 
			 "\n 5) Удалить посл. элемент" << 
			 "\n 6) Удалить заданный элемент" << 
			 "\n 7) Сортировать список" <<
			 "\n 8) Выбрать по значению" <<
			 "\n 9) Максимальная вместимость" <<
			 "\n\n\n Введите номер команды :";
		cin >> number;

		switch (number)
		{
		case 0:
		{
			cout << "\n Завершение программы " << endl;
			Delete_List(); //Удаление списка
			return 0;
		}
		case 1:
		{
			Create_List(Fname);
			break;
		}
		case 2:
		{
			Print_List();
			break;
		}
		case 3:
		{
			// Еслм нет указателя на голову
			if (head == NULL)
			{
				cout << " Список не создан " << endl;
				break;
			}

			cout << " Вы точно хотите удалить список? (Введите цифру) "
				<< "\n 1. Да \n 2. Нет" << endl;
			cin >> value;

			if (value==2)
			{
				break;
			}
			
			//Удаление по одной строчке
			for (int i = 0;i < Count;++i)
			{
				Delete_Data_File(1);
			}
			Delete_List();
			
			break;
		}
		case 4:
		{
			
         
		    cout << "\n Введите расположение в списке (от 1 до "<<Count+1<<" ): ";
			cin >> location;
			
			if (1 > location or location > Count+1)
			{
				cout << " Неправильно введено расположение " << endl;
				break;
			}

			cout << "\n Введите название: ";
			
			cin >> name;

			cout << "\n Введите адрес (без пробелов): ";
			cin >> address;

			cout << "\n Введите номер телефона: ";
			cin >> phone;

			cout << "\n Введите количество залов: ";
			cin >> halls;

			cout << "\n Введите вместимость: ";
			cin >> capacity;

			cout << "\n Введите среднюю цену: ";
			cin >> price;
			// Добавление строчки в файл
			Insert_Data_File(name, address, phone, halls, capacity, price, location);
			if (head == NULL)
			{
				// Создание списка, если его нет
				Create_List(Fname);
				
			}
			else
			{
				Insert_Data(name, address, phone, halls, capacity, price, location - 1);
			}
			cout << " Элемент добавлен" << endl;

			

			break;
		}
		case 5:
		{

			Delete_Tail();

			break;
		}
		case 6:
		{
			if (head == NULL)
			{
				cout << " Список не создан" << endl;
				break;
			}
			cout << " Номер строки (от 1 до "<<Count<<") :";
			
			cin >> location;
			Delete_Data_File(location);
			Delete_Data(location-1);
			cout << " Элемент удалён" << endl;

			break;
		}
		case 7:
		{
			if (head == NULL)
			{
				cout << " Список не создан" << endl;
				break;
			}
			cout << "\t\n Исходный список: " << endl;

			Print_List();

			cout << "\n 1) Название\n 2) Адрес\n 3) Номер телефона"<<
			"\n 4) Количество залов\n 5) Вместимость \n 6) Средняя цена"<<endl;

			cout << " Номер :";
			
			cin >> value;

			
			if (1 > value or value > 6)
			{
				cout << " Неправильно введено расположение " << endl;
				break;
			}
			if (value < 4)
			{
				string value2="fff";	// Любая строка, чтобы функция определила тип данного
				Sort_Data(value-1,value2);
			}
			else
			{
				int value2=1 ; // Любое число, чтобы функция определила тип данного
				Sort_Data(value - 1, value2);
			}
			
			
			cout << "\n";
			Print_List();
			break;
		}
		case 8:
		{
			if (head == NULL)
			{
				cout << " Список не создан" << endl;
				break;
			}

			cout << "\t\nИсходный список: " << endl;
			Print_List();
			

			cout << "\n\n 1) Название\n 2) Адрес\n 3) Номер телефона" <<
				"\n 4) Количество залов\n 5) Вместимость \n 6) Средняя цена" << endl;
			cout << " Номер :";

			cin >> value;

			
			if (1 > value or value > 6)
			{
				cout << " Неправильно введено расположение " << endl;
				break;
			}

			if (value < 4)
			{
				cout << " Введите строковой запрос :" << endl;

				cin >> request;

				Selection(value - 1, request);
				break;
			}
			else 
			{
				cout << " Введите числовую границу: " << endl;
				cin >> request2;
				Selection(value - 1, request2);
				break;
				
			}
		}
		case 9:
		{
			Max_Capacity();
			break;
		}
		default:
		{
			cout << "\n Введите значение ещё раз :" << endl;
			break;
		}
		}
		system("pause");
		system("cls");
	}



}


void Create_List(const char* Fname)
{
	if (head != NULL)
	{
		cout << "  Спиcок уже создан" << endl;
		return;
	}
	fstream fin;
	fin.open(Fname);
	int i = 0;
	while(fin.peek()!=EOF)
	{

		list* temp = new list;      // Новый элемент


		if (i == 0)
		{
			head = temp;       // Начало - голова

		}
		else
		{

			tail->next = temp;  //Связь с предыдущим элементом


		}
		temp->prev = tail;     // Связь с предыдущим элементом
		tail = temp;		   // Текущий элемент - хвост
		temp->next = NULL;	   // Следующего элемента пока что нет

		
		fin >> temp->name;// Заполнение данных
		fin >> temp->address;
		fin >> temp->number;
		fin >> temp->halls;
		fin >> temp->capacity;
		fin >> temp->price;

		i++;
		Count++;
	}
	cout << "  \n Список создан" << endl;
	//Очистка чтения
	fin.clear();
	//Переход на начало для чтения данных
	fin.seekg(0, ios::beg);
	fin.close();
}


void Print_List()
{

	
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}
	list* actual = head;

	 // Вывод шапки
	cout << setw(6) << "Номер" << "\t" << setw(10) << "Название" << "  " << setw(20) << "Адрес" << "  "
		<< setw(16) << "Номер телефона" << "   " << setw(13) << "Кол-во залов" << "  " << setw(12)
		<< "Вместимость" << "  " << setw(7) << "Ср.цена" << endl;

	int i = 0;
	while (actual != NULL)       // Пока не достигнем конца списка
	{
		cout <<setw(6)<<i+1<< "\t" <<setw(10)<< actual->name <<"  "<<setw(20)<<actual->address << "  " 
			<<setw(15)<< actual->number << "   " << setw(10)<<actual->halls << "  " <<setw(12)
			<< actual->capacity << "  " <<setw(7)<< actual->price<<endl;


		actual = actual->next;
		i++;
	}
}

void Delete_List()
{
	if (head == NULL)
	{
		cout << " \n Память свободна" << endl;
		return;
	}

	while (head != NULL)   // Удаление головы, пока список не пуст
	{
		list* actual = head;     // Актуальный элемент - голова
		head = actual->next;   // Следующий элемент - голова
		actual->prev = NULL;
		actual->next = NULL;
		delete actual;
		
	}

	head = NULL;
	tail = NULL;

	cout << " Список удалён " << endl;


	Count = 0;
}


void Insert_Data(const string& name,
				const string& address,
				const string& number,
				const int& halls,
				const int& capacity,
				const int& price, const int& location)
{
	

	list* actual = head;
	int i = 0;

	while (i != location)       // Переходим на месторасположение
	{
		i++;
		actual = actual->next;
	}

	list* temp = new list;
	

	if (actual == NULL)     // Если добавляем последний элемент
	{
		tail->next = temp;
		temp->next = NULL;
		temp->prev = tail;
		tail = temp;
	}
	else
	{

		if (i != 0)
		{

			actual->prev->next = temp;    //Меняем связи с предыдущим эл.


			temp->prev = actual->prev;    //Меняем связи с предыдущим эл   

		}
		else
		{
			head = temp;       // Новый элемент- голова
			temp->prev = NULL;
		}
      actual->prev = temp;    
	}
	       // Соединяем с актуальным
	temp->next = actual;
	temp->name = name;            // Записываем значение
	temp->address = address;
	temp->number = number;
	temp->halls = halls;
	temp->capacity = capacity;
	temp->price = price;
	
	Count++;
}

void Delete_Tail()
{
	if (head == NULL)
	{
		cout << " \nСписок не создан " << endl;
		return;
	}
	list* actual = tail;      //Начинаем с хвоста
	tail = actual->prev;      // Меняем хвост на пред

	if (Count == 1)
	{
		head = NULL;
	}
	else
	{

		tail->next = NULL;  // Рвём связи с последним эл.
	}
	delete actual;
	Delete_Data_File(Count);
	Count--;
	cout << " \n Хвост удалён " << endl;
	
}


//Указатели на поля структуры
string list::* p1 = &list::name,
list::* p2 = &list::address,
list::* p3 = &list::number;

int list::* p4= &list::halls,
list::* p5 = &list::capacity,
list::* p6 = &list::price;

//Массивы указателей
string list::* (FieldArray1[3]) = { p1,p2,p3 };

int list::* (FieldArray2[3]) = { p4,p5,p6 };


void Sort_Data(const int& x,const string& value)
{
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}
	string* array=new string[Count];    // Строковой массив
	list* actual = head;

	// Запись массива
	for (int i = 0;i < Count;++i)
	{
		array[i] = actual->*FieldArray1[x % 3];
		actual = actual->next;
		
	}

	int end = Count;
	string Bufer;
	// Сортировка
	for (int i = 0;i < Count;i++)
	{
		for (int j = 0;j < end-1;j++)
		{
			if (array[j] > array[j + 1])
			{
				Bufer = array[j];
				array[j] = array[j + 1];
				array[j + 1] = Bufer;
			}
		}
		end--;
	}
	

	actual = head;
	
	int begin = 0;
	for (int i=0;i<Count-1;++i)
	{
		for (int j = begin;j < Count;++j)
		{
			
				if (array[i] == actual->*FieldArray1[x % 3])
				{
					// Если совпало - вставляем в нужном порядке в список

					Insert_Data_File(actual->name, actual->address,
						actual->number, actual->halls,
						actual->capacity, actual->price, i+1);

					Insert_Data(actual->name, actual->address,
						actual->number, actual->halls,
						actual->capacity, actual->price, i);

					// Удаляем прошлую запись с учётом сдвига

					Delete_Data_File(j + 2);
					Delete_Data(j + 1);
					break;
				}
			
			
			actual = actual->next;

		}

		// Переход от предпослед. эл к последнему не нужен
		if (i < Count - 2)
		{
			actual = head;
			for (int k = 0;k < i + 1 ;++k)
			{
				actual = actual->next;
			}
		}
		begin++;
		
		
	}

	delete[]array;
}

void Sort_Data(const int& x,const int& value)
{

	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}

	int* array = new int[Count];
	list* actual = head;

	for (int i = 0;i < Count;++i)
	{
		array[i] = actual->*FieldArray2[x % 3];
		actual = actual->next;
		
	}

	int end = Count;
	int Bufer;
	for (int i = 0;i < Count;i++)
	{
		for (int j = 0;j < end - 1;j++)
		{
			if (array[j] > array[j + 1])
			{
				Bufer = array[j];
				array[j] = array[j + 1];
				array[j + 1] = Bufer;
			}
		}
		end--;
	}


	actual = head;

	int begin = 0;
	for (int i = 0;i < Count - 1;++i)
	{
		for (int j = begin;j < Count;++j)
		{

			if (array[i] == actual->*FieldArray2[x % 3])
			{
				Insert_Data_File(actual->name, actual->address,
					actual->number, actual->halls,
					actual->capacity, actual->price, i + 1);

				Insert_Data(actual->name, actual->address,
					actual->number, actual->halls,
					actual->capacity, actual->price, i);

				Delete_Data_File(j + 2);
				Delete_Data(j + 1);
				break;
			}


			actual = actual->next;

		}

		if (i < Count - 2)
		{
			actual = head;
			for (int k = 0;k < i + 1;++k)
			{
				actual = actual->next;
			}
		}
		begin++;


	}

	delete[]array;
}

void Delete_Data(const int& location)
{
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}

	if (0 > location or location > Count - 1)
	{
		cout << " Неправильно введено расположение " << endl;
		return;
	}



	list* actual = head;
	int i = 0;
	while (i != location)       // Переходим на месторасположение
	{
		i++;
		actual = actual->next;
	}
	
	if (Count == 1)
	{
		head = NULL;
		actual->prev = NULL;
		actual->next = NULL;
		tail = NULL;
		delete actual;
		Count--;
		return;
	}


	if (i == 0 )
	{

		
        head = actual->next;

	}
	else if (i==Count-1)
	{
		tail = actual->prev;
		tail->next = NULL;
	}
	else 
	{
		actual->prev->next = actual->next;
		actual->next->prev = actual->prev;//Меняем связи с предыдущим эл.
	}
	actual->prev = NULL;           
	actual->next = NULL;
	delete actual;

	
	Count--;

	
}

void Selection(const int& x, const string& request)
{
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}

	list* actual = head;
	int k = 0;
	string Bufer;		// Переменная для сравнения данных
	bool Info = 1;		// Переменная для вывода

	cout << setw(6) << "Номер" << "\t" << setw(10) << "Название" << "  " << setw(20) << "Адрес" << "  "
		<< setw(16) << "Номер телефона" << "   " << setw(13) << "Кол-во залов" << "  " << setw(12)
		<< "Вместимость" << "  " << setw(7) << "Ср.цена" << endl;

	while (actual != NULL)
	{
		Bufer = actual->*FieldArray1[x % 3];

		for (int i = 0;Bufer[i] != '\0';++i)
		{
			// Если есть совпадение 1-ого элемента
			if (Bufer[i] == request[0])
			{
				// Проверка следующих символов
				int j = 1;
				// Пока не кончилась строка запроса
				while(request[j]!='\0')
				{
					i++;
					if (Bufer[i] == '\0')
					{
						Info = 0;
						break;
					}

					// Если больше нет совпадения
					if (Bufer[i] != request[j])
					{
						Info = 0;
						break;
					}
						
					j++;
						
				}
				if (Info)
				{
					cout << setw(6) << k + 1 << "\t" << setw(10)
						<< actual->name << "  " << setw(20) << actual->address << "  "
						<< setw(15) << actual->number << "   " << setw(10) << actual->halls << "  " << setw(12)
						<< actual->capacity << "  " << setw(7) << actual->price << endl;
					k++;
					break;
				}
				// Обновляем информацию
				Info = 1;
			}

			if (Bufer[i] == '\0')
		    {
				break;
		    }
			
		}
		
		
		actual = actual->next;
	}

	if (k == 0)
	{
		cout << "\n\t\t Нет данных по заданному значению" << endl;
	}
}


void Selection(const int& x, const int& request)
{

	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}

	list* actual = head;
	int k = 0;
	cout << setw(6) << "Номер" << "\t" << setw(10) << "Название" << "  " << setw(20) << "Адрес" << "  "
		<< setw(16) << "Номер телефона" << "   " << setw(13) << "Кол-во залов" << "  " << setw(12)
		<< "Вместимость" << "  " << setw(7) << "Ср.цена" << endl;
	while (actual != NULL)
	{
		if ( request > actual->*FieldArray2[x % 3])
		{
					cout << setw(6) << k + 1 << "\t" << setw(10)
						<< actual->name << "  " << setw(20) << actual->address << "  "
						<< setw(15) << actual->number << "   " << setw(10) << actual->halls << "  " << setw(12)
						<< actual->capacity << "  " << setw(7) << actual->price << endl;
					k++;
					
		}
				
		actual = actual->next;
	}

	if (k == 0)
	{
		cout << "\n\t\t Нет данных по заданному значению" << endl;
	}
}

void Delete_Data_File(const int& x)
{
	if (head == NULL)
	{
		cout << " Список не создан " << endl;
		return;
	}
	if (1 > x or x > Count)
	{
		cout << " Неправильно введено расположение " << endl;
		return;
	}
	ifstream in;
	in.open(Fname);
	int number_now = 0;
	string line;
	string file_text;
	// Пока есть данные
	while (getline(in, line))
	{
		number_now++;

		if (number_now != x )
		{
			
			if (number_now != 1 and !(number_now==2 and x==1) )
			{
				file_text.insert(file_text.size(), "\r\n");
				
			}
			file_text.insert(file_text.size(), line);
			
		}
	
	}
	
	ofstream of;
	
	of.open(Fname, std::ios::trunc | std::ios::binary);
	of.write(file_text.c_str(), file_text.size());
	
	of.clear();
	of.close();
	//Переход на начало для чтения данных
	in.seekg(0, ios::beg);
	in.close();
}

void Insert_Data_File(const string& name,
	const string& address,
	const string& number,
	const int& halls,
	const int& capacity,
	const int& price, const int& x)
{
	ifstream in;
	in.open(Fname);
	int number_now = 0;
	string line;
	string file_text;
	string data; // Вводимые данные

	data.insert(data.size(), name+"  " + address + "  " + number + "  "
		+ to_string(halls) + "  " + to_string(capacity) + "  " + to_string(price)); // Создание строки данного
	
	while (getline(in, line))
	{
		
		number_now++;
		
		if (number_now != 1)
		{
			file_text.insert(file_text.size(), "\r\n");

		}
		if (number_now == x)
		{
			file_text.insert(file_text.size(), data);
			file_text.insert(file_text.size(), "\r\n");
		}

       file_text.insert(file_text.size(), line);

	}
	
	// Еслм это последний элемент
	number_now++;
	if (number_now == x)
	{
		if (Count!=0)
		{
			file_text.insert(file_text.size(), "\r\n");
		}
		file_text.insert(file_text.size(), data);
		
	}

	ofstream of;

	of.open(Fname, std::ios::trunc | std::ios::binary);
	of.write(file_text.c_str(), file_text.size());

	of.clear();
	of.close();
	//Переход на начало для чтения данных
	in.seekg(0, ios::beg);
	in.close();
}

void Max_Capacity()
{
	if (head == NULL)
	{
		cout << " Список не создан" << endl;
		return;
	}
	list* actual = head;
	list* Max = actual;  // Сначала первый элемент максимальный

	while (actual != NULL)
	{
		if (actual->capacity > Max->capacity)
		{
			Max->capacity = actual->capacity;
		}
		actual = actual->next;
	}

	cout << "\n\t" << setw(10)
		<< Max->name << "  " << setw(20) << Max->address << "  "
		<< setw(15) << Max->number << "   " << setw(10) << Max->halls << "  " << setw(12)
		<< Max->capacity << "  " << setw(7) << Max->price << endl;
}





