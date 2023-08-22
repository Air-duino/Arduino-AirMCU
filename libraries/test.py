import os

root = "/home/runner/work/Arduino-AirMCU/Arduino-AirMCU/libraries/"

for dir in os.listdir(root):
    if not os.path.isdir(dir):
        continue
    ex_path = root+dir+"/examples/"
    if not os.path.exists(ex_path):
        continue
    for ex in os.listdir(ex_path):
        ex_repo_path = ex_path+ex+"/"
        if not os.path.isdir(ex_repo_path):
            continue
        print("found example: "+ex_repo_path)
        #编译
        os.system("/home/runner/bin/arduino-cli compile -b AirM2M:AirMCU:AirM2M_Air001_Board "+ex_repo_path)

