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




	}











}