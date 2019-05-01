//Salissou Gomna Ilham

#define _OPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

int main (int argc, string argv[])
{

//Assure that the user have just one command-line argument
    if (argc != 2)
    {
        printf ("ERROR, you must give the hashed code. For example ./crack hash\n");
        return 1;
    }

//Define the hash and the salt
    string hash = argv[1];
    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0';
    memcpy (salt, argv[1], 2);

//Assure that the password have only alphabet characters
    char password[6] = "\0\0\0\0\0\0";
    char alpha[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\0";

//Find the correct password

    printf ("Please wait!\n");
    for (int a = 0; a < 53; a++)
    {
        for (int b = 0; b < 53; b++)
        {
            for (int c = 0; c < 53; c++)
            {
                for (int d = 0; d < 53; d++)
                {
                    for (int e = 1; e < 53; e++)
                    {
                        password[0] = alpha[e];
                        password[1] = alpha[d];
                        password[2] = alpha[c];
                        password[3] = alpha[b];
                        password[4] = alpha[a];

                        if (strcmp (crypt (password, salt), hash) == 0)
                        {
                            printf ("%s\n", password);
                            return 0;
                        }

                    }
                }
            }
        }
    }

    printf ("the password can not be decrypted\n");
}