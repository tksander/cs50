/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    //declare jpg counter
    int counter = 0;

    // declare jpg title buffer 
    char title_buf [8];

    // var tracks whether jpg file is open - jpg file begins closed
    int file_open = 0;

    // declare a buffer for jpg data
    BYTE jpg_buf[512];


    // open memory card file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
    	// prompt user for retry
    	printf("File is not supported\n");
    	return 1;
   	}

    // create first jpg file name - 000
    sprintf(title_buf,"%03d.jpg", counter);

    // jpg counter increment to 001
     counter++;

    // open first jpg file
    FILE* outptr = fopen(title_buf, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", title_buf);
        return 2;
    }


    // repeat until end of card
    while(fread(&jpg_buf, sizeof(BYTE), 512, inptr) == 512)
    {	

		// if found jpg file
    	if(file_open == 0 && jpg_buf[0] == 0xff && jpg_buf[1] == 0xd8 && jpg_buf[2] == 0xff && (jpg_buf[3] == 0xe0 || jpg_buf[3] == 0xe1))
        {

            // mark file as open
            file_open = 1;

            //write first 512 bytes into file
            fwrite(&jpg_buf, sizeof(BYTE), 512, outptr);
        }

            // if new, subsequent jpg
            else if(file_open == 1 && jpg_buf[0] == 0xff && jpg_buf[1] == 0xd8 && jpg_buf[2] == 0xff && (jpg_buf[3] == 0xe0 || jpg_buf[3] == 0xe1))
            {
                // close old jpg
                fclose(outptr);

                //open new jpg file
                sprintf(title_buf, "%03d.jpg", counter);
                counter++;
                outptr = fopen(title_buf, "w");
                if (outptr == NULL)
                    {
                    fclose(inptr);
                    fprintf(stderr, "Could not create %s.\n", title_buf);
                    return 2;
                    }

                //write first 512 bytes into file
                fwrite(&jpg_buf, sizeof(BYTE), 512, outptr);
            }
        

        // if not new jpg
        else if(file_open == 1 && !(jpg_buf[0] == 0xff && jpg_buf[1] == 0xd8 && jpg_buf[2] == 0xff && (jpg_buf[3] == 0xe0 || jpg_buf[3] == 0xe1)))
        {   
                //write into file
                fwrite(&jpg_buf, sizeof(BYTE), 512, outptr);
            
        }
        
         
    }

        //close any remaining files
        fclose(inptr);
        fclose(outptr);

    return 0;
}
