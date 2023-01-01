import sys
import shutil

if len (sys.argv) == 2:
    if sys.argv[1] == "clear":
        shutil.copy ("model.cpp", "temp.cpp")
else:
    type = sys.argv[1]
    id = sys.argv[2]

    if (type == "acwing"):
        shutil.copy ("temp.cpp", "ACWing/" + str(id) + ".cpp")
    else:
        shutil.copy ("temp.cpp", str(id) + ".cpp")

    shutil.copy ("model.cpp", "temp.cpp")
