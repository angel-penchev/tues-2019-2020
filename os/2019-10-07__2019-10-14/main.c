#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void *read_image( const char *filepath );
void bmp_info( const char *file );
void png_info( const char *file );

int main( int argc, const char* argv[] ) {
	if (access( argv[1], F_OK ) == -1) {
		fprintf(stderr, "Unable to open file\n");
		exit(1);
	}

	char *file = (char*)read_image(argv[1]);

	unsigned char png_header[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
	unsigned char bmp_header[] = {0x42, 0x4D};
	 
	if (!memcmp(file, bmp_header, 2)) {
		bmp_info(file);
	} else if(!memcmp(file, png_header, 8)) {
		png_info(file);
	} else {
		fprintf(stderr, "Unable to parse file\n");
		exit(2);
	}
}

void bmp_info( const char *file ) {
	uint32_t width, heigth;
	memcpy(&width,  file + 18, sizeof(uint32_t));
	memcpy(&heigth, file + 22, sizeof(uint32_t));

	printf("BMP image width: %d\n", width);
    printf("BMP image height: %d\n", heigth);
}

void png_info( const char *file ) {
	uint32_t width, heigth, size = 0;
	memcpy(&width,  file + 16, sizeof(uint32_t));
	memcpy(&heigth, file + 20, sizeof(uint32_t));

	width = ntohl(width);
	heigth = ntohl(heigth);

	unsigned char eof_header[] = "IEND";
	for (; memcmp(file + size, eof_header, 4); ++size);
	size += 8; // This is done to include the "IEND" and the following chunk

    printf("PNG image width: %d\n", width);
    printf("PNG image height: %d\n", heigth);
	printf("PNG file size: %d\n", size);
}