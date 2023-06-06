# Virtual Laboratory Setup

A virtual machine is used to provide a uniform environment for the examples in this repository. 
This is a **Debian Linux** image that can be hosted via **VirtualBox**.

## Install Virtual Box

Go to the VirtualBox homepage and download the lates version of the virtualization software.

`https://www.virtualbox.org/`

Make sure you have enabled the virtualization extensions in your computer's BIOS.

After running the installer, you start VirtualBox and go to the `File / Setup / General` menu.
Here you should specify the path to your VM images. Make sure this path does **not include spaces**.

In the `File / Import Appliance` dialog you can select the downloaded `*.ova` file which contains the
Linux image.


## Install the Linux Image

You can find the current (Debian 11.5) and older Linux images in the following folder for 
free [download](https://drive.google.com/drive/folders/1AzsF4Mvh1HJ8k6OW5W5hQ5CF0HdqA51l):

We use a Linux system together with free and open source tools.

**Before you start the VM** image, make sure that you have done the following settings:
* **System**: You can increase the memory size if you want (and your PC is supporting it).
* **Network**: Adapter 1 NAT
* **USB**: 1.1 Controller 
* **Shared Folder**: Make sure that the directory `C:\shared` exists or change the path to an existing folder.


**After starting the VM**, we can use the following accounts have been pre-configured:

* **Regular user** (should be used by default): 
    * username: `student` 
    * password: `student`

* **Super user**: 
    * username: `root`
    * password: `root66`

You are free to change the passwords and create new user accounts.

## References
* [Virtual Lab](https://drive.google.com/drive/folders/1AzsF4Mvh1HJ8k6OW5W5hQ5CF0HdqA51l)
* [Oracle VirtualBox](https://www.virtualbox.org/)


*Egon Teiniker, 2020-2023, GPL v3.0*
