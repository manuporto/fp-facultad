#!/bin/sh

# path
ROOT=`dirname $0`
BASE="$ROOT/Contents/Linux"

# execute
exec "$BASE/squeakvm" \
	-plugins "$BASE" \
	-encoding latin1 \
	-vm-display-X11 \
	"$ROOT/Contents/Resources/pharo.image"
