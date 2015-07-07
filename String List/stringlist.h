#pragma once

#include <string>
#include <vector>
#include "misc.h"
#include "entry.h"
#include <algorithm>

using namespace std;

class StringList
{
public:
	StringList();
	string addString(string token1);
	string showString();
	string removeString(int id);
	string wordCount();
	string wordList();
	string showWordList();
	string test(int numberOfStrings);
private:
	vector<Entry> vEntries;
	int lastStringIDUsed;
	vector<string> sorted;

};

