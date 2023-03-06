#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    FILE  *source, *target;
    int numr, numw;
    char buffer[101];

    source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("open read file error.\n");
        return 0;
    }

    target = fopen(argv[2], "wb");
    if (target == NULL) {
        fclose(source);
        printf("open target file error.\n");
        return 0;
    }

    while (feof(source) == 0) {
        memset(buffer, 0, sizeof(buffer));
        numr = fread(buffer, 1, 100, source);
        if (ferror(target) != 0) {
            printf("read file error.\n");
            break;
        }

        numw = fwrite(buffer, sizeof(char), numr, target);
        if (numw != numr) {
            printf("write file error.\n");
            break;
        }
    }

    fclose(source);
    fclose(target);

    return 0;
}