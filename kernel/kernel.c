/* This will force us to create a kernel entry function instead of jumping to kernel.c:0x00 */
void dummy_test_entrypoint() {
}

char* vmem = (char*)0xb8000;
const char color = 0x0f;

void print(char* instr);
void backspace();

void main() {
    char* banana = "I love bananas\0";
    print(banana);
}

void print(char* instr) {
    char* str = instr;
    while (*str != 0x0) {
        *vmem = *str;
        vmem++;
        *vmem = color;
        vmem++;
    }
}

void backspace() {
    vmem--;
    vmem = 0x0;
}