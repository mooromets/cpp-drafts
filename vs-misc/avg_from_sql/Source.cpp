#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

const int c1[16] = { 1,2,3,60,70,7,7,4,4,65,65,76,897,90,98,98 };
const char *c2[16] = { "abc","xxx","abc","xyz","","abc0","abc0","aaa","abc","xxx","abc","xyz","","abc0","abc0","aaa" };

template <class ValType>
class AvgSq
{
public:
	using ResultType = ValType;
	AvgSq() : m_SumSq(0), m_Count(0) { }
	ResultType operator() (const ValType val)
	{
		m_SumSq += val * val;
		++m_Count;
		return m_SumSq / m_Count;
	}
private:
	ValType m_SumSq;
	int m_Count;
};

template <class UnariOperation>
std::pair<bool, typename UnariOperation::ResultType>
applyEach(const int *c1, const char *c2[], int size, const char *filter, UnariOperation op)
{
	assert(c1 && c2 && filter);

	//compare function    
	auto cmp = [filter](const char *x) -> bool {return !strcmp(x, filter); };

	auto res = std::make_pair<bool, int>(false, 0);
	auto c2End = c2 + size;

	auto it = std::find_if(c2, c2End, cmp);
	while (it != c2End)
	{
		res.first = true;
		res.second = op(c1[std::distance(c2, it)]);
		it = std::find_if(it + 1, c2End, cmp);
	}

	return res;
}

int main()
{
	auto res = applyEach(c1, c2, 16, "abc", AvgSq<int>());
	std::cout << "RES " << res.first << " - " << res.second << std::endl;
}
