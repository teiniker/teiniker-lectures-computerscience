# Processes

Every running program is a **process** and has a unique number, the **PID**
(Process ID). Using this number, we can address a program directly, for example
to terminate one that has frozen.

## Listing Running Processes

```
$ ps                      # only the processes of the current session
$ ps aux                  # all processes on the system
$ ps aux | grep firefox   # search for a specific program
```

A line from `ps aux` looks like this:

```
USER   PID  %CPU %MEM    VSZ   RSS TTY  STAT START   TIME COMMAND
student 2417  0.3  1.2 725312 98420 ?   Sl   10:14   0:07 /usr/bin/firefox
```

Two columns are especially important: **PID** (the number) and **COMMAND**
(the program).

## Live View: `top` and `htop`

```
$ top       # continuously updated, quit with q
$ htop      # more comfortable variant, if needed: `sudo apt install htop`
```

`top` continuously shows which processes are currently consuming CPU time and
memory. This is useful when the VM becomes slow. By default the list is sorted
by CPU load. The view is closed with `q`.

## Terminating Processes: `kill`

```
# 2417 is the PID of the example above
$ kill 2417            # polite request to terminate
$ kill -9 2417         # forced termination (last resort only)
$ pkill firefox        # by name instead of PID
$ killall firefox      # terminates all processes with this name
```

The difference matters: `kill` without an option asks the program to terminate
itself, so it can still save data. `kill -9` immediately removes control from
the process and unsaved data is lost. Therefore: first `kill`, and only if
nothing happens, `kill -9`.

## Foreground and Background

A started command normally blocks the terminal until it has finished.
With an appended `&`, it runs in the background instead:

```
$ sleep 300 &          # runs in the background, the terminal stays free
[1] 3812               # [job number] and PID
$ jobs                 # which jobs are running in this session?
$ fg %1                # bring job 1 to the foreground
```

Two key combinations belong to this topic:

| Key | Effect |
|---|---|
| `[ctrl] + [c]` | Abort the running process |
| `[ctrl] + [z]` | Suspend the running process (continue with `bg` or `fg`) |

A more detailed description can be found in [Process Commands](../processes/README.md).

## Exercise 7

* List all running processes and page through the output.
* Start the command `sleep 300` in the background.
* Determine its PID.
* Terminate the process using its PID and check that it has disappeared.
* Start `top` and quit it again.

## References

* [MeetCyber: Linux Commands Part 3 - ps, top and kill: What's Actually Running on Your Machine](https://meetcyber.net/linux-commands-part-3-ps-top-and-kill-whats-actually-running-on-your-machine-9eb3a9f07a45)

*Nicoletta Kaehling, 2026, GPL v3.0*
