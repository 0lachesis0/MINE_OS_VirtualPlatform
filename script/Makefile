#/***************************************************
#		 Copyright (c) 2018 MINE 田宇
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2 of the GNU General Public
# License as published by the Free Software Foundation.
#
#***************************************************/

all:
	gcc -o kallsyms kallsyms.c
	nm -n system | ./kallsyms > kallsyms.S
	gcc -c kallsyms.S

clean:
	rm -rf kallsyms kallsyms.o kallsyms.S
