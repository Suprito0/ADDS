git:
	git add .
	git commit -m "prac"
	git push

run:
	g++ Computer.cpp Move.cpp Player.cpp Human.cpp Referee.cpp Paper.cpp Pirate.cpp Robot.cpp Rock.cpp Scissors.cpp Zombie.cpp Monkey.cpp Ninja.cpp main.cpp -o game
	./game