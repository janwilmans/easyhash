#!/bin/bash

SCRIPTDIR=$(realpath $(dirname $0))

cd $SCRIPTDIR
rm -rf build

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/easyhash
DESTDIR=install cmake --build build --target install
