#pragma once

#include "lame.h"

class LameEncoder 
{
public:
	LameEncoder() 
	{
		m_Lame = lame_init();
		lame_set_in_samplerate(m_Lame, m_Samplerate);
		lame_set_VBR(m_Lame, vbr_default);
		lame_init_params(m_Lame);
	}


	void encode(const AudioBuf &input, AudioBuf &output) const
	{
		output.resize(input.size() / m_Channels / m_PcmSize);
		auto write = lame_encode_buffer_interleaved(m_Lame, 
			reinterpret_cast<short*>(const_cast<char*>(input.data())), input.size() / m_PcmSize, 
			reinterpret_cast<unsigned char*>(output.data()), output.size());
		output.resize(write);
	}


	void flush(AudioBuf &output, size_t size = 8 * 1024) const
	{
		output.resize(size);
		auto write = lame_encode_flush(m_Lame, reinterpret_cast<unsigned char*>(output.data()), output.size());
		output.resize(write);
	}


	~LameEncoder() 
	{
		lame_close(m_Lame);
	}

private:
	lame_t m_Lame;
	int m_Samplerate = 44100;
	const int m_Channels = 2;
	const int m_PcmSize = sizeof(short);
};