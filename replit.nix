{ pkgs }: {
	deps = [
   pkgs.zulu11
   pkgs.q-text-as-data
   pkgs.nano
   pkgs.openssh
		pkgs.clang
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}