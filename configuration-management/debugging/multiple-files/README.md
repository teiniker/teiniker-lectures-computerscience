# Debugging in VS Code

## Debugging Executables Built with Make

To debug an executable which we have built using `make`, we have to change the `launch.json` file: 
* **Remove the "preLaunchTask" element** to stop automatic compiling before the debugging:

  Remove the following line:
  ```
    "preLaunchTask": "C/C++: gcc build active file",
  ```  

* **Change the "program" element** to point to the executable created by make within the `build` folder:

  Change from:  
  ```
    "program": "${fileDirname}/${fileBasenameNoExtension}", 
  ```  
  to:	 
  ```
    "program": "${fileDirname}/build/${fileBasenameNoExtension}",    
  ```    

Note that we have to open the `main.c` file before we start the debugger because the `${fileBasenameNoExtension}`
variable contains the current opened file's basename.

Here the final `launch.json` file:
```json
{
  "version": "0.2.0",
  "configurations": [
  {
      "name": "Debug build/main (gdb)",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/build/${fileBasenameNoExtension}", //!!!
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "/usr/bin/gdb",
      "setupCommands": [
        { "text": "-enable-pretty-printing" }
      ]
    }
  ]
}
```

*Egon Teiniker, 2020-2026, GPL v3.0* 