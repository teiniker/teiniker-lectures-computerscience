# Archiving and Compressing Files

* **zip**\
    A compression and file packaging utility. 
    Using `-r` we can travel the directory structure recursively.
    The **unzip** command ist used to uncompress a `*.zip` file. Including `-d` dir
    specifies a directory  to which to extract files.  By default, all files and subdirectories are recreated in the current directory.

    _Example_: compress a folder: `zip -r filename.zip folder`   

    _Example_: uncompress a file: `unzip filename.zip`   

* **gzip**\
    GNU Zip is one of the current standard Linux compression programs.
    A file that end with `.gz` is a GNU Zip archive.
    Use **gunzip** to uncompress a `*.gz` file. 

    _Example_: compress a file: `gzip filename`   

    _Example_: uncompress a file: `gunzip filename.gz`   

    The gzip command in Linux can only be used to compress a single file. In order to compress a folder, tar + gzip (which is basically tar `-z`) is used​.

* **tar**\
    Is used to create an archive (and also to gzip that archive).
    Archives created by tar usually have a `.tar` suffix.
    The `c flag` activates create mode. The `v flag` activates verbose diagnostic output.
    The `f flag` denotes the file option.

    _Example_: compress a folder: `tar cvzf filename.tar folder`   

    _Example_: uncompress a folder: `tar xvzf filename.tar.gz`   

    To **unpack** a `.tar` file, use tar with the `x flag` which puts tar into extract (unpack) mode.

    Before unpacking, it is a good idea to **check the contents** of a `.tar` file with the 
    table of contents mode by using the `t flag` instead of the `x flag`.

## References

* Brian Ward. **How Linux Works**. No Starch Press, 2015
    * Chapter 2: Basic Commands and Directory Hierarchy
    

*Egon Teiniker, 2020-2022, GPL v3.0*    