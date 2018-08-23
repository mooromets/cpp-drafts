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


	template <class Ty_InContainer, class Ty_OutContainer>
	void encode(const Ty_InContainer &input, Ty_OutContainer &output) const
	{
		output.resize(input.size() / 2);
		auto write = lame_encode_buffer_interleaved(m_Lame, 
			const_cast<short*>(input.data()), input.size(), 
			const_cast<unsigned char*>(output.data()), output.size());
		output.resize(write);
		//TODO flush ???
		//write = lame_encode_flush(lame, mp3_buffer, MP3_SIZE);
		//write = lame_encode_buffer_interleaved(lame, pcm_buffer, read, mp3_buffer, MP3_SIZE);
	}


	~LameEncoder() 
	{
		lame_close(m_Lame);
	}

private:
	lame_t m_Lame;
	int m_Samplerate = 44100;
};