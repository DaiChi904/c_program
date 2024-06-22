#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "RLFJHXDMKQVBWTIGZCEANYUSPOHLFJRXMKQBVITZECANYUSPOHLRFJXDKMQBWIGZECANYUSQOHLRFJXDKMQBVWITZECANYUSPOHLRFJXDKMQBVWITZECANYUSPOHLRFJXDKMQBWITZECANYUSPOHLRFJXDKMQBVWITZECANYUSPOHLRFJXDKMQBVWITZECANYUSPO";
    char numary[26] = {};
    for (char c = 'A'; c <= 'Z'; c++) {
        int cnt = 0;
        for (int i = 0; str[i] != '\n'; i++)
        if (str[i] == c) {
            cnt++;
        };
        numary[c - 'A'] = cnt;
    };

    int max_count = numary[0];
    char max_char = 'A';
    for (int i = 1; i < 26; i++) {
        if (numary[i] > max_count) {
            max_count = numary[i];
            max_char = 'A' + i;
        }
    }
    printf("char: %c\n", max_char);
    printf("count: %d\n", max_count);

    return 0;
}
