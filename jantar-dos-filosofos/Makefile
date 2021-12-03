# Flags p/ linking
LDFLAGS ?= -pthread

# Prefixo padrão para instalar
PREFIX ?= /usr/local
# Onde ficam as binárias no prefixo
BIN_DIR ?= $(PREFIX)/bin

# Nome do executável
TARGET_EXEC ?= jantar_dos_filosofos
# Diretório para artefatos
BUILD_DIR ?= ./build
# Diretório com código fonte
SRC_DIR ?= ./src

# Pegar todas as .c em SRC_DIR
SRCS := $(shell find $(SRC_DIR) -name *.c)
# Mapear para os equivalentes .o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# Regra para o executável
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Regra para os .o
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Apagar diretório de artefatos
clean:
	$(RM) -r $(BUILD_DIR)

# Instalar no prefixo
install: $(BUILD_DIR)/$(TARGET_EXEC)
	install -d $(BIN_DIR)
	install -t $(BIN_DIR) $<

# Executar executável
run: $(BUILD_DIR)/$(TARGET_EXEC)
	./$<

# Comando mkdir -p para criar diretório
MKDIR_P ?= mkdir -p