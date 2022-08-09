PHONY: run rebuild clean

TARGET=run.o

all: build

build: $(TARGET)
	

$(TARGET):
	./build.sh

run: build
	./build/run.o

clean:
	rm -rf build

rebuild: clean build
