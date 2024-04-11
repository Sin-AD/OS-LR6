#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
#include <stdio.h>

int main() {

    STARTUPINFO si_own;

    STARTUPINFO si_2;
    PROCESS_INFORMATION pi_2;
    DWORD CreationFlags = NORMAL_PRIORITY_CLASS;
    memset(&si_2, 0, sizeof(STARTUPINFO));
    si_2.cb = sizeof(si_2);
    si_2.lpTitle = "Second";
    CreateProcess(NULL, "leaf2.exe", NULL, NULL, FALSE, CreationFlags, NULL, NULL, &si_2, &pi_2); 
    GetStartupInfo(&si_own);

    for (int i = 1; i < 11; i++) {
        Sleep(1300);
        printf("%d. %s branch2\n", i, si_own.lpTitle);
    }
    return 0;
}