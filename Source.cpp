#include <iostream>
#include <vector>
#include <iterator>


using namespace std;
void first() {
//1)Создать пустой вектор типа string.Написать программу, которая записывает в вектор предложения и вывести содержимое вектора на экран.
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
	//2) Создать пустой вектор типа int. Написать программу, которая записывает в вектор только положительные числа. 
	//При вводе отрицательного числа заполнение вектора прекратить. 
	//Вывести содержимое вектора на экран с помощью цикла, основанного на диапазоне.
	vector <int> intVector;
	int number;
	cout << "Number > 0\n";
	while ((cin >> number) && number > 0) intVector.push_back(number);
	vector<int>::iterator znachenie;
	for (znachenie = intVector.begin(); znachenie < intVector.end(); znachenie++) cout << *znachenie << endl;
}

void third() {
//3) Создать пустой вектор типа double. 
//Написать программу, которая записывает в вектор числа до тех пор, пока не введен ноль. 
//Вывести на экран с помощью итератора только положительные элементы вектора. 

	vector <double> doubleVector;
	double number;
	cout << "Number != 0\n";
	while ((cin >> number) && number != 0) doubleVector.push_back(number);
	vector<double>::iterator znachenie;
	for (znachenie = doubleVector.begin(); znachenie < doubleVector.end(); znachenie++) if (*znachenie > 0) cout << *znachenie << endl;
}

void fourth() {
	//4)Обработка исключительных ситуаций. Ввести фамилию, год рождения и пол студента. 
	//Проверить правильность ввода пола и года рождения. Обратить исключительные ситуации.
	class family {
	private:
		string familia;
		float yearOfBirth;
		string pol;
	public:
		void input() {
			string f;
			float y;
			string p;

			cout << "Familia: \n";
			cin >> f;
			cout << "Year: \n";
			cin >> y;
			try {
				if (y < 1900 || y > 2020) throw 0.12;
			}
			catch (float) {
				cout << "Err. Y: \n";
				cin >> y;
			}
			cout << "Pol: \n";
			cin >> p;
			try {
				if (p != "W" && p != "w" && p != "M" && p != "m") throw 0;
			}
			catch (int) {
				cout << "Err. P: \n";
				cin >> p;
			}
			familia = f;
			pol = p;
			yearOfBirth = y;
		}
		void output() {
			cout << familia << " " << yearOfBirth << " " << pol << endl;
		}
	};
	family Person;
	Person.input();
	Person.output();

}
int main() {
	fourth();
	return 0;
}