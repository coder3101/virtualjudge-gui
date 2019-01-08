# Virtual Judge GUI

This is a GUI implementation of the `testcaser/virtualjudge` command line interface. It depends on `testcaser/integrator`  and is a shared executable that can be installed or run on any platform.



## Demo

![](https://i.imgur.com/uYC9vZ3.png)
![](https://i.imgur.com/po7cile.png)

**Input Page for the GUI for Linux and Windows**

![](https://i.imgur.com/2SWIIQF.png)
![](https://i.imgur.com/XDBsJHE.png)

**Result Page for the GUI for Linux and Windows**

## Installation

### Linux 

The release version of VirtualJudge depends upon the following Qt Dynamic Libraries

- libQt5Widgets.so.5
- libQt5Gui.so.5
- libQt5Core.so.5
- libicui18n.so.56
- libicuuc.so.56
- libicudata.so.56


We Provide all the Qt shared libraries along with the executable in the `libs/` directory. In order for dynamic linker to correctly link all the shared libraries you need to tell the linker where to look for the libs. By default the dynamic linker does not looks in the current working directory.

Here are two possible ways to install, While one requires super user privileges other does not, use the one that is best suited for you.

-  You can install the Qt libraries in one of the system library paths (e.g. `/usr/lib` on most systems). You can simpley copy-paste the libs to this directory. (Needs to be super-user)
- You can write a startup script for your application, where you modify the dynamic linker configuration (e.g., adding your Qt lib's directory to the `LD_LIBRARY_PATH` environment variable)

Once libraries are set up and ready you can simply run this `VirtualJudge` executable.

We have provided all major Qt shared libraries in the `libs/`

**Alternatively you can double click on `run.sh` and it should start the GUI**.

### Windows

In order to install VirtualJudge GUI to windows you need to run the setup named `virtualjudge-setup.exe`. You can download the setup and run it, It will install all the required dlls in its place. For Uninstalling you can run the `uninstall.exe` which you can find in your installation directory (mostly `C:\Program Files (x86)\VirtualJudge\uninstall.exe`).

For Curious readers, This Executable and following special shared library dependency
- `QtCore5.dll`
- `Qt5Gui.dll`
- `Qt5Widgets.dll`

I have added all those in the directory `win_dll/`

**It does not have any ICON, We wish to add one very soon**


### MacOSX

**No Support Intended**



---

This is not a part of testcaser and is just a tool that uses testcaser in its core.

The command line interface of the `virtualjudge` is the primary and will get more support than this GUI interface.  We also do not want to provide any Virtual Judge GUI for the MACOS natively, however if you wish you can experiment with Linux executable and mentioned shared libraries.





