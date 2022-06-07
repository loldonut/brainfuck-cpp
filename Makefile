# I don't think this a good make file at all
# but this should do for a small project like this
# 	- loldonut
build:
	g++ src/*.cpp -o bf

# Hello World Test
test:
	g++ src/*.cpp -o bf
	./bf ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-]<+."
