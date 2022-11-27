#ifndef BMPLOADER_H
#define BMPLOADER_H

#ifdef _WIN32
	#include <windows.h>
#endif
#include <GL/glut.h>
#include <stdio.h>

class BmpLoader {
private:FILE* file;
		void getImageSize();
public:	unsigned char* data;	// Contains Image pixel info.
		int iWidth, iHeight;	// Image's Dimentions
		BmpLoader(const char*);
		~BmpLoader();
};

BmpLoader::BmpLoader(const char* filename)
{
	iWidth = 0, iHeight = 0;
	file = fopen(filename, "rb");
	if (file == NULL) {
		printf("ERROR : BITMAP LOAD - File not found : File = %s\n", filename);
		exit(0);
	}

	/// Read Image height & width.
	getImageSize();

	/// Read Image content
	data = (unsigned char*)malloc(iWidth * iHeight * 3);

	fread(data, iWidth * iHeight * 3, 1, file);

	fclose(file);

	/// Swap the R <-> G
	for (int i = 0; i < iHeight * iWidth; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;
	}
}

void BmpLoader::getImageSize()
{
	// NOTE :Read the file first.
	unsigned char imagedata[54];	///Header is of size 54
	int bytevalue;
	int index = 0;

	do {	/// Read all file header.
		bytevalue = fgetc(file);
		imagedata[index] = bytevalue;
		index++;
		if (index == 54)
			break;
	} while (bytevalue != EOF);

	/// Read Height & Width
	iWidth = imagedata[20 - 1] * 256 + imagedata[19 - 1];
	iHeight = imagedata[24 - 1] * 256 + imagedata[23 - 1];
	int image_bits = imagedata[29 - 1];
}

BmpLoader::~BmpLoader()
{
	delete[] data;
}
#endif BMPLOADER_H
