# File enumerator.
Script for file enumeration.

## Use
Just run the script and choose the option according to your needs. The options are:

* **R**: Renames the files by adding a numbering at the beginning of the file, plus a hyphen and a space separating the original file name. If there are enumbered and unnumbered files in the executed directory, the existing enumerations will be removed for the correct inclusion of the unnumbered files.
* **U**: Removes the enumeration given to the files as long as they have them.
* **N**: Ignores the renaming and un-renaming actions, and only creates the file **"enumfiles.txt"**. Any option that is not one of the above mentioned is also evaluated as **N**.

The options **R** and **N**, create a file called **"enumfiles.txt"** that contains the listed files regardless of whether they are renamed or not in the directory from which they were taken.

The script works exclusively with files; the resident directories are ignored, as well as the file containing the script and the file **"enumfiles.txt"**.

## Example
Because some programs or other means do not organize the files correctly when they are listed, the digits less than the maximum digits are filled with leading zeros. Example:

If there are forty files, the enumerations from 1 to 9, will be filled with a zero, type: 01, 02, 03, 03, 04, etc. More examples:

* **100 files:**
```
001- File 1.ext
002- File 2.ext
...
050- File 50.ext
...
100- File 100.ext
```

* **1000 files:**
```
0001- File 1.ext
0002- File 2.ext
...
0050- File 50.ext
...
0145- File 145.ext
...
1000- File 1000.ext
```