#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;
const int DICTWORD = 23907;
void readFile(const string& filename, string*);
void trackCharacters(char* line, int lineNumb, const string* dict);
bool binarySearch(const char* word1, const string* dict);
void lowerCaseChar(char* text);
void lowerCaseString(string& text);
void insertionSortForList(string* list1);
int main()
{

	const string randomWords = "unsorted_words.txt";
	const string text = "ihaveadream.txt";
	char buffer[1024];
	string word1;
	string* dict = new string[DICTWORD];
	readFile(randomWords, dict);


	int lineNumb = 0;
	ifstream fina(text.c_str());
	if (!fina)
	{
		cerr << "cannot open word file " << text << endl;
		exit(1);
	}
	while (!fina.eof())
	{
		lineNumb++;
		fina.getline(buffer, sizeof(buffer));
		lowerCaseChar(buffer);
		trackCharacters(buffer, lineNumb, dict);
	}
	delete[] dict;
	cin.get();
}
void trackCharacters(char* line, int lineNumb, const string* dict)
{
	char* ptr = line;
	vector<char*> ptr_arry;
	ptr = strtok(line, " <>?!:,.;[]{}\"-=_+\\\r\n"); // Check for all non-alphaneumeric characters
	ptr_arry.push_back(ptr);
	while (ptr != NULL)
	{
		ptr = strtok(NULL, " <>?!:,.;[]{}\"-=_+\\\r\n");
		ptr_arry.push_back(ptr);
	}

	while (ptr != NULL)
	{
		if (!binarySearch(ptr, dict))
		{
		    exit(0);
			cout << "Misspelled word, " << ptr << " on line " << lineNumb << endl;
		}
		ptr = strtok(NULL, " <>?:,.;[]{}-=_+\\\r\n");
	}

	for (int words = 0; words < ptr_arry.size() - 1; words++)
	{
		if (!binarySearch(ptr_arry[words], dict))
		{
			cout << "Misspelled word, " << ptr_arry[words] << " on line " << lineNumb << endl;
		}
	}

}


void readFile(const string& filename, string* dict)
{
	ifstream fina(filename.c_str());
	if (!fina)
	{
		cerr << "cannot read word file " << filename << endl;
		exit(1);
	}
	for (int i = 0; i < DICTWORD; i++)
	{
		fina >> dict[i];
		lowerCaseString(dict[i]);
	}
}
bool binarySearch(const char* wordv, const string* dict)
{
	int lowv, highv, middlev;
	string word_string(wordv);
	lowv = 0;
	highv = DICTWORD - 1;
	string middleWord1;
	int compare1;
	while (lowv <= highv)
	{
		middlev = (lowv + highv) / 2;
		middleWord1 = dict[middlev];
		compare1 = strcmp(wordv, middleWord1.c_str());
		if (compare1 < 0)
		{
			highv = middlev - 1;
		}
		else if (compare1 > 0)
		{
			lowv = middlev + 1;
		}
		else
		{
            return true;
		}
	}
	//Commenting out the check for 's and s)
	// Check for 's
	if (word_string.substr(word_string.size() - 1, 1) == "s")
	{
		if (binarySearch(word_string.substr(0, word_string.size() - 1).c_str(), dict))
		{
			return true;
		}
	}
	return false;

}


void lowerCaseChar(char* text1)
{
	for (size_t k = 0; k< strlen(text1); k++)
    {
        text1[k] = tolower(text1[k]);
    }
}


void lowerCaseString(string& text1)
{
	for (size_t k = 0; k < text1.size(); k++)
		text1[k] = tolower(text1[k]);
}

void insertionSortForList(string* list1)
{
	int m, key;
	string tmp;
	bool found;
	for (int i1 = 1; i1 < DICTWORD; i1++)
	{
		found = false;
		tmp = list1[i1];
		for (key = 0, m = i1 - 1; m >= 0 && !found; key++)
		{
			if (tmp < list1[m])
			{
				list1[m + 1] = list1[m];
				m--;
			}
			else
			{
				found = true;
			}
		}
		list1[m + 1] = tmp;
	}
}
