#pragma once

#include <string>
#include <vector>

using namespace std;

class Entry
{
public:
	friend class StringList;

private:
	string input;
	int id;
	bool isDeleted;
};
