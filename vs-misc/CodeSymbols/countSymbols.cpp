#include <iostream>
#include <fstream>
#include <string>
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

struct SymbStats
{
	int nPunct;
	int nTotal;
};

SymbStats countInFile(string fileName)
{
	SymbStats sym{ 0, 0 };

	ifstream ifs(fileName);
	char bufCahr;

	while (ifs.get(bufCahr))
	{
		++sym.nTotal;
		if (ispunct(bufCahr))
			++sym.nPunct;
	}

	return sym;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "enter a filename";
		return 0;
	}

	auto sym = countInFile(argv[1]);

	cout << endl << sym.nPunct << " of " << sym.nTotal << 
		"; Rate: " << static_cast<double> (sym.nPunct) / sym.nTotal << endl;

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

