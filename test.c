#include <stdio.h>
int main(){char mem[256] = {0};int p = 0;mem[p]++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;while(mem[p] > 0){p++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;mem[p]++;
mem[p]++;mem[p]++;p--;mem[p]--;}p++;mem[p]--;mem[p]--;printf("%c", mem[p]);return 0;}