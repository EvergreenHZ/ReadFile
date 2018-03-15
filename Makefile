TARGET=a.out
SRC=test.cpp TrainingData.cpp utils.cpp LinearRegression.cpp matrix.cpp
OBJ=test.o TrainingData.o utils.o LinearRegression.o matrix.o
${TARGET}: ${OBJ}
	g++ -o $@ $^ -g  -std=c++11

clean:
	rm -r ${OBJ} ${TARGET}
