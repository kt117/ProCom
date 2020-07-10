import os


def create_file(path):
    
    s = ""
    with open("util/template.cpp") as f:
        s = f.read()

    for i in range(8):
        file_path = path + "/{}.cpp".format(str(chr(ord('a') + i)))
        if not os.path.isfile(file_path):
            with open(file_path, mode='w') as f:
                f.write(s)

path = "codeforces/educational/52"
create_file(path)