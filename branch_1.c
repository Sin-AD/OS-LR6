#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
#include <stdio.h>

int main() {
    
    STARTUPINFO si_own;

    STARTUPINFO si_1;
    PROCESS_INFORMATION pi_1;
    DWORD CreationFlags = NORMAL_PRIORITY_CLASS;
    memset(&si_1, 0, sizeof(STARTUPINFO));
    si_1.cb = sizeof(si_1);
    si_1.lpTitle = "First";
    CreateProcess(NULL, "leaf1.exe", NULL, NULL, FALSE, CreationFlags, NULL, NULL, &si_1, &pi_1);
    GetStartupInfo(&si_own);
    
    for (int i = 1; i < 11; i++) {
        Sleep(1200);
        printf("%d. %s branch1\n", i, si_own.lpTitle);
    }
    return 0;
}