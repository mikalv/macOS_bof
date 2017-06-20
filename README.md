# macOS Buffer Overflow
Hi and welcome to multiplex3r's demonstration of a buffer overflow attack on a macOS Mach-O binary.

# Non-standard prerequisites
Extra software I use for this is as follows:
 * gdb -> `$ brew install gdb`
 * peda.py for better gdb -> https://github.com/longld/peda
 * Metasploit-Framework for shellcode -> https://github.com/rapid7/metasploit-framework

# Walkthrough
To perform this attack we are first creating a vulnerable Mach-O binary by compiling the macOS_bof.c code.

We can now use the `file` and `otool -hv` commands to find out more information about the binary and it's mitigations.

Then we can also use `otool` (I love otool) to print out the bianry disassembly to perform some static analysis on the binary.

Next load the binary up in gdb (remember to codesign gdb so that it can take control of another process -> https://gcc.gnu.org/onlinedocs/gnat_ugn/Codesigning-the-Debugger.html)

We then set an argument which will cause a crash and determine the offsets for overwriting the EIP register.

Now we need to find a ret gadget to overwrite EIP with. This will return us into our shellcode. Which for the sake of demonstration is going to be `0xcc` or an INT 3 which will cause our debugger to halt.

We now can confirm that we have successfully jumped into our shellcode and can put real shellcode there.

Let's generate some shellcode using MSF.

Now to retry the exploit outside the debugger to see if we can get a shell.

Voila!
