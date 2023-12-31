#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
    FILE* readFile = NULL;
    FILE* writeFile = NULL;
    unsigned char textA[4096] = { 0 };
    unsigned char textEncry[4096] = { 0 };
    int textALen = 0;
    int textEncryLen = 0;
    readFile = fopen("E:\\aliyun_download\\我的视频--encry.mp4", "rb");         // windows系统上的格式
    //readFile = fopen("/home/hi/my-document/azx/text-encry.pdf", "rb");     // linux系统上的格式
    if (readFile == NULL)
    {
        printf("read error\n");
        fclose(readFile);
        return -1;
    }

    writeFile = fopen("E:\\aliyun_download\\我的视频--encry_done.mp4", "wb");    // windows系统上的格式
    //writeFile = fopen("/home/hi/my-document/azx/text-decry.pdf", "wb");       //linux系统上的格式
    if (writeFile == NULL)
    {
        printf("write error\n");
        fclose(writeFile);
        return -1;
    }
    printf("Begin encryption/decryption, please wait a moment\n");
    while (!feof(readFile))
    {
        textALen = fread(textA, 1, 4096, readFile);
        if (feof(readFile))
        {
            break;
        }
        if (textALen != 0)
        {
            for (int m = 0; m < 4096; m++)
            {
                textEncry[m] = textA[m] ^ 0xFE;
            }
        }
        textEncryLen = fwrite(textEncry, 1, 4096, writeFile);
        if (textALen == textEncryLen)
        {
            //printf("--- file encryption/decryption success\n");

            ;
        }
        else
        {
            printf("--- read length(%d) is not equal to write length(%d)\n", textALen, textEncryLen);
            printf("Check there is have available memory\n");
            return -1;
        }

    }
    if (textALen != 0)
    {
        for (int m = 0; m < textALen; m++)
        {
            textEncry[m] = textA[m] ^ 0xFE;
        }
    }
    textEncryLen = fwrite(textEncry, 1, textALen, writeFile);
    if (textALen == textEncryLen)
    {
        printf("*** file encryption/decryption success\n");
        printf("********* Congratulations, the operation has been completed correctly.\n");
    }
    else
    {
        printf("*** read length(%d) is not equal to write length(%d)\n", textALen, textEncryLen);
        printf("Check there is have available memory\n");
        return -1;
    }

    fclose(readFile);
    fclose(writeFile);

}