#!/bin/sh
./mkimage -A arm -O linux -T kernel -C none -a 30008000 -e 30008040 -n linux-2.6.13 -d zImage uImage
