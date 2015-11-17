/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, and resizes BMP. 
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    // remember multiplier
    int n_num = atoi(argv[1]);
    
    
    //check n size
    if (n_num < 0 || n_num >= 100)
    {
        printf("Please provide an 0 < int <= 100");
        return 2;
    }
    
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    //track old padding
    int old_padding =  (4 - ((bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("%d\n", old_padding);
    
    //calculate new padding
    int new_padding =  (4 - ((n_num * bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //track old size, width, height
    //int old_size = bf.bfSize; 
    int old_width = bi.biWidth;
   // int old_height = abs(bi.biHeight);
    
    //track new size, width, height
    bi.biWidth = bi.biWidth * n_num;
    bi.biHeight = bi.biHeight * n_num;
    bf.bfSize = (abs(bi.biHeight) * bi.biWidth * sizeof(RGBTRIPLE)) + 54 + new_padding;
    bi.biSizeImage = (abs(bi.biHeight) * bi.biWidth * sizeof(RGBTRIPLE));
    

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    

    // write outfile's width
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


            // iterate over pixels in scanline
            for (int j = 0; j < old_width; j++)
            {
                    // temporary storage
                    RGBTRIPLE triple_array[bi.biWidth][bi.biHeight];

                    for (int i = 0; i < n_num; i++)
                    {
                    // read RGB triple from infile
                    fread(triple_array, sizeof(RGBTRIPLE), 1, inptr);
                    printf("%d\n", triple_array[i][j]);
                    }
                    

                    /*
                        //write RGB into outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);



                    
                    //if reach end of pixels
                    if(j == old_width - 1)
                    {
                        n++;
                        // then add it back (to demonstrate how)
                        for (int k = 0; k < new_padding; k++)
                        {
                            fputc(0x00, outptr);
                        }
                        // skip over padding, if any
                        printf("%d\n", j);
                   
                        //end of row
                        if (n < n_num)
                        {
                            j = -1;
                            //printf("%d\n", old_width * old_padding);
                            fseek(inptr, -sizeof(RGBTRIPLE) * old_width, SEEK_CUR);
                        } else {
                            fseek(inptr, old_padding, SEEK_CUR);
                        }
                        
                    }
                    */
                    
            }
    

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
