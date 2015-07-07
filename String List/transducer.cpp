#include "transducer.h"
#include "misc.h"
#include <vector>

using namespace std;

string Transducer::transduce(string com)
{
	string result;
	vector<string> token = tokenize(com);

	if(token[0] == "HELP" || token[0] == "H")
	{
		result = "Commands:\n";
		result += "--------------\n";
		result += "\tADDSTRING(AS) <string>\n";
		result += "\tSHOWSTRING(SS)\n";
		result += "\tREMOVESTRING(RS) <stringID>\n";
		result += "\tWORDCOUNT(WC)\n";
		result += "\tWORDLIST(WL)\n";
		result += "\tTEST(T) <numberOfNewStrings>\n";
		result += "\tHELP(H)\n";
		result += "\tQUIT(Q)\n";

	}
	else if(token[0] == "ADDSTRING" || token[0] == "AS")
	{
		result = stringlist.addString(token[1]);
	}
	else if(token[0] == "SHOWSTRING" || token[0] == "SS")
	{
		result = stringlist.showString();
	}
	else if(token[0] == "REMOVESTRING" || token[0] == "RS")
	{
		result = stringlist.removeString(stringToInt(token [1]));
	}
	else if(token[0] == "WORDCOUNT" || token[0] == "WC")
	{
		result = stringlist.wordCount();
	}
	else if(token[0] == "WORDLIST" || token[0] == "WL")
	{
		result = stringlist.wordList();
	}
	else if(token[0] == "TEST" || token[0] == "T")
	{
		result = stringlist.test(stringToInt(token[1]));
	}
	else if(token[0] == "QUIT" || token[0] == "Q" || token[0] == "q" || token[0] == "quit")
	{
		result = "Goodbye.";
	}
	else
	{
		result = "Invalid command!";
	}

	return result;
}



