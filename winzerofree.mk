TARGET = winzerofree.exe
CFLAGS = /O2 -DWIN32 -DNDEBUG -D_CONSOLE -D_UNICODE -DUNICODE -D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_WARNINGS

OBJS = dbgwrappers.obj logging.obj winzerofree.obj

all: $(TARGET)

$(TARGET): $(OBJS)
	link /NOLOGO /SUBSYSTEM:CONSOLE,5.01 /OUT:$@ $(OBJS) advapi32.lib

clean:
	del /Q $(TARGET) $(OBJS)
