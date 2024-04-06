pong: main.cpp
	g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o pong -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -r pong
