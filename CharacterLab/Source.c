#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int newline = '\n';
	int h_tab = '\t';
	int v_tab = '\v';
	int backspace = '\b';
	int c_return = '\r';
	int form_feed = '\f';
	int backslash = '\\';
	int s_quote = '\'';
	int d_quote = '\"';
	int null = '\0';

	printf("%9s  %-21s%-13s%-9s\n", "Character", "Description", "Decimal", "Hexadecimal");
	printf("%9s  %-21s%-13s%-9s\n", "---------", "-----------", "-------", "-----------");
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\n\'", "newline", newline, newline);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\t\'", "horizontal tab", h_tab, h_tab);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\v\'", "vertical tab", v_tab, v_tab);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\b\'", "backspace", backspace, backspace);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\r\'", "carriage return", c_return, c_return);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\f\'", "form feed", form_feed, form_feed);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\\\\'", "backslash", backslash, backslash);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\\'\'", "single quote", s_quote, s_quote);
	printf("%6s     %-22s%-12d%#-9.2x\n", "\'\\\"\'", "double quote", d_quote, d_quote);
	printf("%6s     %-22s%-12d0x%#-9.2x\n", "\'\\0\'", "null", null, null);
	return 0;

}
