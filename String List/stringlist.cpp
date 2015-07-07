#include "stringlist.h"
#include "entry.h"
#include <random>
#include <time.h>

using namespace std;

StringList::StringList()
{
	lastStringIDUsed = 0;
}

string StringList::addString(string token1)
{
	Entry newString;
	newString.input=token1;
	newString.isDeleted = false;
	lastStringIDUsed++;
	newString.id = lastStringIDUsed;
	vEntries.push_back(newString);
	return "String added.";
}

string StringList::removeString(int id)
{
	for(unsigned int i = 0; i < vEntries.size(); i++)
	{
		if(vEntries[i].id == id)
		{
			vEntries[i].isDeleted = true;

			return vEntries[i].input + " was deleted.";
		}
	}

	return "ID not found.";
	
}

string StringList::showString( )
{
	string result;

	result =  padRight("Id",'.',10);
	result += padRight("String",'.',40) + "\n";
	result += padRight("",'-',50) + "\n";

	vector<Entry>::iterator iter;
	
	iter = vEntries.begin();

	while(iter != vEntries.end())
	{
		if(!(*iter).isDeleted)
		{
			result += padLeft(intToString((*iter).id),' ', 8) + "  ";
			result += padRight((*iter).input,' ', 40) + "\n";
		}

		iter++;
	}


	return result;
}

string StringList::wordCount()
{
	unsigned int result = 0;

	for(unsigned int i = 0; i < vEntries.size(); i++)
	{
		if(!vEntries[i].isDeleted)
		{
			for(unsigned int j = 0; j < (vEntries[i].input.length()); j++)
			{
			
				if(j == 0 && vEntries[i].input[j] != ' ')
				{
					result++;
				}
				if(j != 0 && vEntries[i].input[j] != ' ' && vEntries[i].input[j-1] == ' ')
				{
					result++;
				}
			}
		}	
	}

	return ("There are currently " + intToString(result) + " words in your string list.");
}

string StringList::showWordList( )
{
	string result;

	result = padRight("String",'.',50) + "\n";
	result += padRight("",'-',50) + "\n";

	vector<string>::iterator iter;
	
	iter = sorted.begin();

	while(iter != sorted.end())
	{
		result += padRight((*iter),' ', 50) + "\n";

		iter++;
	}


	return result;
}

string StringList::wordList()
{
	string result = "";
	bool check = false;
	string temp = "";
	
	for(unsigned int i = 0; i < vEntries.size(); i++)
	{
		if(!vEntries[i].isDeleted)
		{
			for(unsigned int j = 0; j < (vEntries[i].input.length()); j++)
			{
				while(vEntries[i].input[j] != ' ' && j < (vEntries[i].input.length()) )
				{
					temp += vEntries[i].input[j];

					check = true;

					j++;
				}

				if(check)
				{
					sorted.push_back(temp);
					temp = "";
					check = false;
				}
			
				
			}
		}
	}

	sort(sorted.begin(),sorted.end());

	result = showWordList();

	sorted.clear();

	return result;
}

string StringList::test(int numberOfStrings)
{
	string result = "";
	string charSet = "  ABCDEFGHIJKLMNOPQRSTUVWXYZ  ";

	srand((unsigned int)time(NULL));

	for(int i = 0 ; i < numberOfStrings; i++)
	{
		for(int j = 0; j < ((rand() % 50) + 15); j++)
		{
			result += charSet[rand() % (charSet.length())];
		}

		addString(result);

		result = "";
	}

	return intToString(numberOfStrings) + " strings were added.";
}