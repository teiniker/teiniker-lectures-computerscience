# Debugging in VS Code

## Debugging C Programs 

We can debug a single file by switching into the debug view, click `Run and Debug` and select 
`C++(GDB/LLDB)`. This creates the following `launch.json` file:
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc - Build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\MinGW\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: gcc build active file",
        }
    ]
}
```
Now we can open our C file, set a **breakpoint** and run the debugger by clicking the 
**run button** on the left top corner of the IDE.

![Debug a single file](figures/DebugSingleFile.png)


*Egon Teiniker, 2020-2023, GPL v3.0* 