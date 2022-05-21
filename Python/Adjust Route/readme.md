# Adjust route
Small code to shorten routes.

## Function

### AdjustRoute(route: str, length: int, n_elements: int) (function) (return str)
Arguments:
* route: A string of the route to reduce.
* length: Maximum length that the route must have. The default value is 240.
* n_elements: Number of elements (file and folders) that can be shortened. The default value is 2.

## Example

``` Python
root = "C:\\folder0\\folder1\\folder2\\folder3\\file.ext"
new_root = AdjustRoute(root, 35, None)

print(f"Original root: {root}")
print("Max length: 35")
print(f"New root: {new_root}")
print(f"Length: {len(root)} -> {len(new_root)}")

"""Output:
Original root: C:\folder0\folder1\folder2\folder3\file.ext
Max length: 35
New root: C:\folder0\folder1\folder2\fo\f.ext
Length: 43 -> 35
"""
```
