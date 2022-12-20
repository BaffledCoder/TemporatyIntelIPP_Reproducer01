import os
import sys

#default values for the variables
version     = "2017"
arch        = "64"
mode        = "Release"

def PrintHelp():
    print "------------------------------------------------------------"
    print "Build.py [-m| --mode Build Mode]"
    print " "
    print "-m allowed values are DEBUG and RELEASE"
    print "------------------------------------------------------------"

#parsing command arguments
for i in range(len(sys.argv)):
    argument = sys.argv[i]
    if argument == "help" or argument == "Help":
        PrintHelp()
        sys.exit()
    elif argument == "-m" or argument == "--mode":
        if(i+1 < len(sys.argv)):
            mode = sys.argv[i+1]

#printing values
print ""
print "Creating Build with following values ..."
if(os.name == "nt"):
    print "Visual Studio Version : " + version
print "Architecture Type     : " + arch
print "mode                  : " + mode

#creating build directory
print ""
print "Creating Directory ..."
Dir_Name = "IPP_" + mode + "_x64"
	

print Dir_Name
os.system("mkdir " + Dir_Name)

print ""
print "Generating project files ..."
os.chdir(Dir_Name)

CMake_cmd = "-G \"Visual Studio 15 2017 Win64\""

if mode == "Debug" or mode == "DEBUG":
    CMake_cmd += " -DCMAKE_BUILD_TYPE=Debug"
else:
    CMake_cmd += " -DCMAKE_BUILD_TYPE=Release"

print "CMake_cmd :"
print CMake_cmd
os.system("cmake .. " + CMake_cmd)