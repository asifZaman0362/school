{ pkgs ? import <nixpkgs> {} }: 
let packages = 
  if pkgs.system == "aarch64-darwin" 
    then [ pkgs.lldb pkgs.clang-tools ] 
  else 
    with pkgs; [ gcc cmake gdb clang-tools freeglut libGL libGLU ];
in pkgs.mkShell {
  nativeBuildInputs = packages;
}
