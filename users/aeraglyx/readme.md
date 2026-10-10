## Instructions

After cloning and entering the `qmk_userspace` repo:

```bash
nix-shell
qmk setup
git -C ../qmk_firmware submodule add https://github.com/aeraglyx/dasbob keyboards/grooovebob/dasbob
qmk compile -j $(nproc) --compiledb
```
