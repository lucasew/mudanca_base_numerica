EXECUTAVEL?=basecalc

all:
	${CC} -Wall main.c src/basecalc.c tests/test_basecalc.c -o ${EXECUTAVEL} -g

clean:
	rm ${EXECUTAVEL}
