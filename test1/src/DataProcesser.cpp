#include <numeric>
#include <vector>
#include <algorithm>

#include "DataProcesser.h"

using namespace std;

void DataProcesser::doJob() 
{
	//prepare queues
	vector<size_t> idx(m_InBuf.size());
	iota(std::begin(idx), std::end(idx), 0); // fill with indexes
	random_shuffle(std::begin(idx), std::end(idx)); // balance the load

	//split queue into m_nThreads parts
	auto part = static_cast<int> (idx.size() / m_nThreads);
	auto itBeg = std::begin(idx);
	auto itEnd = itBeg;
	do {
		if (itEnd - itBeg + part <= idx.size())
		{
			itEnd = itBeg + part + 1;
		}
		else 
		{
			itEnd = std::end(idx);
		}

		//TODO call m_Job in seperate thread on each element in subqueue

		itBeg = itEnd;
	} while (itEnd != std::end(idx));
}


//TODO refactor params
static void _job(const Converter::InputBuffer &inbuf,
	const std::vector<size_t>::const_iterator &firstIdx,
	const std::vector<size_t>::const_iterator &lastIdx,
	Converter::OutputBuffer &outbuf,
	std::function<void(const Converter::InputBuffer::value_type &,
		Converter::OutputBuffer::value_type &)> func
	) 
{
	for (auto it = firstIdx; it != lastIdx; ++it) 
	{
		//TODO concurrency synchronisation
		//func(inbuf[*it], outbuf[*it]);
	}
}
