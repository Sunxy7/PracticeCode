#ROOT_PATH=${shell pwd}
#NCLUDE_PATH=${ROOT_PATH}/../lib/include
#BIN_PATH=${ROOT_PATH}/../lib/lib
#LIB=mysqlclient #-lpthread -static
#CC=g++
#DEFILE=-DDEBUG 

sql_api:sql_api.cpp
	g++ -o $@ $^ -L /usr/lib/mysql -lmysqlclient
.PHONY:clean
clean:
	rm -f sql_api


