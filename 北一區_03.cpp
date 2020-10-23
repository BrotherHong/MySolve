#include <iostream>
using namespace std;

char pw[26];
int used[26];
int idx = 0;

void process(string s) {
	int i;
	string result = "";
	for (i = 0;i < s.length();i++) {
		if (!isalpha(s[i])) continue;
		if (!used[s[i]-'a']) {
			used[s[i]-'a'] = 1;
			pw[idx++] = s[i];
		}
	}
}

void makePw() {
	int word = (pw[idx-1]+1-'a') % 26;
	for (;idx < 26;) {
		if (!used[word]) {
			used[word] = 1;
			pw[idx++] = (char)(word+'a');
		} else word = (word+1) % 26;
	}
}

char findChar(int c) {
	int i;
	for (i = 0;i < 26;i++) {
		if (pw[i]-'a' == c) return (char)(i+'a');
	}
}

int main() {
	int type, i; // 0: decode / 1: encode
	char input[101];
	string key, tg;
	string result = "";
	cin >> type;
	cin.ignore();
	
	cin.getline(input, sizeof(input));
	key = input;
	
	cin.getline(input, sizeof(input));
	tg = input;
	
	process(key);
	makePw();
	
	if (type == 0) { // decode
		for (i = 0;i < tg.length();i++) {
			if (!isalpha(tg[i])) {
				result += " ";
				continue;
			}
			if (isupper(tg[i])) {
				result += toupper(findChar(tg[i]-'A'));
			} else {
				result += findChar(tg[i]-'a');
			}
		}
	} else { // encode
		for (i = 0;i < tg.length();i++) {
			if (!isalpha(tg[i])) {
				result += " ";
				continue;
			}
			if (isupper(tg[i])) {
				result += toupper(pw[tg[i]-'A']);
			} else {
				result += pw[tg[i]-'a'];
			}
		}
	}
	cout << result;
	return 0;
}

/*
0
cipher
Texxa Mafxh

ans: Hello World

1
happy birthday
HowAreYou

ans: TlwHobZlu
*/
