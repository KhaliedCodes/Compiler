#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>	
#include <ctype.h>

int isKeyword(char buffer[]) {
	char keywords[][10] = { "int", "if" };
	int i, flag = 0;

	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}

	return flag;
}

void lex() {
	char ch, buffer[15], operators[] = "><+-*/%=";
	FILE* fp, * fi;
	int i, j = 0;
	fi = fopen("D:\\New folder\\id.txt", "w");
	fp = fopen("D:\\New folder\\input.txt", "r");
	printf("\n");
	fscanf(fp, "%c", &ch);
	while (!feof(fp)) {
		for (i = 0; i < 8; ++i) {
			if (ch == operators[i]) {

				fprintf(fi, "%c operator\n", ch);
			}
		}

		if (isalpha(ch)) {
			buffer[j] = ch;
			j++;
		}
		else if (isdigit(ch)) {

			fprintf(fi, "%c num\n", ch);
		}
		else if (ch == '(') {

			fprintf(fi, "%c Lbracket\n", ch);
		}
		else if (ch == ')') {

			fprintf(fi, "%c Rbracket\n", ch);
		}
		else if (ch == '\n') {

			fprintf(fi, "this newline\n", ch);
		}

		else if (ch == ';') {

			fprintf(fi, "%c semicolon\n", ch);
		}

		else if (ch == ' ' && j != 0) {
			buffer[j] = '\0';
			j = 0;


			if (isKeyword(buffer) == 1) {

				fprintf(fi, "%s keyword\n", buffer);
			}
			else {

				fprintf(fi, "%s identifier\n", buffer);
			}
		}

		fscanf(fp, "%c", &ch);
	}
	fclose(fi);
	fclose(fp);

}

void intermedient(){
	FILE* fi, * finter, * ft;
	char z[50], y[10], x[20], r[20], e[20], l[20];
	fi = fopen("D:\New folder\\id.txt", "r");
	//ft= fopen("C:\\Users\\Estabrk\\Desktop\\compiler\\id.txt", "r");
	char ahmed[12], m[50];
	int count = 0;
	fscanf(fi, "%s%s", ahmed, m);


	while (!feof(fi))
	{

		fscanf(fi, "%s%s", ahmed, m);
		//printf("\nahmed = %s ", ahmed);
		//printf("\n m = %s ", m);
		int s, n;
		n = strcmp(m, "semicolon");
		if (n == 0)
		{
			break;
		}

	}
	int i = 1;
	while (!feof(fi))
	{
		fscanf(fi, "%s%s", ahmed, m);

		int a;
		a = strcmp(m, "identifier");
		int b;
		int c;
		int o;
		b = strcmp(m, "semicolon");

		o = strcmp(m, "keyword");
		if (a != 0 && o == 0)
		{
			c = strcmp(m, "Rbracket");

			while (c != 0)
			{
				c = strcmp(m, "Rbracket");
				fscanf(fi, "%s%s", ahmed, m);

				if (c == 0)
				{
					break;
				}


			}

		}
		else if (a == 0)
		{
			strcpy(x, ahmed);
			//printf("\n%s", ahmed);
			fscanf(fi, "%s%s", ahmed, m);
			//printf("\n\nahmed=%s\n", ahmed);
			o = strcmp(m, "operator");
			if (o == 0)
			{
				strcpy(y, ahmed);
				//printf(" %s", ahmed);
				fscanf(fi, "%s%s", ahmed, m);

				o = strcmp(m, "identifier");
				int d;
				d = strcmp(m, "num");
				//printf("\nahmedddddd= %s\n", ahmed);
				if (o == 0 || d == 0)
				{
					strcpy(z, ahmed);
					//printf("%s", ahmed);
					fscanf(fi, "%s%s", ahmed, m);

					o = strcmp(m, "semicolon");
					if (o == 0)
					{
						printf("%s", x);
						printf("%s", y);
						printf("%s", z);

						printf("%s", ahmed);
						printf("\n");
					}
					else
					{

						o = strcmp(m, "operator");
						//	printf("ana bra ");
						//	printf("\nahmedddddd= %s\n", ahmed);
						if (o == 0)
						{
							//printf("%s", ahmed);
							strcpy(r, ahmed);
							fscanf(fi, "%s%s", ahmed, m);
							o = strcmp(m, "identifier");
							d = strcmp(m, "num");
							//	printf("\n1\n");
							if (o == 0 || d == 0)
							{
								//	printf("%s", ahmed);
								strcpy(e, ahmed);
								fscanf(fi, "%s%s", ahmed, m);
								o = strcmp(m, "semicolon");
								//	printf("\n2\n");
								if (o == 0)
								{
									printf("%s", x);
									printf("%s", y);
									printf("%s", z);
									printf("%s", r);
									printf("%s", e);
									printf("%s", ahmed);
									printf("\n");
									//printf("\n\n 2 \n\n");
								}
								else
								{
									//printf("ahmed=%s", ahmed);

									printf("r%d %s %s %s %s ;", i, y, z, r, e);
									i++;
									c = strcmp(m, "semicolon");
									while (c != 0)
									{
										o = strcmp(m, "operator");

										if (o == 0)
										{
											printf("\n");
											printf("r%d = r%d %s ", i, i - 1, ahmed);
											fscanf(fi, "%s%s", ahmed, m);
											o = strcmp(m, "identifier");
											d = strcmp(m, "num");
											if (o == 0 || d == 0)
											{
												printf("%s ;\n", ahmed);

											}

											i++;
										}
										fscanf(fi, "%s%s", ahmed, m);
										c = strcmp(m, "semicolon");


										if (c == 0)
										{

											break;
										}

									}

								}

							}

						}


					}
				}

			}
		}




	}



}

int parser() {
	FILE* fp, * fi;
	//char  lien, op1[20], op2[20], op3[20], a1[20], a2[20], a3[20], a4[20];
	int flag = 0;
	char ahmed[12], m[50];
	int a, b, c, d, e, l, r, no;
	int id = 0, lb = 0, rb = 0, fii = 0, op = 0, n = 0, semi = 0, ne = 0, in = 0, i = 0;
	fi = fopen("D:\\New folder\\id.txt", "r");
	fscanf(fi, "%s%s", ahmed, m);
	a = strcmp(ahmed, "int");
	if (a != 0) {
		flag = 1;
		printf("Syntax error int\n");
	}
	else {
		in = 1;
		fscanf(fi, "%s%s", ahmed, m);
		while (strcmp(m, "semicolon") != 0) {

			//printf("\nm = %s\n", m);
			if (strcmp(m, "identifier") != 0) {
				printf("\nSyntax error %s is not a valid variable name\n", ahmed);
				flag = 1;
				break;
			}
			fscanf(fi, "%s%s", ahmed, m);
		}
		semi = 1;

		while (!feof(fi)) {
			if (flag)
				break;
			id = 0, lb = 0, fii = 0, op = 0, n = 0;
			//printf("\n\nhellllllooooooooo\n\n");
			fscanf(fi, "%s%s", ahmed, m);

			while (!feof(fi)) {
				//printf("\nm up = %s , ne =%d\n", m, ne);
				a = strcmp(m, "identifier");
				b = strcmp(m, "keyword");
				c = strcmp(m, "num");
				d = strcmp(m, "operator");
				l = strcmp(m, "Lbracket");
				r = strcmp(m, "Rbracket");
				no = strcmp(m, "semicolon");
				if (a == 0) {
					semi = 0;
					//printf("\nahmed = %s\n",  ahmed);
					//printf("\nlb =%d, op =%d, ne =%d, in =%d \n", lb, op, ne, in);
					if ((lb == 1 || op == 1 || ne == 1 || in == 1)) {
						op = 0;
						ne = 0;
						FILE* fo = fopen("D:\\New folder\\id.txt", "r");
						char s1[10], s2[20];
						fscanf(fo, "%s%s", s1, s2);
						//printf("\ns1 =%s ahmed = %s\n", s1, ahmed);
						while (strcmp(s2, "semicolon") != 0) {



							//printf("\ns1 =%s ahmed = %s\n", s1, ahmed);

							if (strcmp(s2, "identifier") == 0) {
								if (strcmp(s1, ahmed) == 0) {

									id = 1;
									flag = 0;
									break;
									//return flag;
								}

							}

							fscanf(fo, "%s%s", s1, s2);
							flag = 1;
						}
						if (flag) {
							printf("\nSyntax error %s not declared\n", ahmed);
							flag = 1;
							return flag;
						}
						//

						//printf("\nFlag = %d\n", flag);
						//return flag;
						fclose(fo);
					}
					else {
						printf("\n Error identifier position\n");
						flag = 1;
						return flag;
					}
				}


				if (b == 0) {
					semi = 0;
					if (strcmp(ahmed, "if") == 0) {
						fii = 1;
					}
					if (strcmp(ahmed, "int") == 0) {
						printf("\nNo other declarations allowed\n");
						flag = 1;
						return flag;
					}
				}
				if (c == 0) {
					semi = 0;
					if (op != 1) {
						printf("\nSyntax error no operator detected\n");
						flag = 1;
						return flag;
					}

					else {
						n = 1;
					}

				}
				if (d == 0) {
					semi = 0;
					if (n || id)
						op = 1;
					else {
						printf("\nNo identefier or number preceeded operator detected\n");
						flag = 1;
						return flag;

					}

				}
				if (l == 0) {
					semi = 0;
					if (!fii) {
						printf("\nNo if keyword detected\n");
						flag = 1;
						return flag;
					}
					else {
						lb = 1;
					}
				}
				if (r == 0) {
					if (!lb) {
						printf("\nNo left bracket detcted\n");
						flag = 1;
						return flag;
					}
					else {
						rb = 1;
						lb = 0;
					}

				}
				if (no == 0) {
					semi = 1;
				}
				//printf("\nm = %s\n, semi = %d, rb = %d, ne = %d", m, semi, rb, ne);
				//printf("m = %s\n", m);
				if (strcmp(m, "newline") == 0 || feof(fi)) {
					ne = 1;

					if(!semi && !rb ) {
						printf("\nError semicolon or right bracket\n");
						flag = 1;
						return flag;
					}
				}
				in = 0;
				fscanf(fi, "%s%s", ahmed, m);


				//printf("\nne = %d, i = %d\n", ne, i);


				//printf("\n ahmed2 = %s\n", ahmed);
			}

		}

	}
	fclose(fi);

	return flag;
}

void tree() {

	FILE* fi;
	int a, b, c, d, e, l, r, no;
	int dec = 0, semi = 0, rb = 0, fii = 0, id =1 , exp =0;
	char ahmed[20], m[20];
	fi = fopen("D:\\New folder\\id.txt", "r");
	fscanf(fi, "%s%s", ahmed, m);
	printf("\nProgram{\n");
	while (!feof(fi)) {

		a = strcmp(m, "identifier");
		b = strcmp(m, "keyword");
		c = strcmp(m, "num");
		d = strcmp(m, "operator");
		l = strcmp(m, "Lbracket");
		r = strcmp(m, "Rbracket");
		no = strcmp(m, "semicolon");
		if ((rb || semi) && strcmp(m, "newline") != 0) {
			rb = 0;
			semi = 0;
			printf("\n	statement{\n");
		}
		if (!a) {
			
			if (!dec && id) {
				exp = 1;
				printf("\n		exp{\n");
				printf("\n			Identifier -> %s\n", ahmed);
				id = !id;
			}
			else
				printf("\n			Identifier -> %s\n", ahmed);

		}
		
		if (!b) {
			if (!strcmp(ahmed, "int")) {
				printf("\n	Declaration{\n");
				printf("\n		Keyword -> %s\n", ahmed);
				dec = 1;
			}
			if (!strcmp(ahmed, "if")) {
				fii = 1;
				printf("\n		ifstat{");
				printf("\n			Keyword -> %s\n", ahmed);
			}
		}
		if (!c) {
			printf("\n			num -> %s\n", ahmed);
		}
		if (!d) {
			printf("\n			operation -> %s\n", ahmed);
		}
		if (!l) {
			printf("\n			(\n");
		}
		if (!r) {
			id = 1;
			printf("\n		}	)\n		}\n");
			rb = 1;
		}
		if (!no) {
			id = 1;
			if (dec) {
				dec = 0;
				printf("\n	}\n		;\n");
			}
			else
				printf("\n		}\n		;\n	}\n");
			semi = 1;
		}
		
		fscanf(fi, "%s%s", ahmed, m);
	}
	printf("\n}\n");
	fclose(fi);

}

void gen() {
	FILE* fi, * fo;

	char x[10], type[50], temp[10];
	fi = fopen("D:\\New folder\\id.txt", "r");
	fo = fopen("D:\\New folder\\out.txt", "w");

	fscanf(fi, "%s %s", x, type);
	//	printf("x=%s\ntype=%s\n",x,type);
	while (!feof(fi)) {
		if (strcmp(x, "int") == 0) {
			fscanf(fi, "%s %s", x, type);
			//fprintf(fo, "%s RESW 1\n", x);

			fscanf(fi, "%s %s", x, type);
			while (strcmp(x, ";") != 0) {
				//fprintf(fo, "%s RESW 1\n", x);
				fscanf(fi, "%s %s", x, type);

			}

		}

		else if (strcmp(type, "identifier") == 0) {
			//printf("x=%s\ntype=%s\n",x,type);
			strcpy(temp, x);
			//printf("x=%s\n",x);
			while (strcmp(x, ";") != 0) {
				if (strcmp(x, "=") == 0) {
					fscanf(fi, "%s %s", x, type);
					fprintf(fo, "LDA %s\n", x);
					//printf("x=%s\n", x);
				}
				else if (strcmp(x, "+") == 0) {
					fscanf(fi, "%s %s", x, type);
					fprintf(fo, "ADD %s\n", x);
					//fprintf(fo, "STA %s\n", temp);
				}
				else if (strcmp(x, "-") == 0) {
					fscanf(fi, "%s %s", x, type);
					fprintf(fo, "SUB %s\n", x);
					//fprintf(fo, "STA %s\n", temp);
				}
				else if (strcmp(x, "*") == 0) {
					fscanf(fi, "%s %s", x, type);
					fprintf(fo, "MUL %s\n", x);
					//fprintf(fo, "STA %s\n", temp);
				}
				else if (strcmp(x, "/") == 0) {
					fscanf(fi, "%s %s", x, type);
					fprintf(fo, "DIV %s\n", x);
					//fprintf(fo, "STA %s\n", temp);
				}



				//printf("hi\n");

				fscanf(fi, "%s %s", x, type);
				if (strcmp(x, ";") == 0)
					fprintf(fo, "STA %s\n", temp);

			}

		}
		else if (strcmp(x, "if") == 0) {

			fscanf(fi, "%s %s", x, type);
			//printf("x=%s\ntype=%s\n",x,type);
			fscanf(fi, "%s %s", x, type);
			//printf("this is %s\n", x);
			while (strcmp(x, ")") != 0) {
				if (strcmp(type, "identifier") == 0 || strcmp(type, "num") == 0) {
					//	printf("this is %s\n", x);
					fprintf(fo, "LDA %s\n", x);
				}
				if (strcmp(type, "operator") == 0) {
					if (strcmp(x, "<") == 0) {
						fscanf(fi, "%s %s", x, type);
						fprintf(fo, "COMP %s\n", x);
						fprintf(fo, "JLT %s\n", x);
					}
					else if (strcmp(x, ">") == 0) {
						fscanf(fi, "%s %s", x, type);
						fprintf(fo, "COMP %s\n", x);
						fprintf(fo, "JGT %s\n", x);
					}
					else if (strcmp(x, "=") == 0) {
						fscanf(fi, "%s %s", x, type);
						fprintf(fo, "COMP %s\n", x);
						fprintf(fo, "JEQ %s\n", x);
					}
				}
				fscanf(fi, "%s %s", x, type);
			}

		}
		fscanf(fi, "%s %s", x, type);

	}


	printf("\nGenerated successfully\n");


	fclose(fi);
	FILE* fv;
	char z[50], y[10];
	fv = fopen("D:\\New folder\\id.txt", "r");


	fscanf(fv, "%s %s", y, z);
	//printf("y=%s\nz=%s\n",y,z);
	while (!feof(fv)) {
		if (strcmp(y, "int") == 0) {
			fscanf(fv, "%s %s", y, z);
			fprintf(fo, "%s RESW 1\n", y);
			//	printf("y=%s\n",y);
			fscanf(fv, "%s %s", y, z);
			while (strcmp(y, ";") != 0) {
				fprintf(fo, "%s RESW 1\n", y);
				fscanf(fv, "%s %s", y, z);


			}
			if (strcmp(y, ";") == 0) {
				//				printf("djsjghjds\n");
				break;
			}
			else
				fscanf(fv, "%s %s", y, z);

		}
		if (strcmp(y, ";") == 0) {
			//					printf("ddddddddddddd\n");
			break;
		}
		else

			fscanf(fi, "%s %s", y, z);
	}
	fclose(fv);
	fclose(fo);
}

void opt() {
	FILE* fv, * fs;
	char z[50], y[10], x[20];
	fv = fopen("D:\\New folder\\input.txt", "r");
	fs = fopen("D:\\New folder\\optimized.txt", "w");

	while (!feof(fv)) {
		fscanf(fv, "%s", x);
		//printf("\nx= %s\n", x);
		fprintf(fs, "%s", x);
		int flag1 = strcmp(x, ";");
		int flag2 = strcmp(x, ")");
		if (flag1 == 0 || flag2 == 0) {
			fprintf(fs, "\n");
		}
		else
			fprintf(fs, " ");

	}
	fclose(fv);
	fclose(fs);
}


void main(){
	int flag;
	lex();
	flag = parser();
	//printf("flag = %d", flag);
	if (flag == 1)
	{
		printf("\nDid not generate\n");
	}
	else {
		intermedient();
		gen();
		tree();
		opt();
	}
	_getch();
}