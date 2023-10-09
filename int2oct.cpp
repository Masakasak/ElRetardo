#include <iostream>
 
using namespace std;
 
int get_oct_size(int n) {
    int size = 0;
    while(n > 0) {
        size++;
        n = n / 8;
    }
    
    return size;
}
 
char* str2oct(int n) {
    //
    char sign = ' ';
    if(n < 0) {
        sign = '-';
        n = n * -1;
    }
    
    int size = get_oct_size(n) + 3;
    char* result = new char[size];
    int pointer = size - 1;
    
    if(n == 0) {
        result[3] = '0';
    }
    
    while (n > 0) {
        result[pointer] = '0' + (n % 8);
        pointer--;
        n = n / 8;
    }
    
    result[0] = sign;
    result[1] = '0';
    result[2] = 'o';
    
    return result;
}
  
int main()
{
    int number = 666;
    char* res = str2oct(number);
    
    cout << res << endl;
    
    delete[] res;
    
    return 0;

}
