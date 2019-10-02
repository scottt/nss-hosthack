libnss_hosthack.so.2: nss-hosthack.c
	$(CC) -g3 -Os -Wall -Wextra -fdiagnostics-show-option -shared -fPIC -Wl,-soname -Wl,$@ $< -o $@

.PHONY: clean
clean:
	rm -f libnss_hosthack.so.2
