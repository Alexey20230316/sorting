// ���� ������� �� �����, ���������� �� ������, ����� � ����

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
	// �������
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

	//�������
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

	//����������� �� ���������
	address() {
		city = "No name ";
		street = "No name ";
		house = 0;
		flat = 0;
	}
	 // ����������� � �����������
	address(std::string city, std::string street, int house, int flat) {
		this -> city = city;
		this -> street = street;
		this -> house = house;
		this -> flat = flat;
	}

	// ����������� �����������
	address(const address& other) {
		this->city = other.city;
		this->street = other.street;
		this->house = other.house;
		this->flat = other.flat;
	}
	// �������� ������������
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

	std::string path_in = "in.txt";  // ��� ����� ����������� ���������� ����                                                               ������ 
	std::ifstream fin;              //   ������� ������ fin �� ������
	fin.open(path_in);             //  ����� ������  open ��� �������� �����  in.txt.

	std::string path_out = "out.txt";   // ��� ����� ����������� ���������� ���� ������
	std::ofstream fout;                //  ������� ������ fout �� ������
	fout.open(path_out);              //  ����� ������  open ��� �������� ����� out.txt.

	if (!(fin.is_open() || fout.is_open()))      //  is_open  ����������  true ��� false
	{
		std::cout << "������ �������� �����!" << std::endl;
	}
	else
	{
		int n = 0; // ���������� ������ � ��������
		fin >> n;
		

		address* arr = new address[n];       //������� ������������ ������ �� N ��������

		for (int i = 0; i < n; i++)        // ���� �������� ���� ��������� ������� ��������
		{                             
			std::string b;               // ���������� ����� ������ ����� ������� �� ����� in.txt
			fin >> b;                   // � ������������� ����� ���������� ������ address ����� i.
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
		for (int i = 0; i < n; i++)  // ���� ������ � ���� � ���������� ���� ������� �� ����� 
		{                            // �����������
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