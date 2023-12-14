/* This will force us to create a kernel entry function instead of jumping to kernel.c:0x00 */
void dummy_test_entrypoint() {
}


// Command: & "C:\Program Files\qemu\qemu-system-x86_64.exe" -drive file=\\wsl$\Ubuntu\home\jonah\dev\os1\os.bin,format=raw -m 2G






char* vmem = (char*)0xb8000;
const char color = 0x0f;

void print(char* instr);
void backspace();
void newline();




void main() {
    return;
    char* banana = "I love bananas\n\r\0";
    char* monkey = "I love monkeys\0";
    print(banana);
    print(monkey);
}














void print(char* instr) {
    char* str = instr;
    while (*str != 0x0) {
        *vmem = *str;
        vmem++;
        *vmem = color;
        vmem++;
        str++;
    }
}

void newline() {
    *vmem = 0x0a;
    vmem++;
    *vmem = color;
    vmem++;
    
    *vmem = 0x0d;
    vmem++;
    *vmem = color;
    vmem++;
}

void backspace() {
    vmem--;
    vmem = 0x0;
}