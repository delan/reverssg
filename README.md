reverssg
========


The goal of this project is to create a decompilation of *Super Solvers: Gizmos & Gadgets!* that can ideally be recompiled.


Knowledge gained here forms the basis of [ssgesus](https://bitbucket.org/delan/ssgesus), my speedrun route planner for the game.


* Disassembled: <https://delan.github.io/reverssg/1.2/ssgwin32.exe/ssgwin32.exe.html#00414750>
* Decompiled: <https://github.com/delan/reverssg/blob/default/1.2/ssgwin32.exe/annotated.c>


how the sausage is made
-----------------------


* Ghidra 10.1.2
* ssgwin32.exe 1.2 <https://archive.org/details/SSGCD>
* export Ghidra Zip File, default options
* export HTML, default options
* export C/C++, Create Header File on, Function Tags = annotated
    * Function Tags Excluded off → ssgwin32.exe.annotated{.c,.h}
    * Function Tags Excluded on → ssgwin32.exe{.c,.h}
