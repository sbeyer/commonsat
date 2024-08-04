#!/bin/sh
# Run doxygen and fail if there are warnings or errors

STDOUT="dox-stdout-$$"
STDERR="dox-stderr-$$"

make -C build doc >$STDOUT 2>$STDERR
cleanup() {
	rm -f "$STDOUT" "$STDERR"
}
trap cleanup 1 2 3 6 15

cat $STDOUT

ret=0

if [ -s $STDERR ]
then
	echo
	echo "== Doxygen warnings/errors =="
	cat "$STDERR"
	ret="$(wc -l "$STDERR")"
fi

cleanup
exit $ret
