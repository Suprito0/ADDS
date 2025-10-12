git:
	git add .
	git commit -m "prac"
	git push
run:
	g++ LinkedList.cpp Node.cpp main.cpp BigNumCalc.cpp -o main
	./main