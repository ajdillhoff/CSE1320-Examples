#include <stdio.h>

struct thumb_instr {
    unsigned int           : 3;
    unsigned int op1       : 2;
    unsigned int op2       : 7;
    unsigned int reserved1 : 4;
    unsigned int op        : 1;
    unsigned int reserved2 : 15;
};

int main() {
    struct thumb_instr instr;

    printf("sizeof(instr) = %ld bits\n", sizeof(instr) * 8);

    instr.op1 = 0x1;
    instr.op2 = 0x7;
    instr.op = 0x1;
    printf("op1: 0x%X\n", instr.op1);
    printf("op2: 0x%X\n", instr.op2);
    printf("op: 0x%X\n", instr.op);

    return 0;
}
