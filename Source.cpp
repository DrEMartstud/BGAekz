#include <iostream>
#include <vector>
#include <iterator>


using namespace std;
void first() {
//1)������� ������ ������ ���� string.�������� ���������, ������� ���������� � ������ ����������� � ������� ���������� ������� �� �����.
	vector <string> ourVector;
	string s;
	for (int i = 0; i < 5; i++) {
		cout << i << ": ";
		cin >> s;
		ourVector.push_back(s);
	}
	vector<string>::iterator ukaz;
	for (ukaz = ourVector.begin(); ukaz != ourVector.end(); ukaz++) cout << *ukaz << endl;
}

void second() {
	//2) ������� ������ ������ ���� int. �������� ���������, ������� ���������� � ������ ������ ������������� �����. 
	//��� ����� �������������� ����� ���������� ������� ����������. 
	//������� ���������� ������� �� ����� � ������� �����, ����������� �� ���������.
	vector <int> intVector;
	int number;
	cout << "Number > 0\n";
	while ((cin >> number) && number > 0) intVector.push_back(number);
	vector<int>::iterator znachenie;
	for (znachenie = intVector.begin(); znachenie < intVector.end(); znachenie++) cout << *znachenie << endl;
}
void third() {
//3) ������� ������ ������ ���� double. 
//�������� ���������, ������� ���������� � ������ ����� �� ��� ���, ���� �� ������ ����. 
//������� �� ����� � ������� ��������� ������ ������������� �������� �������. 

	vector <double> doubleVector;
	double number;
	cout << "Number != 0\n";
	while ((cin >> number) && number != 0) doubleVector.push_back(number);
	vector<double>::iterator znachenie;
	for (znachenie = doubleVector.begin(); znachenie < doubleVector.end(); znachenie++) if (*znachenie > 0) cout << *znachenie << endl;
}
int main() {
	
	return 0;
}