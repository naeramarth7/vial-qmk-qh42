{
  description = "Flake for building vial-qmk firmware";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-25.11";
  inputs.nixos-unstable.url = "github:nixos/nixpkgs/nixos-unstable";

  inputs.vial-qmk = {
    url = "git+https://github.com/vial-kb/vial-qmk.git?submodules=1&ref=vial";
    flake = false;
  };

  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs =
    {
      self,
      nixpkgs,
      nixos-unstable,
      vial-qmk,
      flake-utils,
    }:
    flake-utils.lib.eachSystem [ "x86_64-linux" ] (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [
            (final: prev: {
              unstable = nixos-unstable.legacyPackages."${prev.stdenv.hostPlatform.system}";
            })

            (final: prev: {
              python3 = final.python310;
              python3Packages = final.python310.pkgs;
            })
          ];
        };
      in
      {
        devShell = pkgs.mkShell {
          buildInputs = [
            pkgs.unstable.qmk
            pkgs.unstable.vial
          ];
        };
      }
    );
}
