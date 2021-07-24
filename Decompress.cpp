#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <fstream>
#include <ostream>

#define SIZE 4096
using namespace std;

string dictionary[SIZE];

void initASCII(string dictionary[]) { //inits the ASCII chars to the first 256 cells of the dictionary array
	for (int i = 0; i < 256; i++) {
		char temp = i;
		dictionary[i] = temp;
	}
	for (int i = 256; i < SIZE - 1; i++)
	{
		dictionary[i] = ""; //TODO look at this
	}
}

bool doesExist(int code) {

	if (dictionary[code] == "")
	{
		return false;
	}
	return true;
}

string decompressionAlgo(string codes) {


	int pW = NULL;
	int cW;
	int dictionaryIndex = 256;
	string stringpW, stringcW, p, c;
	string sum = p + c;
	string realCode;
	int j = 0;
	string decompressed;
	int abbb = codes.length();
	int flag = true;

	for (int i = 0; i < codes.length(); i++)
	{
		while (j < abbb && codes[j] != ' ')
		{
			realCode = realCode + codes[j];
			j++;
		}
		j++;

		cW = atoi(realCode.c_str());

		if (flag) //just for the first code since it will always be in the dictionary
		{
			stringcW = dictionary[cW];
			decompressed.append(stringcW);
			flag = false;
		}
		else if (doesExist(cW))
		{
			stringcW = dictionary[cW];
			decompressed.append(stringcW);
			dictionary[dictionaryIndex] = stringpW + stringcW[0];
			dictionaryIndex++;
		}
		else if(!doesExist(cW))
		{
			stringcW = stringpW + stringpW[0];
			dictionary[dictionaryIndex] = stringcW;
			decompressed.append(stringcW);
			dictionaryIndex++;
		}
		

		pW = cW;
		stringpW = stringcW;
		realCode = "";
	}

	return decompressed;
}

int main() {

	vector<int> codeSequence;
	string codes;
	string decompressed;

	ifstream compout;
	compout.open("compout.txt");

	while (getline(compout, codes)) //This loop fills the set with the search words and doc numbers
	{
		istringstream iss(codes);
	}

	initASCII(dictionary);

	decompressed = decompressionAlgo(codes);

	ofstream decompout("decompout.txt");

	decompout << decompressed;

	decompout.close();

	return 0;
}