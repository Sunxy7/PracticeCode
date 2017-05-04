#!/bin/bash

ROOT_PATH=$(pwd)
INCLUDE=$ROOT_PATH

#http src
SRC=$(ls *.c | tr '\n' ' ')
OBJ=$(ls *.c | sed 's/\.c/\.o/g' | tr '\n' ' ')
SERVER_NAME=http
CC=gcc
LIB=-lpthread

#http Makefile
cat <<EOF > Makefile
.PHONY:all
all:${SERVER_NAME} cgi

${SERVER_NAME}:${OBJ}
	${CC} -o \$@ \$^ $LIB
%.o:%.c
	${CC} -c \$<
.PHONY:cgi
cgi:
	cd cgi;make;make output;cd -

.PHONY:clean
clean:
	rm -f *.o $SERVER_NAME output; cd cgi; make clean; cd -

.PHONY:output
output:
	mkdir output
	cp ${SERVER_NAME} output/
	cp -rf log output/
	cp -rf conf output/
	cp -rf wwwroot output/
	mkdir -p output/wwwroot/cgi_bin
	cp -f cgi_math output/wwwroot/cgi_bin/
	cp -f http_ctl.sh output/
EOF

#cgi
CGI_PATH=$ROOT_PATH/cgi
MATH_SRC=$(ls $CGI_PATH | grep 'math'|grep -E '.c$')
MATH_CGI_BIN=cgi_math

#cgi Makefile
cat << EOF > $CGI_PATH/Makefile
${MATH_CGI_BIN}:$MATH_SRC
	$CC -o \$@ \$^
.PHONY:clean
clean:
	rm -f $MATH_CGI_BIN

.PHONY:output
output:
	cp $MATH_CGI_BIN ..
EOF

#





