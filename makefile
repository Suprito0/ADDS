git:
	git add .
	git commit -m "prac"
	git push

run:
	g++ Computer.cpp Move.cpp Player.cpp Human.cpp Referee.cpp main.cpp -o game
	./game