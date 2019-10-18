#pragma once

#include "jnucbitmap.h"

namespace jnuc {
	class Font
	{
	public:
		Font(const void *descriptor, const GreyscaleBitmap &bitmap);
		inline const GreyscaleBitmap& Bitmap() const {return m_Bitmap;}
		ShortRect GetCharacterRect(unsigned int charcode)  const;
		unsigned int GetCharacterWidth(unsigned int charcode)  const;
		inline unsigned int GetFontHeight()  const
		{
			const unsigned char &fontheight=m_FontDescriptor[5];
			return fontheight;
		}

	private:
		inline unsigned int GetCharacterDescriptor(unsigned int charcode)  const;

	private:
		const GreyscaleBitmap m_Bitmap;
		const unsigned char *m_FontDescriptor;
	};

} // namespace

