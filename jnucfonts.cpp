#include "jnucfonts.h"

#pragma GCC optimize("O0")

namespace jnuc {
	Font::Font(const void *descriptor, const GreyscaleBitmap &bitmap)
	  : m_Bitmap(bitmap), m_FontDescriptor((const unsigned char*)descriptor)
	{

	}

	inline unsigned int Font::GetCharacterDescriptor(unsigned int charcode) const
	{
		const unsigned char &lowestchar=m_FontDescriptor[0];
		const unsigned char &numchars=m_FontDescriptor[1];
		const unsigned char &bytesperchar=m_FontDescriptor[2];
		unsigned int chardescriptor=0;
		if(charcode >= lowestchar)
		{
			charcode -= lowestchar;
			if(charcode < numchars)
			{
				unsigned int offset=charcode*bytesperchar+6;
				for(int i=0; i < bytesperchar; i++)
				{
					chardescriptor |= (((int)m_FontDescriptor[offset + i]) << 8*i);
				}
			}
		}
		return chardescriptor;
	}

	ShortRect Font::GetCharacterRect(unsigned int charcode) const
	{
		unsigned int chardescriptor=GetCharacterDescriptor(charcode);
		if(chardescriptor == 0)
		{
			return ShortRect();
		}
		else
		{
			const unsigned char &widthbits=m_FontDescriptor[3];
			const unsigned char &xcoordbits=m_FontDescriptor[4];
			const unsigned char &fontheight=m_FontDescriptor[5];
			unsigned int widthmask=(1 << widthbits)-1;
			unsigned int charwidth=chardescriptor & widthmask;
			unsigned int xmask=(1 << xcoordbits)-1;
			unsigned int charx=(chardescriptor >> widthbits) & xmask;
			unsigned int chary=(chardescriptor >> (widthbits+xcoordbits));
			chary *= fontheight;
			return ShortRect((short)charx, (short)chary, (short)(charx+charwidth),(short)(chary+fontheight));
		}
	}

	unsigned int Font::GetCharacterWidth(unsigned int charcode) const
	{
		unsigned int chardescriptor=GetCharacterDescriptor(charcode);
		if(chardescriptor == 0)
		{
			return 0;
		}
		else
		{
			const unsigned char &widthbits=m_FontDescriptor[3];
			unsigned int widthmask=(1 << widthbits)-1;
			unsigned int charwidth=chardescriptor & widthmask;
			return charwidth;
		}
	}
} // namespace
