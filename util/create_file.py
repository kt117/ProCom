import os
import sys


def create_file(path):
    
    s = ""
    with open("util/template.cpp") as f:
        s = f.read()

    os.makedirs(path)

    for i in range(8):
        file_path = path + "/{}.cpp".format(str(chr(ord('a') + i)))
        if not os.path.isfile(file_path):
            with open(file_path, mode='w') as f:
                f.write(s)


args = sys.argv
create_file(args[1])