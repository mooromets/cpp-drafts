#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

using MyPair = pair<int, double>;

bool cmp(const MyPair  &p1, const MyPair &p2)
{
	return p1.second < p2.second;
}

int copyMap2Vector()
{
	map<int, double> m;
	for (int i = 0; i < 10; ++i)
		m[i] = i * -i;

	vector<MyPair> v(m.begin(), m.end()); // copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].first << " : " << v[i].second << endl;
	return 0;
}
