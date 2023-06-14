#include "main.h"

#define min_init 1
#define max_init 9

#define wrong_init "Wrong int value!"
#define wrong_msg "Wrong answer!"

int rand_number(int a, int b) {
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	return rand() % (b + 1 - a) + a;
}

bool rand_operation() {
	return rand() % 2;
}

string convert_to_string(long time) {
	int hour = time / 3600 % 24;
	int min = time % 3600 / 60;
	int sec = time % 60;

	string stime = to_string(hour);
	stime += (min > 9 ? ":" : ":0") + to_string(min);
	stime += (sec > 9 ? ":" : ":0") + to_string(sec);

	return stime;
}

int read_int(string prompt) {
	string input;

	while (true) {
		bool flag = true;

		cout << prompt;
		cin >> input;

		for (int i = 0; i < input.size(); i++)
		{
			if (!isdigit(input[i])) {
				cout << wrong_init << endl;
				flag = false;
				break;
			}
		}

		if (flag) {
			break;
		}
	}

	return stoi(input);
}


int main() {
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	char yesno;

	do {
		system("cls");

		int number = read_int("\nInput number of exercise (количество решаемых примеров): ");
		long start_time = time(NULL);
		cout << "\nSTART time: " + convert_to_string(start_time) << "\n\n";

		int error = 0;
		int count = 0;

		for (int i = 0; i < number; i++)
		{
			int a = rand_number(min_init, max_init);

			int b = rand_number(min_init, max_init);
			while (b == a) {
				b = rand_number(min_init, max_init);
			}

			int c = rand_number(min_init, max_init);
			while (c == a || c == b) {
				c = rand_number(min_init, max_init);
			}

			bool operation = rand_operation();

			if (a < b && !operation) {
				int t = a;
				a = b;
				b = t;
			}

			int result = operation ? a + b - c : a - b + c;

			if (result < 0) {
				int t = b;
				b = c;
				c = t;

				result = operation ? a + b - c : a - b + c;
			}

			string msg = to_string(i + 1) + ") ";
			msg += to_string(a);

			if (operation) {
				msg += " + " + to_string(b) + " - ";
			}
			else {
				msg += " - " + to_string(b) + " + ";
			}

			msg += to_string(c) + " = ";

			int answer;

			do {
				answer = read_int(msg);
				if (answer != result) {
					cout << wrong_msg << endl;
				}
			} while (answer != result);
		}

		long finish_time = time(NULL);
		cout << "\nFINISH time: " + convert_to_string(finish_time) << endl;

		cout << "\nYour TOTAL time : " + convert_to_string(finish_time - start_time) << endl;

		cin.ignore();
		cout << "\nTry again? (y/n)";
		yesno = _getch();

		yesno = tolower(yesno);

	} while (yesno == 'y');

	system("cls");

	
	return 0;
}