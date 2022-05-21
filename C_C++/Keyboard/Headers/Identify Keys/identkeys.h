#ifndef IDENTKEY_H
#define IDENTKEY_H

#include <stdio.h>
#include <stdlib.h>

#ifndef BYTE
#define BYTE unsigned char
#endif

char *_TO_POINT_CHAR(BYTE c){
    char *out = (char*)malloc(2);
    sprintf(out, "%c", c);
    return out;
}

char *GetNumericKeyCharacter(BYTE key){
    if (key >= '0' && key <= '9') return _TO_POINT_CHAR(key);
    return NULL;
}

char *GetAlphabetKeyCharacter(BYTE key){
    if (key >= 'A' && key <= 'Z') return _TO_POINT_CHAR(key);
    return NULL;
}

char *GetAlphaNumericKeyCharacter(BYTE key){
    if (key >= '0' && key <= '9') return _TO_POINT_CHAR(key);
    if (key >= 'A' && key <= 'Z') return _TO_POINT_CHAR(key);
    return NULL;
}

char *GetNumericPadKeyString(BYTE key){
    if (key == 108) return NULL;
    if (key >= 96 && key <= 111){
        char *out;
        out = (char*)malloc(9);
        if (key >= 106) sprintf(out, "Numpad %c", key-64);
        else sprintf(out, "Numpad %i", key-96);
        return out;
    }
    return NULL;
}

char *GetFunctionKeyString(BYTE key){
    if (key >= 112 && key <= 135){
        char *out;
        if (key-111 > 9) out = (char*)malloc(4);
        else out = (char*)malloc(3);
        sprintf(out, "F%i", key-111);
        return out;
    }
    return NULL;
}

char *GetOtherKeyString(BYTE key){

    if (key == 8) return (char*)"Backspace";
    if (key == 9) return (char*)"Tabulator";
    if (key == 12) return (char*)"Clear";
    if (key == 13) return (char*)"Enter";
    if (key == 19) return (char*)"Pause/Break";
    if (key == 20) return (char*)"Caps Lock";
    if (key == 27) return (char*)"Esc";
    if (key == 32) return (char*)"Space";
    if (key == 33) return (char*)"Page Up";
    if (key == 34) return (char*)"Page Down";
    if (key == 35) return (char*)"End";
    if (key == 36) return (char*)"Home";
    if (key == 37) return (char*)"Arrow Left";
    if (key == 38) return (char*)"Arrow Up";
    if (key == 39) return (char*)"Arrow Right";
    if (key == 40) return (char*)"Arrow Down";
    if (key == 44) return (char*)"Print Screen";
    if (key == 45) return (char*)"Insert";
    if (key == 46) return (char*)"Delete";
    if (key == 91) return (char*)"Left Win";
    if (key == 92) return (char*)"Right Win";
    if (key == 93) return (char*)"Menu";
    if (key == 108) return (char*)"Separator";
    if (key == 144) return (char*)"Num Lock";
    if (key == 145) return (char*)"Scroll Lock";
    if (key == 160) return (char*)"Left Shift";
    if (key == 161) return (char*)"Right Shift";
    if (key == 162) return (char*)"Left Ctrl";
    if (key == 163) return (char*)"Right Ctrl";
    if (key == 164) return (char*)"Left Alt";
    if (key == 165) return (char*)"Right Alt";
    if (key == 186) return (char*)";:";
    if (key == 187) return (char*)"=+";
    if (key == 188) return (char*)",";
    if (key == 189) return (char*)"–_";
    if (key == 190) return (char*)".";
    if (key == 191) return (char*)"/?";
    if (key == 192) return (char*)"`~";
    if (key == 219) return (char*)"[{";
    if (key == 220) return (char*)"\\|";
    if (key == 221) return (char*)"]}";
    if (key == 222) return (char*)"\'\"";

    return NULL;
}

char *GetKeyString(BYTE key){
    char *out;

    char *(*function[4])(BYTE) = {
        GetAlphaNumericKeyCharacter,
        GetNumericPadKeyString,
        GetFunctionKeyString,
        GetOtherKeyString
    };

    for (BYTE i=0;i<4;i++){
        out = function[i](key);
        if (out != NULL) return out;
    }

    return NULL;
}

#endif
