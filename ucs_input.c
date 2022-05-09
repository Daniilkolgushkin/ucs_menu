#include<stdlib.h>
#include<stdio.h>

int main() {
	FILE* dmenu_in = popen("dmenu -fn '' -p codepoint: </dev/null", "r");
	char digits[] = "0123456789";
	char lovercase[] = "abcdef";
	char uppercase[] = "ABCDEF";
//	char cmd[] = "printf '\\u0000' | xclip -i";
	char cmd[] = "printf 'type \\u0000' | xdotool -";
	char curchar = '\0';
	int place = 0;
	while (!feof(dmenu_in) && place < 4) {
		curchar = getc(dmenu_in);
		for (unsigned char i = 0; i < 10; i ++) {
			if (curchar == digits[(int) i]) {
				cmd[15 + (int) place] = curchar;
				place ++;
				break;
			}
		}
		for (unsigned char i = 0; i < 5; i ++) {
			if (curchar == lovercase[(int) i] || curchar == uppercase[(int) i]) {
				cmd[15 + (int) place] = uppercase[(int) i];
				place ++;
				break;
			}
		}
	}
	//FILE* out = popen(cmd, "w");
	fclose(dmenu_in);
	//fclose(out);
	system(cmd);
	return 0;
}
