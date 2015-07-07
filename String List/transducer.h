#pragma once

#include "stringlist.h"
#include <string>
#include "entry.h"

using namespace std;

class Transducer
{
public:
	string transduce(string com);
private:
	StringList stringlist;

};