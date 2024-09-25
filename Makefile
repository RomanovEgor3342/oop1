# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++11 -Iincludes -mconsole

# Папки с исходным кодом и заголовочными файлами
SRC_DIR = classes
INCLUDES_DIR = includes

# Поиск всех .cpp файлов в папке src и корневой папке
SRCS = $(wildcard main.cpp $(SRC_DIR)/*.cpp)

# Автоматическая генерация объектных файлов из .cpp файлов
OBJS = $(SRCS:.cpp=.o)

# Имя исполняемого файла
TARGET = my_program

# Правило по умолчанию: сборка всего проекта
all: $(TARGET)

# Правило для создания исполняемого файла из объектных файлов
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Автоматическое правило для компиляции всех .cpp файлов в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(SRC_DIR)/*.o main.o $(TARGET)

