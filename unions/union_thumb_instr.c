#include <stdio.h>

struct thumb_instr_bit {
    unsigned int : 3;
    unsigned int op1 : 2;
    unsigned int op2 : 7;
    unsigned int reserved1 : 4;
    unsigned int op : 1;
    unsigned int reserved2 : 15;
};

union thumb_instr {
    unsigned int thumb_instr_int;
    struct thumb_instr_bit bit;
};

int main() {
    union thumb_instr instr;

    instr.bit.op1 = 0x3;
    instr.bit.op2 = 0xF;
    instr.bit.op = 0x1;

    printf("op1 = 0x%X\n", instr.bit.op1);
    printf("op2 = 0x%X\n", instr.bit.op2);
    printf("op = 0x%X\n", instr.bit.op);

    printf("thumb_instr_int = 0x%X\n", instr.thumb_instr_int);

    printf("op1 = 0x%X\n", instr.bit.op1);
    printf("op2 = 0x%X\n", instr.bit.op2);
    printf("op = 0x%X\n", instr.bit.op);

    return 0;
}
