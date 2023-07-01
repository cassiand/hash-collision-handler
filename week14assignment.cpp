// cassian pularo
// 12/11/22
// week 14 assignment
// handling hash collisions


#include <iostream>
#include <string>
using namespace std;

int main() {
	int choice = 0;
	int pos = 0;
	string value;
	string hashtable[10];
	for (int i = 0; i < 10; i++)
		hashtable[i] = "*";

	while (true) {
		cout << "Select an option" << endl;
		cout << "1. Insert value" << endl;
		cout << "2. Display table" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			pos = 0;
			cout << "Enter string:" << endl;
			cin >> value;
			for (int i = 0; i < value.length(); i++)
				pos = pos + value[i];
			pos = pos % 10;
			if (hashtable[pos] == "*") {
				hashtable[pos] = value;
				cout << "String inserted at position " << pos << endl;
			}
			
			else		// if collision
			{						
					for (int j = 0; j < 10; j++)	// loop through possible values
					{
						pos = (pos + (pos ^ j));		// quadratic function, new pos = old pos + (old pos ^ i)
						pos = pos % 10;
						if (hashtable[pos] == "*")	// if empty
						{
							hashtable[pos] = value;	// go there
							cout << "String inserted at position " << pos << endl;
							break;
						}
					}									
			}			
			break;

		case 2:
			for (int i = 0; i < 10; i++)
				cout << hashtable[i] << " ";
			cout << endl;
			break;
		}
	}
	return 0;
}