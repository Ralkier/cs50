/****************************************************************************
* recover.c                                                                 *
*                                                                           *
* Jason Yoder (Ralkier)                                                     *
* Computer Science 50                                                       *
* Problem Set 4                                                             *
*                                                                           *
* Recovers JPEGs from a forensic image.                                     *
***************************************************************************/
/*
    Load the .raw image as read only. (fopen)
        Make sure the file exists and is readable.
        Check for the size of the image.
    Scan the .raw for jpg images (Maybe other items?? Like
      http://www.youtube.com/watch?v=oHg5SJYRHA0&feature=youtu.be).
    Save files found to disk in incremental order starting at 000.
    Close the file.
    Not going to use cs50.h for this.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCKS 512
typedef uint8_t BYTE;
static const uint8_t jpeg_hdr1[] =
{
    0xff, 0xd8,     //Start of Image
    0xff, 0xe0      //Application-specific: For example, an Exif JPEG file uses an APP1 marker to store metadata, laid out in a structure based closely on TIFF.
};
static const uint8_t jpeg_hdr2[] =
{
    0xff, 0xd8,     //SOI
    0xff, 0xe1      //APP1
};

int main(void)
{
    /*Set filename and give it a value,
     who knows what is sitting there waiting to be annoying.*/
    char* filename = {"card.raw"};
    /*Open the file for binary reading.*/
    FILE* c_raw = fopen(filename, "rb");
    /*Lets exit since the file couldn't be read.*/
    if (c_raw == NULL)
    {
        printf("Could not open %s\n", filename);
        return 1;
    }
    /*Yay! The file can be opened! Now lets find some stuff!*/

    /*Define some vars, buf[BLOCKS] to hold the fread buffer*/
    uint8_t buf[BLOCKS];
    /*File pointer to write the jpeg files, initialize it just in case...*/
    FILE* jpeg = NULL;
    /*File name 000.jpg*/
    char jpeg_file[8] = { '\0' };
    /*Keep track of the image #*/
    int img_count = -1;

    /*While we are not at the end of the file (c_raw)...*/
    while (!feof(c_raw))
        //while (fread(&buf, BLOCKS*sizeof(BYTE), 512,c_raw)>0)
    {
        /*Read the file, place in the buf*/
        fread(buf, sizeof(BYTE), BLOCKS, c_raw);
        /*See if the header matches*/
        if (memcmp(buf, jpeg_hdr1, 4) == 0 || memcmp(buf, jpeg_hdr2, 4) == 0)
        {
            /*If the last jpeg file is open lets close it.*/
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }
            /*Start writing the jpeg file, write the file using the counter for the filename)*/
            sprintf(jpeg_file, "%03d.jpg", ++img_count);
            jpeg = fopen(jpeg_file, "wb");
            fwrite(buf, sizeof(BYTE)*BLOCKS, 1, jpeg);
        }
        else
        {

            /*Stop writing jpeg if we are at the end of the file.
                 Had to add this, it was writing extra bytes at the end
                 of 050.jpg
                 Thanks cs50 discuss!*/

            if (feof(c_raw))
            {
                if (jpeg != NULL)
                {
                    fclose(jpeg);
                }
                fclose(c_raw);
                return 0;
            }
            /*If jpeg is still open and the headers do not match, continue writing to jpeg*/
            if (jpeg != NULL)
            {
                fwrite(buf, sizeof(BYTE)*BLOCKS, 1, jpeg);
            }
        }

    }

    if (jpeg != NULL)
    {
        fclose(jpeg);
    }
    /*Close c_raw and return 0!*/
    fclose(c_raw);
    return 0;
}
