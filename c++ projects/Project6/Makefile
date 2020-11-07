project6: Random.o Weapon.o Person.o Zombie.o ZCS.o project6.o
		g++ Random.o Weapon.o Person.o Zombie.o ZCS.o project6.o -o project6

project6.o: project6.cpp Zombie.h Weapon.h Person.h ZCS.h
		g++ -c project6.cpp

ZCS.o: ZCS.cpp ZCS.h Zombie.h Person.h Weapon.h
		g++ -c ZCS.cpp

Person.o: Person.cpp Person.h Weapon.h
		g++ -c Person.cpp

Zombie.o: Zombie.cpp Zombie.h Random.h
		g++ -c Zombie.cpp

Weapon.o: Weapon.cpp Weapon.h
		g++ -c Weapon.cpp

Random.o: Random.cpp Random.h
	     g++ -c Random.cpp

clean:
		rm *.o project6
