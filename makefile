git:
	git add Finder.cpp Finder.h
	git commit -m "prac4"
	git push

run:
	g++ Finder.cpp main.cpp -o game
	./game