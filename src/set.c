typedef void* space;

enum types {
	CHAR,

};

typedef struct {
	void* universe;
	char* types;
	char* mask;
	int size;
} set;

void space_add (space S, void* pointer, char* type) {
	int size = 0;

	if !(strcmp (type, "char"))
		size = sizeof(char);
	else if (strcmp (type, "short"))
		size = sizeof(short);
	else if (strcmp (type, "unsigned short"))
		size = sizeof(unsigned short);
	else if (strcmp (type, "int"))
		size = sizeof(int);
	else if (strcmp (type, "unsigned int"))
		size = sizeof(unsigned int);
	else if (strcmp (type, "long"))
		size = sizeof(long);
	else if (strcmp (type, "unsigned long"))
		size = sizeof(unsigned long);
	else if (strcmp (type, "long long"))
		size = sizeof(long long);
	else if(strcmp (type, "unsigned long long"))
		size = sizeof(unsigned long long);
	else if(strcmp (type, "float"))
		size = sizeof(float);
	else if(strcmp (type, "double"))
		size = sizeof(double);
	else if(strcmp (type, "long double"))
		size = sizeof(long double);

	S.universe = realloc (S.universe, sizeof(S.universe) + sizeof(void*));
	S.universe[S.size] = pointer;
	S.types = realloc (S.types, sizeof(S.types) + sizeof(char*));
	S.types[S.size] = type;
}

void space_from_array (space S, ) {

}

int main () {
	space S;

}
