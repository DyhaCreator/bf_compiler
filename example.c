#include <stdio.h>

int main(){
    char mem[256] = {0};
    int p = 0;
    //+
    mem[p]++;
    //-
    mem[p]--;
    //.
    printf("%c", mem[p]);
    //,
    scanf("%c", &mem[p]);
    //>
    p++;
    //<
    p--;
    //[
    while(mem[p] > 0){
    //]
    }
    return 0;
}