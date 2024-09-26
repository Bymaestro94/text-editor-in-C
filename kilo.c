#include <termios.h>
#include <unistd.h>

void enableRawMode(){
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);

    raw.c_flag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(){
    enableRawMode()

    char c;
    while (read(STDIN_FILEND, &c, 1) == 1 && c != 'q');
    return 0;
}
