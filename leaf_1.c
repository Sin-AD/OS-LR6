#include <Windows.h>
#include <string.h>
#include <stdio.h>

int main() {

    STARTUPINFO si_own;
    GetStartupInfo(&si_own);

    for (int i = 1; i < 11; i++) {
        Sleep(1400);
        printf("%d. %s leaf1\n", i, si_own.lpTitle);
    }

    return 0;
}