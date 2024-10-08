#!/bin/bash
assert() {
	expected="$1"
	input="$2"

	./9cc "$input" > tmp.s
	cc -o tmp tmp.s
	./tmp
	actual="$?"

	if [ "$actual" = "$expected" ]; then
		echo "$input => $actual"
	else
		echo "$input => $expected expected, but got $actual"
		exit 1
	fi
}

assert 0 "0;"
assert 42 "42;"
assert 41 "12+34-5;"
assert 41 " 12 + 34 - 5 ;"
assert 19 "(2+5)*2 + 5 ;"
assert 5 "-3+8;"
assert 0 "1 == 2;"
assert 1 "(2+5)*2 + 5 == (2+5)*2 + 5;"
assert 5 "a=5;b=0;a-b;"
echo OK
