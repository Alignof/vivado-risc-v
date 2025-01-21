if [ ! -e debian-riscv64/debian-riscv64.sd.img ]
then
    ./mk-sd-image
fi

# Check if OpenSBI exists, if not, build U-Boot and OpenSBI
if [ ! -e qemu/opensbi/build/platform/generic/firmware/fw_payload.bin ]
then
    make u-boot-qemu
    make opensbi-qemu
fi

qemu-system-riscv64 -machine virt -m 512M -nographic \
-S -gdb tcp::10000 \
-bios qemu/opensbi/build/platform/generic/firmware/fw_payload.bin \
-cpu rv64,smstateen=true \
-smp cores=1 \
-drive if=none,file=debian-riscv64/debian-riscv64.sd.img,format=raw,id=mydisk \
-device ich9-ahci,id=ahci -device ide-hd,drive=mydisk,bus=ahci.0 

#-device virtio-net-device,netdev=net0 \
#-netdev user,id=net0,tftp=tftp,hostfwd=tcp::2222-:22  \
#-device virtio-rng-pci
