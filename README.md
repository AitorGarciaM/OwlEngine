# OwlEngine
OwlEngine it's a GameEngine.

Actually, to prevent errors when cloning the repository, do the following steps:
1) Do "git clone --recurse-submodules" instead "git clone".
2) Build Sandbox.
3) Go to OwlEngine\bin\Debug32-windows-x86 and delete Sandbox file.
4) Rebuild Sandbox project.
5) Include OwlEngine\bin\Debug32-windows-x86\OwlEngine\OwlEngine.dll into OwlEngine\bin\Debug32-windows-x86\Sandbox
6) Include glew32.dll and SDL2.dll(x86) into OwlEngine\bin\Debug32-windows-x86\Sandbox
