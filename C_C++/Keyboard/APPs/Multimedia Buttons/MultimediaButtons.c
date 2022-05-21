#include <fcntl.h>
#include <stdio.h>
#include <wchar.h>
#include <windows.h>

void SendKey(BYTE key){
    INPUT temp;
    ZeroMemory(&temp, sizeof(INPUT));

    temp.type = INPUT_KEYBOARD;
    temp.ki.wVk = key;
    temp.ki.time = 1;

    temp.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    SendInput(1, &temp, sizeof(INPUT));

    temp.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &temp, sizeof(INPUT));
}

int main(){
    _setmode(_fileno(stdout), _O_U8TEXT);

    wprintf(L"\t\tInitiated\n");
    wprintf(L"Increase the volume: Ctrl + Alt + ↑\n");
    wprintf(L"Dicrease the volume: Ctrl + Alt + ↓\n");
    wprintf(L"Mute sound: Ctrl + Alt + M\n");
    wprintf(L"Next media: Ctrl + Alt + →\n");
    wprintf(L"Previous media: Ctrl + Alt + ←\n");
    wprintf(L"Pause and resume playback: Ctrl + Alt + P\n");

    while (1){
        Sleep(100);

        if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_MENU) & 0x8000){
            if (GetAsyncKeyState(VK_UP) & 0x8000) SendKey(VK_VOLUME_UP);
            else if (GetAsyncKeyState(VK_DOWN) & 0x8000) SendKey(VK_VOLUME_DOWN);
            else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) SendKey(VK_MEDIA_NEXT_TRACK);
            else if (GetAsyncKeyState(VK_LEFT) & 0x8000) SendKey(VK_MEDIA_PREV_TRACK);
            else if (GetAsyncKeyState('M') & 0x8000) SendKey(VK_VOLUME_MUTE);
            else if (GetAsyncKeyState('P') & 0x8000) SendKey(VK_MEDIA_PLAY_PAUSE);
        }
        else if (GetAsyncKeyState(VK_LCONTROL) & 0x8000 && GetAsyncKeyState(VK_RCONTROL) & 0x8000){
            break;
        }
    }

    wprintf(L"\t\tFinished\n");
}
