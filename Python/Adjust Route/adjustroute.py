from os.path import abspath, sep, splitdrive, splitext

def AdjustRoute(route: str, length: int=240, n_elements: int=2) -> str:
    """route: A string of the route to reduce.
    length: Maximum length that the route must have.
    n_elements: Number of elements (file and folders) that can be shortened.
    """

    route = abspath(route)
    if len(route) <= length: return route

    drive, rest = splitdrive(route)
    rest = rest.split(sep)

    if rest[0] == "": rest = rest[1:]
    left = len(route) - length

    for element, count in zip(reversed(rest), range(1, (len(rest)+1))):
        element = list(splitext(element))
        element_length = len(element[0])

        if  n_elements == None or n_elements > 0:
            if len(element[0]) > left:
                element[0] = element[0][:len(element[0])-left]
                left = 0

            elif len(element[0]) < left:
                element[0] = element[0][:1]
                left = left - (element_length-1)
                
            else:
                element[0] = element[0][:len(element[0])-left+1]
                left = left - (element_length-1)

            rest[-count] = "".join(element)

        if n_elements != None:
            n_elements -= 1
            if n_elements==0 or left==0: break

    route = sep.join(rest)

    if drive == "": return sep + route
    else: return sep.join((drive, route))

if __name__ == "__main__":
    root = "/root/folder1/folder2/folder3/file.ext"
    new_root = AdjustRoute(root, 35, None)
    print(f"Original root: {root}")
    print("Max length: 35")
    print(f"New root: {new_root}")
    print(f"Length: {len(root)} -> {len(new_root)}")
