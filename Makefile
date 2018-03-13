SRC=main.cpp TrainingData.cpp
OBJ=main.o TrainingData.o
test: ${OBJ}
	g++ -o $@ $^

clean:
	rm -r ${OBJ} test
