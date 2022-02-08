//�����ַ���
#define maxsize 100
typedef struct {
	char a[maxsize + 1];
	int length;
}str;
//�䳤�ַ���
typedef struct {
	char *ch;
	int length;
}Str;

//��ֵ����
int strassign(Str &str, char *ch) {
	int len = 0;
	char *c = ch;
	while (*c) {
		++len;
		++c;
	}
	if (len == 0) {
		str.ch = nullptr;
		str.length = 0;
		return true;
	}
	else {
		c = ch;
		for (int i = 0; i <= len; ++i, ++c)
			str.ch[i] = *c;
		str.length = len;
		return true;
	}
}
//ȡ�����Ȳ���
int strlength(Str str) {
	return str.length;
}
//���Ƚϲ���
int strcompare(Str s1, Str s2) {
	for (int i = 0; i <= s1.length&&i <= s2.length; ++i) {
		if (s1.ch[i] != s2.ch[i]) {
			return s1.ch[i] - s2.ch[i];
		}
	}
	return s1.length - s2.length;
}
//ģʽƥ���㷨
int index(Str str, Str substr) {
	int i = 0, j = 0, k = i;
	while (i < str.length&&j < substr.length) {
		if (str.ch[i] == substr.ch[i]) {
			++i;
			++j;
		}
		else {
			j = 0;
			i = ++k;
		}
	}
	if (j == substr.length) {
		return k;
	}
	else return -1;
}
