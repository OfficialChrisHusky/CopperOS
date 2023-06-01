void dummy_test_entrypoint() {}

void main() {

    char* videoMemory = (char*) 0xb8000;
    *videoMemory = 'H'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = ','; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'W'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'd'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'f'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = 'm'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 't'; videoMemory += 2;
    *videoMemory = 'h'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'k'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'n'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = '!'; videoMemory += 2;

}