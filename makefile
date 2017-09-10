EXE_NAME = a.out
DIR_CPP = $(wildcard ./*.cpp)
DIR_OBJ = $(patsubst %.cpp, %.o, $(DIR_CPP))
DIR_DEP = $(patsubst %.o, %.d, $(DIR_OBJ))

$(EXE_NAME): $(DIR_OBJ)
	g++ $(DIR_OBJ) -o $(EXE_NAME) -lpthread

%.o:%.cpp
	g++ -c -g -MMD $< -o $@

-include $(DIR_DEP)

clean:
	rm -rf *.o *.d *.out
