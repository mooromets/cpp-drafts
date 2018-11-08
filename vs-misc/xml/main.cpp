#include <iostream>
#include <rapidxml.hpp>
#include <rapidxml_print.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace rapidxml;


void walkThru(xml_node<> *pnode) 
{
	if (!pnode)
		return;

	//name
	switch (pnode->type())
	{
	case node_element:
		cout << "<" << pnode->name(); // << " (" << pnode->type() << ") ";

									  //attrs
		for (auto pa = pnode->first_attribute(); pa; pa = pa->next_attribute())
		{
			cout << " " << pa->name() << "=" << pa->value();
		}
		cout << ">" << endl;

		for (auto pn = pnode->first_node(); pn; pn = pn->next_sibling())
		{
			walkThru(pn);
		}
		break;
	case node_data:
		cout << pnode->value() << endl;
		break;
	}
}

int main(void) 
{
	ifstream input("input.xml");

	string buf;
	string text;
	while(getline(input, buf)) 
	{
		text.append(buf);
	}

	xml_document<> doc;    // character type defaults to char
	doc.parse<0>(const_cast<char*>(text.c_str()));

	cout << doc;

	//walk thru
	walkThru(doc.first_node());

	return 0;
}