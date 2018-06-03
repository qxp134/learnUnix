edit:daytimetcpcli.o
	cc -o edit daytimetcpcli.o
daytimetcpcli.o:daytimetcpcli.c
	cc -c daytimetcpcli.c unp.h
