p4: Random.o Weapon.o Knight.o p4.o
		g++ Random.o Weapon.o Knight.o p4.o -o p4

p4.o: p4.cpp Random.h Weapon.h Knight.h
		g++ -c p4.cpp

Knight.o: Knight.cpp Knight.h Random.h Weapon.h
		g++ -c Knight.cpp

Weapon.o: Weapon.cpp Weapon.h
		g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	    g++ -c Random.cpp

clean:
		rm *.o p4
