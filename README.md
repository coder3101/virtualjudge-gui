# Virtual Judge GUI

This is a GUI implementation of the `testcaser/virtualjudge` command line interface. It depends on `testcaser/integrator`  and is a shared executable that can be installed or run on any platform.



## Demo

![](https://i.imgur.com/uYC9vZ3.png)

<center> **Input Page for the GUI** </center>

![](https://i.imgur.com/2SWIIQF.png)

<center> **Result Page for the GUI** </center>

## Installation

### Linux 

The release version of VirtualJudge depends upon the following Qt Dynamic Libraries

- libQt5Widgets.so.5
- libQt5Gui.so.5
- libQt5Core.so.5
- libicui18n.so.56
- libicuuc.so.56
- libicudata.so.56

Apart from these libraries it also depends upon following shared librariess of linux.

- linux-vdso.so.1
- libgtk3-nocsd.so.0
- libpthread.so.0
- libstdc++.so.6
- libgcc_s.so.1
- libc.so.6 
- ld-linux-x86-64.so.2
- libdl.so.2
- libGL.so.1
- libm.so.6
- libz.so.1
- libgthread-2.0.so.0
- libglib-2.0.so.0
- libGLX.so.0
- libGLdispatch.so.0
- libpcre.so.3
- libX11.so.6
- libxcb.so.1
- libXau.so.6
- libXdmcp.so.6
- libbsd.so.0
- librt.so.1



We Provide all the Qt shared libraries along with the executable in the `libs/` directory. In order for dynamic linker to correctly link all the shared libraries you need to tell the linker where to look for the libs. By default the dynamic linker does not looks in the current working directory.

Here are two possible ways to install, While one requires super user privileges other does not, use the one that is best suited for you.

-  You can install the Qt libraries in one of the system library paths (e.g. `/usr/lib` on most systems). You can simpley copy-paste the libs to this directory. (Needs to be super-user)
- You can write a startup script for your application, where you modify the dynamic linker configuration (e.g., adding your Qt lib's directory to the `LD_LIBRARY_PATH` environment variable)

Once libraries are set up and ready you can simply run this `VirtualJudge` executable.

We have provided all major Qt shared libraries in the `libs/`

**Alternatively you can double click on `run.sh` and it should start the GUI**.

### Windows

*Coming Soon*



### MacOSX

**No Support Intended**



---

This is not a part of testcaser and is just a tool that uses testcaser in its core.

The command line interface of the `virtualjudge` is the primary and will get more support than this GUI interface.  We also do not want to provide any Virtual Judge GUI for the MACOS natively, however if you wish you can experiment with Linux executable and mentioned shared libraries.





