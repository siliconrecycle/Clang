#include <stdio.h>

void escape(char s[], char t[]);
void escape01(char t[], char s[]);

int main(void) {
	char msg[] =
		"Yuan, hello		today is 20220918"
		"hello world!\n"
		"Tomorrow should be a good day!";
	
	printf("%s\n", msg);

	char rst[1000];

	escape(rst, msg);
	printf("%s\n", rst);	

	escape01(msg, rst);
	printf("%s\n", msg);
}

void escape01(char t[], char s[])
{
	int i, j;


	for (i = j = 0; s[i] != '\0'; ++i) {
		switch (s[i]) {
		case '\\':
			switch (s[++i]) {
			case 't':
				t[j++] = '\t';
				break;
			case 'n':
				t[j++] = '\n';
				break;
			default:
				t[j] = '\\';
				t[++j] = s[++i];
				++j;
				break;
			}
			break;
		default:
			t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}


void escape(char s[], char t[])
{
	int i, j;


	for (i = j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		case '\n':
			s[j] = '\\';
			s[++j] = 'n';
			++j;
			break;
		case '\t':
			s[j] = '\\';
			s[++j] = 't';
			++j;
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}
