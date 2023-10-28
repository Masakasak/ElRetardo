#include <cstdio>
int main(){
    char symbols[] = "1234567890AbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

    for (char c1 : symbols) {
        for (char c2 : symbols) {
            for (char c3 : symbols) {
                for (char c4 : symbols) {
                    for (char c5 : symbols) {
                        printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
                    }
                }
            }
        }
    }
    return 0;
}