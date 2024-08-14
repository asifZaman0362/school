{ pkgs ? import <nixpkgs> {} }: 
let debugger = if pkgs.system == "aarch64-darwin" then pkgs.lldb else pkgs.gdb; 
in
pkgs.mkShell {
  nativeBuildInputs = [ pkgs.gcc debugger pkgs.clang-tools pkgs.python312Packages.compiledb  ];
}
