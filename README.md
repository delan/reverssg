reverssg
========

The goal of this project is to create a decompilation of *Super Solvers: Gizmos & Gadgets!* that can ideally be recompiled.

Knowledge gained here forms the basis of [ssgesus](https://bitbucket.org/delan/ssgesus), my speedrun route planner for the game.

* Disassembled: <https://delan.github.io/reverssg/1.2/ssgwin32.exe/ssgwin32.exe.html#00414750>
* Decompiled: <https://github.com/delan/reverssg/blob/default/1.2/ssgwin32.exe/annotated.c>

how the sausage is made
-----------------------

* Ghidra 10.3
* ssgwin32.exe 1.2 <https://archive.org/details/SSGCD>
* analyse as borlandcpp (somewhat better than borlanddelphi)
* export Ghidra Zip File, default options
* export HTML, default options
* export C/C++, Create Header File on, Function Tags = annotated
    * Function Tags Excluded on → ssgwin32.exe{.c,.h}
    * Function Tags Excluded off → annotated{.c,.h}

patterns to look out for
------------------------

* `(T)(&x)[y]` may mean `x` needs retyping as array
* `CONCAT22(...)` may mean undefined4 needs retyping as undefined2
* erroneous __fastcall (edit signature, change to __stdcall or __cdecl, remove first three arguments)
    * `extraout_{CL,DL,CX,DX,ECX,EDX}` may mean erroneous __fastcall
    * three or more arguments may mean erroneous __fastcall
