#include <iostream>
#include <fstream>
//#include <string>
//#include <functional>
//#include <unordered_map>
#include <ctype.h>


//////
//  Ccount a number of symbols in code that don't match in EN and DE keyboards
//////

using namespace std;
/*
void applyToSymbols(std::string filename, std::function<void(const char)> funAppl) 
{
	ifstream ifs("countSymbols.cpp");
	char bufCahr;
	while (ifs.get(bufCahr))
	{
		funAppl(bufCahr);
	}
}
*/

int main(void) 
{
	ifstream ifs("countSymbols.cpp");
	char bufCahr;
	auto punct { 0 };
	auto total { 0 };

	while (ifs.get(bufCahr))
	{
		++total;
		if (ispunct(bufCahr))
			++punct;
	}

	cout << endl << punct << " of " << total << "; Rate: " << static_cast<double> (punct) / total << endl;

	return 0;

	/*
	unordered_map<char, int> counter;

	applyToSymbols("countSymbols.cpp", 
		[&counter] (const char c) 
		{
			auto it = counter.find(c);
			if (it != counter.end()) 
			{
				++(it->second);
			}
			else 
			{
				counter[c] = 0;
			}
		});

	std::ispunct

	auto samePlace { 0 };
	auto changedPlace { 0 };
	for (auto sym : counter)
	{

	}
	*/
}

