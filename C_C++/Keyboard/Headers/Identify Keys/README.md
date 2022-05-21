# Identify keys
Small header to classify keyboard keys and get their names.

## Content

### Note:
All the functions mentioned below accept an integer between 0 and 255 as a parameter and return a character string with the name of the key, but if the function fails, it will return NULL.

### Functions:

* **GetNumericKeyCharacter**: Checks if the key corresponds to number keys.
* **GetAlphabetKeyCharacter**: Checks if the key corresponds to the keys between A and Z.
* **GetAlphaNumericKeyCharacter**: Checks if the key corresponds to GetNumericKeyCharacter or GetAlphabetKeyCharacter.
* **GetNumericPadKeyString**: Check if the key corresponds to a key on the numeric keypad.
* **GetFunctionKeyString**: Check if the key corresponds to a function key.
* **GetOtherKeyString**: Check the remaining keys.
* **GetKeyString**: Checks all the above functions.

### Example:

```C
char *keyname = GetKeyString(115);
printf("%s\n", keyname);
// out: F4.

char *keyname2 = GetKeyString(255);
// keyname2 is NULL.

char *keyname3 = GetNumericKeyCharacter(65);
// 65 = A.
// keyname3 is NULL.
```
