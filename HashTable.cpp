#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

#define Hash_Size 4001

class Hash {
public:
	Hash() { tableSize = 0; firstCheck = -1; }

	int H(string x);
	int size();
	void update(string x);
	bool search(string x) { return (array[H(x)] == x); }

	string look(int i) { return array[i]; }

private:
	string array[Hash_Size];
	int tableSize;
	int firstCheck;			// first checked index
};

int main() {
	fstream f;
	int array[Hash_Size];
	char s[100];

	Hash h;

	f.open("RomeoAndJuliet.txt");
	while (!f.eof()) {
		while (f >> s) {
			h.update(s);
		}
	}

	cout << h.size();

	return 0;
}

int Hash::H(string x) {
	int y = 0;
	for (int i = 0; i < x.size(); i++) {
		y += int(x[i]);
	}
	return y % Hash_Size;
}
int Hash::size(){
	return tableSize;
}
void Hash::update(string x) {
	int hashValue = H(x);
	// check for collision
	if (array[hashValue] == "\0") {
		array[hashValue] = x;
		tableSize++;
	}
	else {
		if (array[hashValue] == x) {
			return;
		}
		firstCheck = hashValue;
		hashValue++;
		while (firstCheck != hashValue) {
			if (array[hashValue] == "\0") {
				array[hashValue] = x;
				tableSize++;
				return;
			}
			hashValue++;
			if (array[hashValue] == x) {
				return;
			}
		}
	}
	
}
