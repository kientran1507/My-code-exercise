#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *str1, char *str2) {
    int len1, len2; 
    char *result;
    len1 = strlen(str1);
    len2 = strlen(str2);
    result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL){
        printf("Allocation failed! Check memory\n");
        return NULL;
    }
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}

int main(int argc, char *argv[]) {
    char *str1, *str2;
    char *cat_str;
    if (argc != 3) {
        printf("Please enter <string 1> <string 2>\n");
        return 1;
    }
    str1 = argv[1];
    str2 = argv[2];
    cat_str = my_strcat(str1, str2);
    if (cat_str == NULL) {
        printf("Problem allocating memory!\n");
        return 1;
    }
    printf("The concatenation of %s and %s is %s\n", str1, str2, cat_str);
    free(cat_str);
    return 0;
}
