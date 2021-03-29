empltest: empltest.o employee.o manager.o Supervisor.o 
	c++  -o  test empltest.o employee.o manager.o Supervisor.o
empltest.o: employee.h manager.h Supervisor.h
	c++ -c empltest.cpp
employee.o: employee.h
	c++ -c employee.cpp
manager.o: manager.h employee.h
	c++ -c manager.cpp
Supervisor.o: Supervisor.h manager.h 
	c++ -c Supervisor.cpp
Clean:
	rm *.o

