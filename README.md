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

The Application is available as an **AppImage**. In order to run it simply get the latest app image from here and make it executable and run it. Create a Desktop file for Desktop Integration with content as follows.

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





