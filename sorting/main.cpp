// ¬вод адресов из файла, сортировка по городу, вывод в файл

#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>

class address {

private:
	std::string city;
	std::string street;
	int house;
	int flat;

public:
	// геттеры
	std::string get_city()const {
		return city;
	}
	std::string get_street()const {
		return street;
	}
	int get_house()const {
		return house;
	}
	int get_flat()const {
		return flat;
	}

	//сеттеры
	void set_city(std::string citi) {
		this->city = citi;
	}
	void set_street(std::string street) {
		this->street = street;
	}
	void set_house(int house) {
		this->house = house;
	}
	void set_flat(int flat) {
		this->flat = flat;
	}

	//конструктор по умолчанию
	address() {
		city = "No name ";
		street = "No name ";
		house = 0;
		flat = 0;
	}
	 // конструктор с параметрами
	address(std::string city, std::string street, int house, int flat) {
		this -> city = city;
		this -> street = street;
		this -> house = house;
		this -> flat = flat;
	}

	// конструктор копировани€
	address(const address& other) {
		this->city = other.city;
		this->street = other.street;
		this->house = other.house;
		this->flat = other.flat;
	}
	// оператор присваивани€
	address& operator = (const address& other) {
		this->city = other.city;
		this->street = other.street;
		this->house = other.house;
		this->flat = other.flat;
		return *this;
	}
};


int main() {

	setlocale(LC_ALL, "Russian");

	std::string path_in = "in.txt";  // им€ файла присваиваем переменной типа                                                               стринг 
	std::ifstream fin;              //   создаем обьект fin на чтение
	fin.open(path_in);             //  вызов метода  open дл€ открыти€ файла  in.txt.

	std::string path_out = "out.txt";   // им€ файла присваиваем переменной типа стринг
	std::ofstream fout;                //  создаем обьект fout на запись
	fout.open(path_out);              //  вызов метода  open дл€ открыти€ файла out.txt.

	if (!(fin.is_open() || fout.is_open()))      //  is_open  возвращает  true или false
	{
		std::cout << "ќшибка открыти€ файла!" << std::endl;
	}
	else
	{
		int n = 0; // количество блоков с адресами
		fin >> n;
		

		address* arr = new address[n];       //создали динамический массив из N обьектов

		for (int i = 0; i < n; i++)        // цикл перебора всех элементов массива обьектов
		{                             
			std::string b;               // считывание строк одного блока адресов из файла in.txt
			fin >> b;                   // и инициализаци€ полей экземпл€ра класса address номер i.
			arr[i].set_city(b);
			fin >> b;
			arr[i].set_street(b);
			int c = 0;
			fin >> c;
			arr[i].set_house(c);
			fin >> c;
			arr[i].set_flat(c);
		}
		
			address p;

		for (bool swapped = true; swapped;)
		{
			swapped = false;

			for (int i = 0; i < n - 1; i++)
			{
				std::string c = arr[i].get_city();
				std::string v = arr[i + 1].get_city();
				int d = c.compare(v);

				if (d == -1)
				{
					p = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = p;
					swapped = true;
				}

		    }
		}

		           

		fout << n << "\n";
		for (int i = 0; i < n; i++)  // цикл вывода в файл в измененном виде адресов из полей 
		{                            // экземпл€ров
			fout << arr[i].get_city() << ", ";
			fout << arr[i].get_street() << ", ";
			fout << arr[i].get_house() << ", ";
			fout << arr[i].get_flat() << "\n";
		}
		delete[]arr;


		fin.close();
		fout.close();
	}




}