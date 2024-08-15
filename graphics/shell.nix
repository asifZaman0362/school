{ pkgs ? import <nixpkgs> {} }: 
let packages = 
  if pkgs.system == "aarch64-darwin" 
    then [ pkgs.lldb pkgs.clang-tools ] 
  else 
    with pkgs; [ gcc gdb clang-tools glfw ];
in pkgs.mkShell {
  nativeBuildInputs = packages;
}
