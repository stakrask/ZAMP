# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -g -pedantic -std=c++17 -Iinc
LDFLAGS = -Wall
LIBS = -lxerces-c

# Katalogi
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
PLUGIN_DIR = plugin
LIBS_DIR = libs

# Pliki źródłowe
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/CommandRegistry.cpp \
          $(SRC_DIR)/LibInterface.cpp \
          $(SRC_DIR)/Preprocessor.cpp \
          $(SRC_DIR)/Configuration.cpp \
          $(SRC_DIR)/xmlinterp.cpp \
          $(SRC_DIR)/Connection.cpp

# Pliki obiektowe
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Nazwa programu wykonywalnego
TARGET = interpreter

# Cel główny
all: directories $(LIBS_DIR) plugins $(TARGET)
	@echo ""
	@echo "=========================================="
	@echo " Kompilacja zakończona pomyślnie!"
	@echo "=========================================="
	@echo ""
	@echo "Aby uruchomić program, wpisz: ./$(TARGET)"
	@echo ""

# Tworzenie katalogów
directories:
	@mkdir -p $(OBJ_DIR)

$(LIBS_DIR):
	@mkdir -p $(LIBS_DIR)

# Kompilacja wtyczek
plugins:
	@echo ""
	@echo "=== Kompilacja wtyczek ==="
	@$(MAKE) -C $(PLUGIN_DIR)
	@echo ""

# Linkowanie programu głównego
$(TARGET): $(OBJECTS)
	@echo ""
	@echo "=== Linkowanie programu głównego ==="
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo "Program $(TARGET) utworzony."

# Kompilacja plików źródłowych
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Kompilacja: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Zależności
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/Preprocessor.hh \
                   $(INC_DIR)/CommandRegistry.hh $(INC_DIR)/Configuration.hh \
                   $(INC_DIR)/xmlinterp.hh $(INC_DIR)/Connection.hh

$(OBJ_DIR)/CommandRegistry.o: $(SRC_DIR)/CommandRegistry.cpp \
                               $(INC_DIR)/CommandRegistry.hh \
                               $(INC_DIR)/LibInterface.hh

$(OBJ_DIR)/LibInterface.o: $(SRC_DIR)/LibInterface.cpp \
                           $(INC_DIR)/LibInterface.hh \
                           $(INC_DIR)/AbstractInterp4Command.hh

$(OBJ_DIR)/Preprocessor.o: $(SRC_DIR)/Preprocessor.cpp \
                           $(INC_DIR)/Preprocessor.hh

$(OBJ_DIR)/Configuration.o: $(SRC_DIR)/Configuration.cpp \
                           $(INC_DIR)/Configuration.hh \
                           $(INC_DIR)/Vector3D.hh

$(OBJ_DIR)/xmlinterp.o: $(SRC_DIR)/xmlinterp.cpp \
                       $(INC_DIR)/xmlinterp.hh \
                       $(INC_DIR)/Configuration.hh

$(OBJ_DIR)/Connection.o: $(SRC_DIR)/Connection.cpp \
                         $(INC_DIR)/Connection.hh

# Czyszczenie
clean:
	@echo "Czyszczenie plików obiektowych..."
	@rm -f $(OBJ_DIR)/*.o
	@$(MAKE) -C $(PLUGIN_DIR) clean

cleanall: clean
	@echo "Usuwanie programu wykonywalnego i bibliotek..."
	@rm -f $(TARGET)
	@rm -f $(LIBS_DIR)/*.so
	@$(MAKE) -C $(PLUGIN_DIR) cleanall
	@find . -name '*~' -exec rm {} \;
	@echo "Kompletne czyszczenie zakończone."

# Uruchomienie programu
run: all
	@echo ""
	@echo "=== Uruchomienie programu ==="
	@./$(TARGET)

# Pomoc
help:
	@echo ""
	@echo "Dostępne cele:"
	@echo "  all       - kompilacja całego projektu (domyślne)"
	@echo "  plugins   - kompilacja tylko wtyczek"
	@echo "  clean     - usunięcie plików obiektowych"
	@echo "  cleanall  - usunięcie wszystkich wygenerowanych plików"
	@echo "  run       - kompilacja i uruchomienie programu"
	@echo "  help      - wyświetlenie tej pomocy"
	@echo ""

.PHONY: all directories plugins clean cleanall run help