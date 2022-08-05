CFLAGS += -D_GUN_SOURCE -D_XOPEN_SOURCE -D_FILE_OFFSET_BITS=64 -Wall  -lcrypt

%:%.c
	gcc $< -o $@ $(CFLAGS)
